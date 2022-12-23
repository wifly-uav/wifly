#from Calc_Control import Calc_Control
import numpy as np
import tensorflow as tf
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import sys
from visualize_nn import visual_nn
import os
import time

N_EPOCHS = 10
N_FRAMES = 200
MODEL_NAME_HEADER = "WiflyDual_DQN"

if __name__ == "__main__":    
    tf.compat.v1.disable_eager_execution()     #tf1を無効(tf2の場合、エラーが出るので推奨)
    path = os.path.dirname(__file__)
    print('save folder name:')
    save_folder = input()
    save_file = os.path.join(path, 'result', save_folder)
    print(save_file)

    if not os.path.exists(save_file):
        # ディレクトリが存在しない場合、ディレクトリを作成する
        os.makedirs(save_file)
    else:
        print('The folder exists.')
        print('override? y/n')
        override = input()
        if (override == 'y'):
            pass
        else:
            print('Quit')
            sys.exit()
    
    agent = DQNAgent(folder=save_file)
    
    print('Use saved model? y/n')
    ans_yn = input()
    if (ans_yn == 'y'):        
        print('use model folder name:')
        use_folder = input()

        load_flag = agent.load_model(model_path= use_folder)
        if load_flag:
            print('Model load has been done')
            print('training? y/n')
            ans = input()
            if (ans == 'y'):
                training_flag = True
                print('training')
            else:
                training_flag = False
                print('test')
        else:
            print('No model data')
            sys.exit()

    else:
        print('Program starts without loading a model')
        training_flag = True

    log = logger(folder=save_file)
    env = Environment()
    vi = visual_nn(folder=save_file)
    
    #print("press y to start")

    #try:
    for i in range(N_EPOCHS):
        #init
        #frame = 0
        loss = 0.0
        Q_max = 0.0
        reward = 0
        terminal = True
        data = True
        env.reset(i=i)
        state_next = env.observe_state()
        action = 0
        #print("i"+str(i))
        a = time.time()

        for j in range(N_FRAMES):
            #print("loop_time:" + str(time.time()-a))
            a = time.time()
            state_current = state_next
            #action = agent.select_action_limit(state_current)    //agent.learnで経験再生してる
            if terminal == True:
                action = agent.choose_action(state_current)
                if training_flag:
                    agent.epsilon -= 0.1 / 2000
                else:
                    agent.epsilon = 0
                env.excute_action(action)
            if (j != 0 and training_flag == True):
                #agent.experience_replay()
                agent.learn()
            if terminal == True:
                state_next, ti, ti_ = env.observe_update_state()
            #action, data = env.reaction(state_next)
            reward = env.observe_reward(state_next)
            #terminal = env.observe_terminal()
            terminal = True     #terminalをTrueに固定
            print(i,j,action,state_next[0], reward, terminal)
            #agent.store_experience(state_current, action, reward, state_next, terminal)
            '''
            print("state_current:"+str(state_current))
            print("action:"+str(action))
            print("reward:"+str(reward))
            print("state_next:"+str(state_next))
            print("terminal:"+str(terminal))
            '''
            agent.store_transition(state_current, action, reward, state_next, terminal)
            # for loging
            log.add_log_state_and_action(state_next, action, env.params_to_send, ti, ti_)
            log.add_log_state(state_next, reward, ti)
            if terminal == False:
                print("reset")
                break
                #print(state_next)
                #env.reset()

        #agent.create_checkpoint()
    #except:
    #except KeyboardInterrupt:
        #print("Key finish")
        #print(state_next)


    #agent.save_model()
    agent.debug_nn()
    '''
    agent.debug_memory()
    agent.debug_minibatch()
    agent.debug_q()
    agent.debug_loss()
    '''
    log.output_log()
    
    loss = agent.check_loss()
    log.loss_graph(loss)
    log.angle_graph()

    vi.visualize()

    print("finish")