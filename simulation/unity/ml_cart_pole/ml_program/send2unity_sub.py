# socket サーバを作成
import socket
import sys
import time

class Communicator():

    def __init__(self):
        # AF = IPv4 という意味
        # TCP/IP の場合は、SOCK_STREAM を使う
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #self.s.settimeout(20.0)
        # IPアドレスとポートを指定
        self.s.bind(('127.0.0.1', 50007))
        self.data = 0
        self.__raw_data = "0,0,0,0,0"
        self.__old_data = "0,0,0,0,0"
        self.flag_termination = []
        self.old_data = []
        self.new_data = []

    def com_start(self):
        print("Press the play button on unity")
        try:
            # 1 接続
            self.s.listen(1)
            self.conn, self.addr = self.s.accept()
            print("success")
        except:
            print("can't communicate")

    def perse_raw_data(self):
        self.old_data = [float(i) for i in self.__old_data.split(",")[0:2]]
        self.new_data = [float(i) for i in self.__raw_data.split(",")[0:2]]
        #print("data")
        #print(self.new_data)
        return self.new_data #order : len,ang,time,reset

    def get_time(self):
        time_data = [float(i) for i in self.__raw_data.split(",")[2:3]]
        return time_data

    def get_hedder(self):
        hedder_data = [int(i) for i in self.__raw_data.split(",")[4:5]]
        hedder = hedder_data[0]
        return hedder

    def recieve_from_unity(self, flag):
        re = self.conn.recv(1024)
        if flag is False:
            self.send_to_unity([0,0,0,0,0])
        self.__old_data = self.__raw_data
        self.__raw_data = re.decode('utf-8')
        #print("raw_data")
        #print(self.__raw_data)
        if self.__raw_data == "":
            print("Not connecting")
            self.conn.close()
            print("Reconnect")
            self.start_com()

    def send_to_unity(self, msg):
        #print("send")
        a = str(msg)
        b = a.strip("[""]")
        a_utf8 = b.encode("utf-8")
        self.conn.sendall(a_utf8)

    def termination_switch(self):
        self.flag_termination = [float(i) for i in self.__raw_data.split(",")[3:4]]
        if self.flag_termination[0] == 0.0:
            return False
        else:
            return True

    def com_finish(self):
        self.s.close()
'''
com = Communicator()

com.com_start()
while True:
    com.recieve_from_unity()
    ret = com.perse_raw_data()
    print("roll:" + str(ret[0])+"pitch:"+str(ret[1])+"yaw:"+str(ret[2])+"height:"+str(ret[3]))
    com.termination_switch()
    message = [1,10,3,10,5]
    com.send_to_unity(message)
    time.sleep(0.5)
'''

'''
# socket サーバを作成

import socket

# AF = IPv4 という意味
# TCP/IP の場合は、SOCK_STREAM を使う
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # IPアドレスとポートを指定
    s.bind(('127.0.0.1', 50007))
    # 1 接続
    s.listen(1)
    # connection するまで待つ
    while True:
        # 誰かがアクセスしてきたら、コネクションとアドレスを入れる
        conn, addr = s.accept()
        with conn:
            while True:
                # データを受け取る
                data = conn.recv(1024)
                if not data:
                    break
                print('data : {}, addr: {}'.format(data, addr))
                # クライアントにデータを返す(b -> byte でないといけない)
                #conn.sendall(b'Received: ' + data)
                #print(type(conn))
'''