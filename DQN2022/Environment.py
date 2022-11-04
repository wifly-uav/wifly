#from Communication_unity import Communicator
from Communication import Communicator
import numpy as np
import random as rd
import time
from collections import deque
import threading

YAW_INDEX = 2
FRAMES = 4      #維持フレーム数

"""
#もとの設定
RIGHT_WING = 1  #params_to_sendやdefault_params内での添え字
LEFT_WING = 3   #params_to_sendやdefault_params内での添え字
PWM_WING = 0    #はばたき初期値

default_params = [255, PWM_WING, 0, PWM_WING, 0]    #ここを変更しないといけない気がする。
                ##header,right,servo,left,controlmode
"""


#変更後
RIGHT_WING = 1
LEFT_WING = 2
PWM_WING = 209
default_params = [255, PWM_WING, PWM_WING, 45, 0, 0]

"""
#変更提案(2022/08/09/22:47)→没!(2022/08/20/18:24)
#現在のESPの通信にはヘッダがない。
RIGHT_WING = 0
LEFT_WING = 1
PWM_WING = 0
default_params = [PWM_WING, PWM_WING, 0, 0, 0]  #[羽ばたき1, 羽ばたき2, tail_servo, cog, 0]
"""
receive_byt = 8

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

    def reset_pid_2(self, add = 0):
        """
        4フレーム分の状態を格納するdequeを作成
        最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得
        """
        self.communicator.start_esp(default_params)
        self.state = deque(maxlen = self.keep_frames)         #状態格納用deque
        self.params_to_send = default_params                  #2行下に同じ文がある。

        #NNの入力に必要なFRAMES個の状態をLazuriteから取得する。
        for i in range(self.keep_frames):
            self.params_to_send = default_params    #送信用データを格納（未使用?）
            data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
            data.append(add)    #受信データにPgainを付け加える（data=Falseの場合RE?)
            #data:[モータ出力1,モータ出力2,サーボ1,サーボ2,Pitch,Yaw,Pgain]
            self.update_2(data)

    def reset_pid_3(self, add=0, add2=0):
        """
        4フレーム分の状態を格納するdequeを作成
        最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得
        """
        self.communicator.start_esp(default_params)
        self.state = deque(maxlen = self.keep_frames)         #状態格納用deque
        self.params_to_send = default_params                  #2行下に同じ文がある。

        #NNの入力に必要なFRAMES個の状態をLazuriteから取得する。
        for i in range(self.keep_frames):
            self.params_to_send = default_params    #送信用データを格納（未使用?）
            data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
            data.append(add)    #受信データにPgainを付け加える（data=Falseの場合RE?)
            data.append(add2)
            #data:[モータ出力1,モータ出力2,サーボ1,サーボ2,Pitch,Yaw,Pgain]
            self.update_2(data)

    def reset_nopid(self):
        """
        4フレーム分の状態を格納するdequeを作成
        最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得
        """
        self.communicator.start_esp(default_params)
        self.state = deque(maxlen = self.keep_frames)         #状態格納用deque
        self.params_to_send = default_params                  #2行下に同じ文がある。
        for i in range(self.keep_frames):
            data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
            self.update_2(data)

    def update_2(self, data):
        """
        状態を更新する
        Args:
            data ([list]): 新しく保存する状態
        """
        #新しい状態を先頭に加える（stateは新しい順に格納されている）
        #self.stateにはmaxlenを設定しているので、格納しきれない古い状態は自動的に削除される。
        self.state.appendleft(data) 

    def observe_update_state_pid_2(self, flag=True, pid=0):

        #ESPからデータを受信
        #正常に受信できれば、受信データ、受信した時間、前回受信との間隔が返ってくる
        #正常に受信できなかった場合、False,0,0が返ってくる

        data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
        ti = self.communicator.state[-1][3]
        ti_ = self.communicator.state[-1][4]

        data.append(pid)                    #受信データにPgainを付け加える（pid=0は引数が指定されなかった場合の値なので注意）
        self.update_2(data)
        return self.state, ti, ti_          #更新されたstateデック、受信した時間、前回受信との間隔を返す

    def observe_update_state_pid_3(self, flag=True, p=0, i=0):

        #ESPからデータを受信
        #正常に受信できれば、受信データ、受信した時間、前回受信との間隔が返ってくる
        #正常に受信できなかった場合、False,0,0が返ってくる

        data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
        ti = self.communicator.state[-1][3]
        ti_ = self.communicator.state[-1][4]

        data.append(p)
        data.append(i)
        self.update_2(data)
        return self.state, ti, ti_          #更新されたstateデック、受信した時間、前回受信との間隔を返す

    def observe_update_state_nopid(self, flag=True):
        data = [self.communicator.state[-1][0],self.communicator.state[-1][1],self.communicator.state[-1][2]]
        ti = self.communicator.state[-1][3]
        ti_ = self.communicator.state[-1][4]
        self.update_2(data)
        return self.state, ti, ti_          #更新されたstateデック、受信した時間、前回受信との間隔を返す    

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
        #報酬の設定
        #Yaw角の0.0度からのずれに基づいて報酬を与える
        #報酬はクリッピングしてある。
        err = abs(float(data[0][YAW_INDEX])-0.0)
        return 1.0-err/90.0

    #未使用
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
        #各送信時にparams_to_sendを書き換えて送信していく。
        #
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