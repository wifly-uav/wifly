from send2unity import Communicator
import numpy as np
import random as rd
import time

default_params = [0,0]

class Environment():
    ##for initialize params_to_send to lazurite
    ##header,right,servo,left,controlmode

    def __init__(self):
        self.communicator = Communicator()
        #self.reset()
        self.params_to_send = default_params
        self.state = [0,0]
        self.communicator.com_start()

        self.reward_plt = []
        self.x_ax = []


    def reset(self):
        self.update()
        self.params_to_send = default_params
        #print(self.state)

    def update(self):
        self.state=self.communicator.perse_raw_data()

    def observe_update_state(self):
        self.communicator.recieve_from_unity(True)
        self.update()

    def observe_state(self):
        return self.state
        #print(self.state)

    def observe_terminal(self):
        # return True when the number of frames > N_FRAMES_EPOCH or when termination button is pushed
        return self.communicator.termination_switch()

    def excute_action(self, action):
        self.params_to_send=action
        self.communicator.send_to_unity(self.params_to_send)
        #time.sleep(0.1)

    def get_sentparam(self):
        return self.params_to_send


    def stop_sim(self):
        self.communicator.send_to_unity([0,1])