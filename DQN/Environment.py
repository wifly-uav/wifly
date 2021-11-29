from Communication import Communicator
import numpy as np
import random as rd
import time
from collections import deque

RIGHT_WING = 1
LEFT_WING = 3
PWM_WING = 140
FRAMES = 4
default_params = [255, PWM_WING, 0, PWM_WING, 0]
                ##header,right,servo,left,controlmode
receive_byt = 7

#0:header(255固定)
#1:right wing(0~255)
#2:servo: elevator
#3:left wing(0~255)
#4:control mode(1:manual, 0:auto)

class Environment():
    """
    強化学習をする際の環境を設定するクラス
    状態取得、報酬決定、行動内容の決定をしている
    """
    def __init__(self):
        self.communicator = Communicator()
        self.reset()
        self.params_to_send = default_params
        self.state = deque()

    def reset(self):
        """
        状態を格納するデックを作る
        最初に足りない分のフレームの状態を保存する
        """
        self.communicator.start_laz(default_params)
        self.state = deque()
        self.params_to_send = default_params
        for i in range(FRAMES):
            self.params_to_send = default_params
            data, _, _ = self.communicator.recieve_from_laz(byt=receive_byt)
            self.update(flag=False, data=data)

    def reset_pid(self, add=0):
        self.communicator.start_laz(default_params)
        self.state = deque()
        self.params_to_send = default_params
        for i in range(FRAMES):
            self.params_to_send = default_params
            data, _, _ = self.communicator.recieve_from_laz(byt=receive_byt)
            data.append(add)
            self.update(flag=False, data=data)

    def update(self, flag, data):
        """
        状態を更新する
        Args:
            flag ([bool]): True:一番古い状態を消す
            data ([list]): 新しく保存する状態
        """
        if flag:
            self.state.pop()
        self.state.appendleft(data)

    def observe_update_state(self, flag=True):
        """
        状態を更新した上で状態を確認する
        """
        data, ti, ti_ = self.communicator.recieve_from_laz(byt=receive_byt)
        self.update(flag=flag, data=data)
        return self.state, ti, ti_
    
    
    def observe_update_state_pid(self, flag=True, pid=0):
        data, ti, ti_ = self.communicator.recieve_from_laz(byt=receive_byt)
        data.append(pid)
        self.update(flag=flag, data=data)
        return self.state, ti, ti_

    def observe_state(self):
        """
        状態を確認する
        """
        return self.state

    def observe_reward(self, data):
        """
        報酬を定義する
        Args:
            data ([list]): 状態（1フレーム）
        Returns:
            [int]: 報酬
        """
        ##報酬の設定
        err = abs(float(data[0][0])-0.0)
        if err < 10:
            return 1
        elif err < 30:
            return 0
        elif err <45:
            return -1
        else:
            return -10

    def observe_terminal(self):
        """
        ターミナルスイッチの情報を読み取る
        Returns:
            bool: ターミナルスイッチ
        """
        return self.communicator.termination_switch(default_params)

    def excute_action(self, action):
        """
        行動内容を定義する
        行動内容に沿って機体に通信を送る
        Args:
            action ([int]): 行動の番号
        """
        if action == 1:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 2:
            self.params_to_send[RIGHT_WING]=PWM_WING+20
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 3:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING+20
        elif action == 4:
            self.params_to_send[RIGHT_WING]=PWM_WING+40
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 5:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING+40
        elif action == 6:
            self.params_to_send[RIGHT_WING]=PWM_WING+60
            self.params_to_send[LEFT_WING]=PWM_WING
        else:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING+60

        self.communicator.send_to_laz(self.params_to_send)
        #time.sleep(0.01)

    def execute_action_(self, actions):

        self.params_to_send[RIGHT_WING]=actions[0]
        self.params_to_send[LEFT_WING]=actions[1]
    
        self.communicator.send_to_laz(self.params_to_send)
    
    
    def execute_action_gain(self, action):

        if action == 1:
            return 1.5
        elif action == 2:
            return 1.75
        elif action == 3:
            return 2
        elif action == 4:
            return 1.25
        else:
            return 1
    
    
    def excute_action_pid(self, action, actions):
        if action == 1:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 2:
            self.params_to_send[RIGHT_WING]=actions[0]+10
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 3:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]+10
        elif action == 4:
            self.params_to_send[RIGHT_WING]=actions[0]+20
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 5:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]+20
        elif action == 6:
            self.params_to_send[RIGHT_WING]=actions[0]+30
            self.params_to_send[LEFT_WING]=actions[1]
        else:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]+30

        self.communicator.send_to_laz(self.params_to_send)

    def reaction(self, state):
        flag = True
        state_list = list(state)
        if state_list[0][2] == str(PWM_WING+30):
            action = 2
        elif state_list[0][2] == str(PWM_WING+60):
            action = 4
        elif state_list[0][1] == str(PWM_WING+30):
            action = 3
        elif state_list[0][1] == str(PWM_WING+60):
            action = 5
        elif state_list[0][1] == state_list[0][2]:
            action = 1
        else:
            action = 0
            flag = False
        return action, flag

    def get_sentparam(self):
        """
        機体に送った情報を確認する
        Returns:
            [list]: 送った情報
        """
        return self.params_to_send