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

        #self.start_laz()

    def start_laz(self, data_to_send=[0]):
        print("Press the play button on unity")
        try:
            # 1 接続
            self.s.listen(1)
            self.conn, self.addr = self.s.accept()
            print('Connected to unity')
        except:
            print("can't communicate")

        self.time_started = time.time()
        self.time_last_receive = time.time()

    def perse_raw_data(self):
        self.old_data = [float(i) for i in self.__old_data.split(",")[0:4]]
        self.new_data = [float(i) for i in self.__raw_data.split(",")[0:4]]
        #print(self.new_data)
        return self.new_data #order : roll,pitch,yaw,height

    def recieve_from_laz(self, mode=True, byt=7):
        re = self.conn.recv(1024)
        if mode is False:
            self.send_to_laz([0,0,0,0,0])
        self.__old_data = self.__raw_data
        self.__raw_data = re.decode('utf-8')
        print(self.__raw_data)
        if self.__raw_data == "":
            print("Not connecting")
            self.conn.close()
            print("Reconnect")
            self.start_laz()

        recieve_time = str(time.time() - self.time_started)
        delta_time = time.time() - self.time_last_receive
        self.time_last_receive = time.time()
        data = self.perse_raw_data()

        return data, recieve_time, recieve_time

    def send_to_laz(self, msg):
        a = str(msg)
        b = a.strip("[""]")
        a_utf8 = b.encode("utf-8")
        self.conn.sendall(a_utf8)

    def termination_switch(self, msg):
        self.flag_termination = [float(i) for i in self.__raw_data.split(",")[3:4]]
        if self.flag_termination[0] == 0.0:
            return True
        else:
            return False

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