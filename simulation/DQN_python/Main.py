#from Calc_Control import Calc_Control
import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import sys

N_EPOCHS = 200
N_FRAMES = 100
MODEL_NAME_HEADER = "WiflyDual_DQN"

if __name__ == "__main__":
    log = logger()
    agent = DQNAgent()
    env = Environment()
    """
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
        sys.exit()
    """
        
    print("start")

    try:
        for i in range(N_EPOCHS):
            #init
            frame = 0
            loss = 0.0
            Q_max = 0.0
            reward_sum = 0.0
            reward = 0
            terminal = True
            env.reset()
            state_next = env.observe_state()

            for j in range(N_FRAMES):
                state_current = state_next
                action = agent.select_action(state_current)
                env.excute_action(action)
                state_next, ti = env.observe_update_state()
                reward = env.observe_reward(state_next)
                terminal = env.observe_terminal()
                agent.store_experience(state_current, action, reward, state_next, terminal)
                agent.experience_replay()
                print(i,j,state_next[0],action, terminal, reward)
                # for lioging
                reward_sum += reward
                loss += agent.current_loss
                log.add_log_state_and_action(state_next, env.get_sentparam(), ti)
                if terminal == True:
                    break

            agent.create_checkpoint()
            checkpoint_report = "EPOCH: {:03d}/{:03d} | REWARD: {:03f} | LOSS: {:.4f}".format(i, N_EPOCHS - 1, reward_sum, loss)
            print(checkpoint_report)
            log.add_log([checkpoint_report])
            log.add_log(["Epoch End"])

    except KeyboardInterrupt:
        print("Key finish")


    env.stop_sim()
    agent.debug_nn()
    agent.debug_memory()
    agent.debug_minibatch()
    agent.debug_q()
    agent.debug_loss()

    agent.save_model()
    log.output_log()
    print("finish")