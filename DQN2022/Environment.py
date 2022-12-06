#from Communication_unity import Communicator
from Communication import Communicator
import numpy as np
import random as rd
import time
from collections import deque
import threading

RIGHT_WING = 1
LEFT_WING = 2
PWM_WING = 209
default_params = [255, PWM_WING, PWM_WING, 45, 0, 0]

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
    def __init__(self, keep_frames):
        self.communicator = Communicator()
        self.thread1 = threading.Thread(target=self.communicator.receive_from_esp)
        self.thread1.start()
        #self.reset()
        self.params_to_send = default_params
        self.state = deque()
        self.keep_frames = keep_frames
        self.target_angle = 0

    def set_cut_off(self, cut_off):
        self.params_to_send[5] = cut_off
    
    def stop_com(self):
        self.thread1.join()

    def update(self, data):
        """
        状態を更新する
        Args:
            data ([list]): 新しく保存する状態
        """
        self.state.appendleft(data) 

    def reset_pid(self, p_gain=None, i_=None, yaw_index=2):
        """
        4フレーム分の状態を格納するdequeを作成
        最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得
        """
        self.communicator.start_esp(default_params)
        self.state = deque(maxlen = self.keep_frames)

        for i in range(self.keep_frames):
            _,_,_,_ = self.observe_update_state_pid(p_gain=p_gain, i_=i_, yaw_index=yaw_index)

    def observe_update_state_pid(self, p_gain=None, i_=None, yaw_index=2):
        data = [int(self.communicator.state[-1][0]),int(self.communicator.state[-1][1]),int(self.communicator.state[-1][yaw_index])-self.target_angle]
        ti = self.communicator.state[-1][3]
        ti_ = self.communicator.state[-1][4]
        dyaw = self.communicator.state[-1][6]

        if p_gain != None:
            data.append(p_gain)
        if i_ != None:
            data.append(i_)
        self.update(data)
        return self.state, ti, ti_, dyaw          #更新されたstateデック、受信した時間、前回受信との間隔を返す

    def observe_state(self):
        """
        状態を確認する
        """
        return self.state
    
    def update_target(self, angle):
        self.target_angle = angle

    def observe_reward(self, data, yaw_index=2):
        """
        報酬を定義する
        Args:
            data ([list]): 状態（1フレーム）
        Returns:
            [int]: 報酬
        """
        err = abs(float(data[0][yaw_index])-self.target_angle)
        return 1.0-err/90.0

    def excute_action(self, action):
        """
        行動内容を定義する
        行動内容に沿って機体に通信を送る
        Args:
            action ([int]): 行動の番号
        """
        if (int)(action) == 0:
            self.params_to_send[RIGHT_WING]=PWM_WING-100
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 1:
            self.params_to_send[RIGHT_WING]=PWM_WING-80
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 2:
            self.params_to_send[RIGHT_WING]=PWM_WING-60
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 3:
            self.params_to_send[RIGHT_WING]=PWM_WING-40
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 4:
            self.params_to_send[RIGHT_WING]=PWM_WING-30
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 5:
            self.params_to_send[RIGHT_WING]=PWM_WING-20
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 6:
            self.params_to_send[RIGHT_WING]=PWM_WING-10
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 7:
            self.params_to_send[RIGHT_WING]=PWM_WING-5
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 8:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING
        elif (int)(action) == 9:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-5
        elif (int)(action) == 10:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-10
        elif (int)(action) == 11:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-20
        elif (int)(action) == 12:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-30
        elif (int)(action) == 13:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-40
        elif (int)(action) == 14:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-60
        elif (int)(action) == 15:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-80
        elif (int)(action) == 16:
            self.params_to_send[RIGHT_WING]=PWM_WING
            self.params_to_send[LEFT_WING]=PWM_WING-100

        self.communicator.send_to_esp(self.params_to_send)
        #print(self.params_to_send)
        #time.sleep(0.01)

    def execute_action_(self, actions):
        """
        決定した行動に基づくモータ出力の変更を機体に反映（送信）
        """
        self.params_to_send[RIGHT_WING] = actions[0]
        self.params_to_send[LEFT_WING] = actions[1]
        #print("params_to_send:", end = "")
        #print(self.params_to_send)
        self.communicator.send_to_esp(self.params_to_send)
     
    def execute_action_gain(self, action):
        if action == 0:
            return 2
        elif action == 1:
            return 3.5
        elif action == 2:
            return 4
        elif action == 3:
            return 4.5
        elif action == 4:
            return 6
        elif action == 5:
            return 9
    
    def excute_action_inc(self, action, actions):
        if action == 0:
            self.params_to_send[RIGHT_WING]=actions[0]-10
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 1:
            self.params_to_send[RIGHT_WING]=actions[0]+10
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 2:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 3:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]-10
        elif action == 4:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]+10
        if(self.params_to_send[LEFT_WING]<50):
            self.params_to_send[LEFT_WING] = 100
        if(self.params_to_send[LEFT_WING]>230):
            self.params_to_send[LEFT_WING] = 230
        if(self.params_to_send[RIGHT_WING]<50):
            self.params_to_send[RIGHT_WING] = 50
        if(self.params_to_send[RIGHT_WING]>230):
            self.params_to_send[RIGHT_WING] = 230

        self.communicator.send_to_esp(self.params_to_send)
        return self.params_to_send[RIGHT_WING],self.params_to_send[LEFT_WING]
    
    def excute_action_pid(self, action, actions):
        if action == 0:
            self.params_to_send[RIGHT_WING]=actions[0]-30
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 1:
            self.params_to_send[RIGHT_WING]=actions[0]-20
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 2:
            self.params_to_send[RIGHT_WING]=actions[0]-10
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 3:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 4:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 5:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]
        elif action == 6:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]-10
        elif action == 7:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]-20
        elif action == 8:
            self.params_to_send[RIGHT_WING]=actions[0]
            self.params_to_send[LEFT_WING]=actions[1]-30

        self.communicator.send_to_esp(self.params_to_send)

    def state2action(self, actions):
        act = 0
        if actions[1] == PWM_WING:
            if actions[0] > PWM_WING-35:
                if actions[0] > PWM_WING-15:
                    if actions[0] > PWM_WING-8:
                        if actions[0] > PWM_WING-3:
                            act = 8
                        else:
                            act = 7
                    else:
                        act = 6
                else:
                    if actions[0] > PWM_WING-25:
                        act = 5
                    else: 
                        act = 4
            else:
                if actions[0] > PWM_WING-70:
                    if actions[0] > PWM_WING-50:
                        act = 3
                    else:
                        act = 2
                else:
                    if actions[0] > PWM_WING-90:
                        act = 1
                    else:
                        act = 0
        else:
            if actions[1] > PWM_WING-35:
                if actions[1] > PWM_WING-15:
                    if actions[1] > PWM_WING-8:
                        act = 9
                    else:
                        act = 10
                else:
                    if actions[1] > PWM_WING-25:
                        act = 11
                    else: 
                        act = 12
            else:
                if actions[1] > PWM_WING-70:
                    if actions[1] > PWM_WING-50:
                        act = 13
                    else:
                        act = 14
                else:
                    if actions[1] > PWM_WING-90:
                        act = 15
                    else:
                        act = 16
        return act