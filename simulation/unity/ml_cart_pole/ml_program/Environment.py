from send2unity import Communicator
import numpy as np
import random as rd
import time
from collections import deque
import copy
import csv

N_FRAMES_EPOCH = 5000
TARGET_VALUE_TO_CONTROL = 2
default_params = [0, 0, 0]
#0:force
#4:reset

class Environment():
    ##for initialize params_to_send to lazurite
    ##header,right,servo,left,controlmode

    def __init__(self):
        #self.reset()
        self.params_to_send = default_params
        self.state = deque()
        self.frame = 0

        self.reward_plt = []
        self.x_ax = []


    def reset(self, data):
        ##学習開始時のバッファ用
        self.params_to_send = default_params
        self.update(flag_init=True, data=data)
        #print(self.state)

    def update(self, flag_init, data):
        if flag_init is False:
            self.state.pop()
        self.state.appendleft(data)

    def observe_update_state(self, data):
        self.update(flag_init=False, data=data)

    def observe_state(self):
        st = self.state
        #print('observe' + str(st))
        return st

    def observe_reward(self, data_le, data_arg_n, data_arg, data_time):
        ##報酬の設定
        ##45.0は姿勢の目標角度
        ##err = abs(self.communicator.perse_raw_data()[0] - 45.0)
        le = abs(data_le)
        arg_n = abs(data_arg_n)
        arg = abs(data_arg)
        #print("err" + str(err))
        #print("arg" + str(arg))
        #print("hei" + str(hei))]
        #print((arg-arg_n)/self.communicator.get_time()[0])
        #reward = 0.2*(arg-arg_n) + 0.7*(0-arg_n) + 0.1*(2.0-le)
        reward = 0.8*(0-arg_n) + 0.2*(2.0-le)
        self.reward_plt.append(reward)
        #if arg_n < 45:
            #reward = (arg-arg_n)/data_time
            #reward = 0.2*(arg-arg_n) + 0.8*(5-arg_n)
        #else:
            #reward = -100
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
        #self.rec_reward = (90-arg_n)/90*self.communicator.get_time()[0]
        #self.reward_plt.append(reward)
        #self.x_ax.append(len(self.reward_plt))
        #print(reward)
        return reward

    def observe_terminal(self, com_terminal):
        # return True when the number of frames > N_FRAMES_EPOCH or when termination button is pushed
        if self.frame > N_FRAMES_EPOCH:
            return True
        else:
            return com_terminal

    def excute_action(self, action):
        self.params_to_send = copy.copy(default_params)
        if action == 1:
            self.params_to_send[0]=30
        elif action == 2:
            self.params_to_send[0]=15.0
        elif action == 3:
            self.params_to_send[0]=-15.0
        elif action == 4:
            self.params_to_send[0]=-30.0
        
        return self.params_to_send

        #time.sleep(0.1)

    def get_sentparam(self):
        return self.params_to_send

    '''
    def reset_sim(self):
        self.communicator.send_to_unity([0, 1, 0])

    def stop_sim(self):
        self.communicator.send_to_unity([0, 0, 1])
    '''

    def log_reward(self):
        with open('debug/reward' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.rec_reward)