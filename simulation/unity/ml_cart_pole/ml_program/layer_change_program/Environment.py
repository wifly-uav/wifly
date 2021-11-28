from send2unity import Communicator
import numpy as np
import random as rd
import time
from collections import deque

N_FRAMES_EPOCH = 500
TARGET_VALUE_TO_CONTROL = 2
default_params = [0, 0, 0]
#0:force
#4:reset

class Environment():
    ##for initialize params_to_send to lazurite
    ##header,right,servo,left,controlmode

    def __init__(self, TEST_MODE):
        self.communicator = Communicator()
        #self.reset()
        self.params_to_send = default_params
        self.state = deque()
        self.communicator.com_start()

        self.reward_plt = []
        self.x_ax = []


    def reset(self):
        self.state = deque()
        self.params_to_send = default_params
        ##学習開始時のバッファ用
        for i in range(2):
            self.params_to_send = default_params
            self.communicator.recieve_from_unity(False)
            self.update(flag_init=True)
        #print(self.state)

    def update(self, flag_init):
        if flag_init is False:
            self.state.pop()
        self.state.appendleft(self.communicator.perse_raw_data())

    def observe_update_state(self):
        self.communicator.recieve_from_unity(True)
        self.update(flag_init=False)

    def observe_state(self):
        return self.state
        #print(self.state)

    def observe_reward(self):
        ##報酬の設定
        ##45.0は姿勢の目標角度
        ##err = abs(self.communicator.perse_raw_data()[0] - 45.0)
        le = abs(self.communicator.perse_raw_data()[0])
        arg_n = abs(self.communicator.perse_raw_data()[1])
        arg = abs(self.communicator.old_data[1])
        #print("err" + str(err))
        #print("arg" + str(arg))
        #print("hei" + str(hei))]
        #print((arg-arg_n)/self.communicator.get_time()[0])
        if arg_n < 60:
            reward = (arg-arg_n)/self.communicator.get_time()[0]
        else:
            reward = -1000
        '''
        if arg<10:
            reward = 1
        elif arg<45:
            reward = 0
        else:
            reward = -1
        if le > 17:
            reward = -2
        '''
        #print(self.communicator.get_time()[0])
        self.rec_reward = (90-arg_n)/90*self.communicator.get_time()[0]
        #self.reward_plt.append(reward)
        #self.x_ax.append(len(self.reward_plt))
        return reward

    def observe_terminal(self, n_frames):
        # return True when the number of frames > N_FRAMES_EPOCH or when termination button is pushed
        if n_frames > N_FRAMES_EPOCH:
            return True
        else:
            return self.communicator.termination_switch()

    def excute_action(self, action):
        if action == 1:
            self.params_to_send[0]=-10.0
        elif action == 2:
            self.params_to_send[0]=-5.0
        elif action == 3:
            self.params_to_send[0]=5.0
        elif action == 4:
            self.params_to_send[0]=10.0

        self.communicator.send_to_unity(self.params_to_send)
        #time.sleep(0.1)

    def get_sentparam(self):
        return self.params_to_send

    def reset_sim(self):
        self.communicator.send_to_unity([0, 1, 0])

    def stop_sim(self):
        self.communicator.send_to_unity([0, 0, 1])