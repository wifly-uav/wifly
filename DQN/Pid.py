#from Calc_Control import Calc_Control
from matplotlib.pyplot import flag
import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import sys
from Calc_Control import calc_PID

N_EPOCHS = 5*500
N_FRAMES = 500
MODEL_NAME_HEADER = "WiflyDual_DQN"

if __name__ == "__main__":
    log = logger()
    saturations = [0,100]
    pwm_def = 100
    pid = calc_PID(saturations)
    param = [1.5,0.0001,0,0]
    ti = 10
    actions = [pwm_def, pwm_def]
    pid.update_params(param)
    #agent = DQNAgent()
    env = Environment()
        
    print("start")
    terminal = env.observe_terminal()
    state_next, ti, ti_ = env.observe_update_state(flag=False)
    try:
        for i in range(N_EPOCHS):
            #init
            #env.reset()

            state_current = state_next
            diff = pid.calculate_output(current_value=(int)(state_current[0][0]), delta_time= (int)(ti), mode=True)
            if diff > 0:
                actions[0] = pwm_def
                actions[1] = pwm_def + diff
            else:
                actions[0] = pwm_def - diff
                actions[1] = pwm_def
            env.execute_action_(actions)
            state_next, ti, ti_ = env.observe_update_state()
            #reward = env.observe_reward(state_next)
            print(i, state_next[0], env.params_to_send)

            # for loging
            #log.add_log_state_and_action(state_next, actions[0], env.params_to_send, actions[1], ti)
            reward = 0
            log.add_log_state(state_next, reward, ti)
            #print(state_next)
            #env.reset()
    except:
        pass



    #agent.save_model()
    log.output_log(flag=False)

    print("finish")