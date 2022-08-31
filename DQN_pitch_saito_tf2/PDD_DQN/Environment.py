#from Communication_unity import Communicator
from Communication import Communicator
import numpy as np
import random as rd
import time
from collections import deque

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
PWM_WING = 0
default_params = [255, PWM_WING, PWM_WING, 0, 0, 0]    


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
        #self.reset()
        self.params_to_send = default_params
        self.state = deque()
        self.keep_frames = keep_frames

    #未使用
    def reset(self, i=0):
        """
        状態を格納するデックを作る
        最初に足りない分のフレームの状態を保存する
        """
        if(i == 0):
            self.communicator.start_laz(default_params)
        self.state = deque()
        self.params_to_send = default_params
        for i in range(FRAMES):
            self.params_to_send = default_params
            data, _, _ = self.communicator.receive_from_esp(byt=receive_byt, mode=False)
            self.update(flag=False, data=data)
        #print("state:")
        #print(self.state)

    def reset_pid_2(self, add = 0):
        """
        4フレーム分の状態を格納するdequeを作成
        最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得
        """

        #ESPにデータを送り、通信の準備をさせる。
        #(ESPは何かしらのデータを受け取らないと送信モードにならない。)
        self.communicator.start_esp(default_params)

        self.state = deque(maxlen = self.keep_frames)         #状態格納用deque
        self.params_to_send = default_params                  #2行下に同じ文がある。

        #NNの入力に必要なFRAMES個の状態をLazuriteから取得する。
        for i in range(self.keep_frames):
            self.params_to_send = default_params    #送信用データを格納（未使用?）

            #Lazuriteからデータを受信
            #正常に受信できれば、受信データ、受信した時間、前回受信との間隔が返ってくる
            #正常に受信できなかった場合、False,0,0が返ってくる
            data, _, _ = self.communicator.receive_from_esp(byt = receive_byt)

            data.append(add)    #受信データにPgainを付け加える（data=Falseの場合RE?)
            #data:[モータ出力1,モータ出力2,サーボ1,サーボ2,Pitch,Yaw,Pgain]                                               
            #このdataが1つの状態である。

            #4つの状態を保持するdeque(self.state)に格納する。
            self.update_2(data)
            #self.update(flag=False, data=data)

    #未使用
    def update(self, flag, data):
        """
        状態を更新する
        Args:
            flag ([bool]): True:一番古い状態を消す
            data ([list]): 新しく保存する状態
        """
        if flag:
            self.state.pop()        #古い状態を削除
        self.state.appendleft(data) #新しい状態を先頭に加える（stateは新しい順に格納されている）

    def update_2(self, data):
        """
        状態を更新する
        Args:
            data ([list]): 新しく保存する状態
        """
        #新しい状態を先頭に加える（stateは新しい順に格納されている）
        #self.stateにはmaxlenを設定しているので、格納しきれない古い状態は自動的に削除される。
        self.state.appendleft(data) 

    #未使用
    def observe_update_state(self, flag=True):
        """
        状態を更新した上で状態を確認する
        """
        data, ti, ti_ = self.communicator.receive_from_laz(byt=receive_byt)
        self.update(flag=flag, data=data)
        return self.state, ti, ti_
    
    #未使用
    def observe_update_state_pid(self, flag=True, pid=0):

        #Lazuriteからデータを受信
        #正常に受信できれば、受信データ、受信した時間、前回受信との間隔が返ってくる
        #正常に受信できなかった場合、False,0,0が返ってくる
        data, ti, ti_ = self.communicator.receive_from_laz(byt=receive_byt)

        data.append(pid)                    #受信データにPgainを付け加える（pid=0は引数が指定されなかった場合の値なので注意）
        #self.update(flag=flag, data=data)   #stateデックを更新

        return self.state, ti, ti_          #更新されたstateデック、受信した時間、前回受信との間隔を返す

    def observe_update_state_pid_2(self, flag=True, pid=0):

        #ESPからデータを受信
        #正常に受信できれば、受信データ、受信した時間、前回受信との間隔が返ってくる
        #正常に受信できなかった場合、False,0,0が返ってくる
        data, ti, ti_ = self.communicator.receive_from_esp(byt = receive_byt)

        data.append(pid)                    #受信データにPgainを付け加える（pid=0は引数が指定されなかった場合の値なので注意）
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
        try:
            err = abs(float(data[0][5])-0.0)
            if err < 10:
                return 10
            elif err < 20:
                return 0
            elif err <45:
                return -1
            else:
                return -10
        except:
            return 1

    def observe_terminal(self):
        """
        ターミナルスイッチの情報を読み取る
        Returns:
            bool: ターミナルスイッチ
        """
        return self.communicator.termination_switch(default_params)

    #未使用
    def excute_action(self, action):
        """
        行動内容を定義する
        行動内容に沿って機体に通信を送る
        Args:
            action ([int]): 行動の番号
        """
        if action == 0:
            self.params_to_send[RIGHT_WING]=PWM_WING+20
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 1:
            self.params_to_send[RIGHT_WING]=PWM_WING+10
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 2:
            self.params_to_send[RIGHT_WING]=PWM_WING+5
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 3:
            self.params_to_send[RIGHT_WING]=PWM_WING-5
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 4:
            self.params_to_send[RIGHT_WING]=PWM_WING-10
            self.params_to_send[LEFT_WING]=PWM_WING
        elif action == 5:
            self.params_to_send[RIGHT_WING]=PWM_WING-20
            self.params_to_send[LEFT_WING]=PWM_WING

        self.communicator.send_to_esp(self.params_to_send)
        #time.sleep(0.01)

    def execute_action_(self, actions):
        """
        決定した行動に基づくモータ出力の変更を機体に反映（送信）
        """
        #各送信時にparams_to_sendを書き換えて送信していく。
        self.params_to_send[RIGHT_WING] = actions[0]
        self.params_to_send[LEFT_WING] = actions[1]
        print("params_to_send:", end = "")
        print(self.params_to_send)
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
        else:
            return 6
    
    #未使用
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

    #未使用
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

    #未使用
    def get_sentparam(self):
        """
        機体に送った情報を確認する
        Returns:
            [list]: 送った情報
        """
        return self.params_to_send