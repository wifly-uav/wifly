#from Calc_Control import Calc_Control
import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import matplotlib.pyplot as plt
import time

N_EPOCHS = 300
TEST_MODE = False
MODEL_NAME_HEADER = "WiflyDual_DQN"
rec_reward = []
x_ax = []

if __name__ == "__main__":
    log = logger()
    agent = DQNAgent()
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
    env = Environment(TEST_MODE)

    for i in range(N_EPOCHS):
        #init
        frame = 0
        loss = 0.0
        Q_max = 0.0
        reward = 0
        terminal = False
        env.reset()
        state_next = env.observe_state()
        
        rec_re = 0.0


        while not terminal:
            t1 = time.time()
            state_current = state_next
            action = agent.select_action(state_current)
            env.excute_action(action)
            t3 = time.time()
            env.observe_update_state()
            state_next = env.observe_state()
            terminal = env.observe_terminal(frame)
            t4 = time.time()
            reward = env.observe_reward()

            rec_re = rec_re + env.rec_reward

            agent.store_experience(state_current, action, reward, state_next, terminal)
            agent.experience_replay()
            #print(env.communicator.perse_raw_data())
            #print(action, terminal, reward)
            # for loging
            frame += 1
            loss += agent.current_loss
            Q_max += np.max(agent.Q_values(state_current))
            log.add_log_state_and_action(state_current[1], env.get_sentparam())
            t2 = time.time()
            #print("all_time:" + str(t2-t1))
            #print("state_time:" + str(t4-t3))
        
        #agent.epsilon = agent.epsilon - 0.2/N_EPOCHS
        rec_reward.append(rec_re)
        x_ax.append(len(rec_reward))
        if i == N_EPOCHS-1:
            env.stop_sim()
        else:
            env.reset_sim()
        print(str(i) + "epoch end")
        log.add_log(["Epoch End"])

        if(i % 30 == 0):
            agent.create_checkpoint()
            checkpoint_report = "EPOCH: {:03d}/{:03d} | REWARD: {:03f} | LOSS: {:.4f} | Q_MAX: {:.4f}".format(i, N_EPOCHS - 1, reward, loss, Q_max)
            #print(checkpoint_report)
            log.add_log([checkpoint_report])

    agent.debug_nn()
    agent.save_model()
    log.output_log()
    #plt.plot(agent.x_ax,agent.loss_plt)
    #plt.show()
    plt.plot(x_ax,rec_reward)
    plt.show()
