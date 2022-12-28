#import threading
import statistics
import socket
import json
import struct
import numpy as np
import time
#import matlab.engine

#[受信データ , 送信データ , time]
class Communicator():
    """
    マイコンと通信するためのクラス
    このクラスの使用方法はプログラムの最後にあります
    """
    def __init__(self):
        """
        初期化
        """
        #self.eng = matlab.engine.start_matlab()
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.bind(('127.0.0.1',9999))
        self.s.listen(1)
        print('waiting for connection...')
        #eng.sym('com_test')
        #time.sleep(1)
        self.sock, self.addr = self.s.accept()
        print('connected to simulink')

        self.state = [[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]]
        

        self.motor_r = 0
        self.motor_l = 0
        self.angle = -90
        self.omega = 0

        self.__raw_data = ""
        self.time_started = None
        self.time_last_receive = time.time()
        self.old_data = [0,0,0,0]
        self.old_dyaw_data = [0,0,0,0]

    def start_esp(self, data_to_send):
        """
        """
        self.time_started = time.time()         #最初に送信した時間を記録
        self.time_last_receive = time.time()    #未使用?

    def receive_from_esp(self):
        """
        """
        delta_time = time.time() - self.time_last_receive       #最後の受信との時間間隔をPC側で記録
        self.time_last_receive = time.time()                    #最後の受信時刻を更新  
        receive_time_ = 40                 #機体側のマイコンで計測された受信間隔の読み取り（popなので削除もされる）
        
        #状態の整形
        ddyaw = 0
        self.old_dyaw_data.pop(0)
        self.old_dyaw_data.append(int(ddyaw))
        a = statistics.mean(self.old_dyaw_data)

        #persed_data:[モータ出力1, モータ出力2, Yaw, RC_Yaw, dyaw]
        persed_data = [self.motor_r,self.motor_l,int(self.angle),int(self.omega),int(self.omega)]
        
        #受信データ、受信間隔（機体計測）、受信間隔(PC)を返す。
        self.old_data.pop(0)
        self.old_data.append(int(persed_data[4]))
        v_ave = statistics.mean(self.old_data)
        self.state.append([persed_data[0],persed_data[1],persed_data[2],receive_time_,delta_time,persed_data[3],persed_data[4],v_ave,a,ddyaw])


    def send_to_esp(self, data_to_send):
        """
        マイコンにデータを送る関数
        Args:
            data_to_send (list): 送信するデータ
        """
        self.motor_r = data_to_send[2]
        self.motor_l = data_to_send[1]
        s = f'{self.motor_r:03}{self.motor_l:03}'
        s_l = s.encode("utf-8")
    
        self.sock.send(s_l)
        for i in range(800):
            re = self.sock.recv(1024)
        #re = self.sock.recv(1024)
        self.re_ = re.decode('utf-8')
        self.angle = self.re_.split("\r")[0]
        self.omega = self.re_.split("\r")[1].split(" ")[1]


    def serial_close(self):
        self.sock.close()