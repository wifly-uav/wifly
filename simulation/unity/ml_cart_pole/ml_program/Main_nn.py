#from Calc_Control import Calc_Control
import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import matplotlib.pyplot as plt
import time
from send2unity import Communicator
import socket
import copy


from restore_nn import NN



N_EPOCHS = 500
MODEL_NAME_HEADER = "DQN"

N_AGENT = 5

if __name__ == "__main__":


    nn = NN()
    #nn.load_model('nn/state_nn')

    log = logger()
    agent = DQNAgent()
    communicator = Communicator()


    env = [0] * N_AGENT
    state_current = [0] * N_AGENT
    state_old = [0] * N_AGENT
    terminal = [0] * N_AGENT
    action = [0] * N_AGENT
    action_old = [0] * N_AGENT
    action = [0] * N_AGENT

    '''
    print('Use saved model? y/n')
    ans_yn = input()
    if (ans_yn == 'y'):
        print('Type model no.')
        agent.load_model(model_path=MODEL_NAME_HEADER + input())
        print('Model load has been done')
    elif(ans_yn == 'n'):
        print('Progam starts without loading a model')
    else:
        print("Type y or n . Quit the program")
    '''

    communicator.com_start()

    i = 0

    while i < N_EPOCHS:
        #print("loop: " + str(i))
        #操作するagentのヘッダーを取得する(受信)
        communicator.recieve_from_unity()
        hedder = communicator.get_hedder()
        #print("hedder: " +str(hedder))
        #print(hedder)
        #取得したヘッダー用の環境がなければ作成する
        if env[hedder] == 0:
            env[hedder] = Environment()
            #print("make_class: " + str(hedder))

        #1,2回目はバッファ用にデータを格納する必要があるため分離(default信号を送信する)
        if env[hedder].frame == 0:
            #print("env[" + str(hedder) + "] : " + str(env[hedder].frame) + "reset_1st")
            communicator.send_to_unity([0,0,0])
            env[hedder].reset(communicator.perse_raw_data())
            state_old[hedder] = env[hedder].observe_state()
            env[hedder].frame += 1
        elif env[hedder].frame == 1:
            #print("env[" + str(hedder) + "] : " + str(env[hedder].frame) + "reset_2nd")
            #communicator.send_to_unity([0,0,0])
            env[hedder].reset(communicator.perse_raw_data())
            state_old[hedder] = env[hedder].observe_state()
            
            #2回目は行動した結果が得られないため、replay_memoryへの保存はしない
            #行動選択
            act_ = nn.optimize_action(list(state_old[hedder]), 0.0, 0.0)
            act = env[hedder].excute_action(act_)
            action[hedder] = act[0]
            #print('act[hedder]' + str(act[hedder]))
            #行動の実行(送信)
            communicator.send_to_unity(act)

            env[hedder].frame += 1
        else:
            #状態の更新(受信しない)
            #print("hedder: " + str(hedder))

            #なぜか参照渡しされるため、copyで回避
            st = env[hedder].observe_state()
            #st = env[hedder].state.copy()
            #print('st' + str(st))
            state_old[hedder] = st

            env[hedder].update(False, communicator.perse_raw_data())
            state_current[hedder] = env[hedder].observe_state()
            #print('state_current' + str(state_current[hedder]))

            
            terminal[hedder] = env[hedder].observe_terminal(communicator.termination_switch())
            #状態が終了条件を満たしたらクラスをリセット(送信)
            if terminal[hedder] is True:
                i += 1 
                print(str(i) + "epoch end")
                if i == N_EPOCHS:
                    #env.stop_sim()
                    communicator.send_to_unity([0, 0, 1])
                else:
                    #env.reset_sim()
                    communicator.send_to_unity([0, 1, 0])
            else:
                #行動の記録
                action_old[hedder] = action[hedder]

                #print("state_old____" + str(hedder) + ": " + str(state_old[hedder]))
                #行動選択
                act_ = nn.optimize_action(list(state_old[hedder]), 0.0, 0.0)
                act = env[hedder].excute_action(act_)
                #print('hedder: ' + str(hedder) + " / " +'act: ' + str(act))
                action[hedder] = act[0]
                act[1] = 0
                act[2] = 0
                #print('act[hedder]' + str(act[hedder]))
                #行動の実行(送信)
                #print('act' + str(act))
                communicator.send_to_unity(act)
                env[hedder].frame += 1
            #ここまででagentとのやり取りは終了

                #ここから学習準備
                if env[hedder] != 3:
                    #reward = env[hedder].observe_reward(communicator.perse_raw_data()[0],communicator.perse_raw_data()[1],communicator.old_data[1],communicator.get_time()[0])
                    nn.store_memory(list(state_old[hedder]), action_old[hedder], list(state_current[hedder]), action[hedder])
                    #学習
                    nn.experience_replay(nn.get_memory(),8)
            
            
            if terminal[hedder] is True:
                #del env[hedder]
                #print("delete class: " + str(hedder))
                #del するとenv[hedder]そのものが無くなる
                env[hedder] = 0
        
        #print("env[" + str(hedder) + "] : " + str(env[hedder].frame))
        #agent.epsilon = agent.epsilon - 0.2/N_EPOCHS
        #rec_reward.append(rec_re)
        #x_ax.append(len(rec_reward))
        #log.add_log(["Epoch End"])

    nn.save_model()
    nn.debug_nn()
    nn.debug_loss()
    #nn.debug_loss_total()


'''
    agent.debug_nn()
    agent.debug_memory()
    agent.debug_q()
    agent.debug_loss()
    agent.debug_aim()
'''
'''
    agent.debug_minibatch()
    agent.save_model()
    log.output_log()
'''
    #plt.plot(agent.x_ax,agent.loss_plt)
    #plt.show()
    #plt.plot(x_ax,rec_reward)
    #plt.show()
