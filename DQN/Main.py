#from Calc_Control import Calc_Control
import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import sys
from visualize_nn import visual_nn

N_EPOCHS = 7
N_FRAMES = 500
MODEL_NAME_HEADER = "WiflyDual_DQN"

if __name__ == "__main__":    
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

    
    print('Use saved model? y/n')
    ans_yn = input()
    if (ans_yn == 'y'):
        print('save folder name:')
        save_folder = input()
        save_file_ = save_file
        save_file = os.path.join(path, 'result/test',save_folder)
        if not os.path.exists(save_file):
            os.makedirs(save_file)
        
        print('use folder name:')
        use_folder = input()

        agent = DQNAgent(folder=save_file)
        agent.load_model(model_path='../' + use_folder + '/' + MODEL_NAME_HEADER)
        print('Model load has been done')
    elif(ans_yn == 'n'):
        agent = DQNAgent(folder=save_file)
        print('Progam starts without loading a model')
    else:
        print("Type y or n . Quit the program")
        sys.exit()

    log = logger(folder=save_file)
    env = Environment()
    vi = visual_nn(folder=save_file)
    
    print("press y to start")

    try:
        for i in range(N_EPOCHS):
            #init
            frame = 0
            loss = 0.0
            Q_max = 0.0
            reward = 0
            terminal = True
            data = True
            env.reset()
            state_next = env.observe_state()

            for j in range(N_FRAMES):
                terminal = env.observe_terminal()
                state_current = state_next
                action = agent.select_action_limit(state_current)
                agent.epsilon -= 0.1/3000
                env.excute_action(action)
                if i != 0:
                    agent.experience_replay()
                state_next, ti, ti_ = env.observe_update_state()
                #action, data = env.reaction(state_next)
                if data == True:
                    reward = env.observe_reward(state_next)
                    terminal = env.observe_terminal()
                    agent.store_experience(state_current, action, reward, state_next, terminal)
                    print(i,j,state_next[0], reward)
                    # for loging
                    log.add_log_state_and_action(state_next, action, env.params_to_send, ti, ti_)
                    log.add_log_state(state_next, reward, ti)
                else:
                    print("reset")
                    #print(state_next)
                    #env.reset()

            agent.create_checkpoint()
            #checkpoint_report = "EPOCH: {:03d}/{:03d} | REWARD: {:03f} | LOSS: {:.4f} | Q_MAX: {:.4f}".format(i, N_EPOCHS - 1, reward, loss, Q_max)
            #print(checkpoint_report)
            #log.add_log([checkpoint_report])
            #log.add_log(["Epoch End"])

    except:
    #except KeyboardInterrupt:
        print("Key finish")
        print(state_next)


    agent.save_model()
    agent.debug_nn()
    agent.debug_memory()
    agent.debug_minibatch()
    agent.debug_q()
    agent.debug_loss()
    log.output_log()
    
    loss = agent.check_loss()
    log.loss_graph(loss)
    log.angle_graph()

    vi.visualize()

    print("finish")