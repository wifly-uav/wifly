import serial
import time
import serial.tools.list_ports
import datetime
import csv
import msvcrt
import sys
import threading

RECEIVE_BYTE = 8    #receive_from_espの引数

KEYS_LOG = ["Slope", "Pitch", "R-servo", "L-servo", "R-DC", "L-DC", "time"]
#[受信データ , 送信データ , time]
class Communicator():
    """
    マイコンと通信するためのクラス
    このクラスの使用方法はプログラムの最後にあります
    """

    #要確認!!!
    def __init__(self):
        """
        初期化
        COMポートの自動選択をしています
        """
        print('======================START========================')
        ports = list(serial.tools.list_ports.comports())    #シリアルポートのリストを取得
        devices = [info.device for info in ports]           #ポート名を取得?
        if len(devices) == 0:
            print("ポートが見つかりませんでした")
        elif len(devices) == 1:
            port_controller = devices[0]                    #port_controllerにポート名を格納
        else:
            for p in ports:
                print(p)
                print(p.hwid)                               #?
            print('Input port number of the controller:')   #ポート番号の入力を指示
            port_controller = 'COM' + input()               
        #self.__ser = serial.Serial(port_controller, 115200)
        self.__ser = serial.Serial(                     #SERIAL通信の設定
                        port_controller,                #COMの番号
                        baudrate = 460800,             #もとのボーレート
                        #baudrate = 115200,             #遅くしてみた。
                        #baudrate = 57600,              #さらに遅くしてみた。(Lazurite時代と同じ)
                        #baudrate = 38400,               #9600, 14400, 19200, 28800
                        parity = serial.PARITY_NONE,
                        bytesize = serial.EIGHTBITS,
                        stopbits = serial.STOPBITS_ONE,
                        timeout = None,
                        xonxoff = 0,
                        rtscts = 0,
                        )
        #self.__ser = serial.Serial(port_controller, 115200, parity = serial.PARITY_NONE, bytesize = serial.EIGHTBITS, stopbits = serial.STOPBITS_ONE)
        #self.__ser = serial.Serial(port_controller, 115200, parity=serial.PARITY_NONE)
        #self.__ser = serial.Serial(port_controller, 115200, parity=serial.PARITY_ODD)
        #self.__ser.timeout =0.01
        '''
        self.__ser.close()
        self.__ser.parity = serial.PARITY_ODD
        self.__ser.open()
        self.__ser.close()
        self.__ser.parity = serial.PARITY_NONE
        self.__ser.open()
        '''
        
        time.sleep(0.5)

        self.state = [0,0,0,0,0]
        
        print('Connected to controller')

        self.__fail_counter = 0
        self.__test_count = 0
        self.__raw_data = ""
        self.terminal_flag = 1
        self.dataset_from_esp = []
        self.log = [KEYS_LOG]
        self.time_started = None
        self.time_last_receive = time.time()

    def start_esp(self, data_to_send):
        """
        シリアル通信の準備とESPに準備させるための関数
        適当なデータを一回送信する
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushInput()                 #受信キャッシュをflush
        self.__ser.flushOutput()                #送信キャッシュをflush 
        #self.send_to_esp(data_to_send)          #data_to_sendをESPに送信
        self.time_started = time.time()         #最初に送信した時間を記録
        #self.receive_from_laz(False, 5)
        self.time_last_receive = time.time()    #未使用?
    
    def save_communicate_log(self):
        """
        通信のログをcsvに出力する関数
        """
        with open('com_log_{0:%Y%m%d_%H%M%S}'.format(datetime.datetime.now())+ ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log)

    def receive_from_esp(self, byt = RECEIVE_BYTE, try_data = [255,254,254,0,0,0]):
        """
        マイコンからデータを受け取る関数
        whileを使っているので抜け出せなくなる可能性あり
        Args:
            byt (int): 受け取るデータの数
        Returns:
            list or bool: 通信が成功した場合は、マイコンから送られてきたデータのlist、失敗した場合は、False
            float: 前回受信してからの時間
        """
        while True:
            #print(self.__ser.in_waiting)
            if self.__ser.in_waiting > 0:                                   #in_waitingはキャッシュ内に受信されたデータのbyte数を返す。 
                #print("Data found")
                self.__raw_data =self.__ser.readline().decode('utf-8')      #受信データを1行分読み取り、文字列に変換したものを取得
                #print(self.__raw_data) 
                #self.__ser.flushInput()
                persed_data = self.__raw_data.split(",")                    #__raw_dataを","区切りにしたものを取得
                #print("persed_data:", end = "")
                #print(persed_data)

                #print(persed_data)                    
                #出力:[モータ1出力,モータ2出力,サーボ1,サーボ2,受信間隔,Pitch,Yaw,Roll]

                self.__ser.flushInput()         #受信キャッシュ内のデータを破棄（初期化）
                if len(persed_data) == byt:                                     #受信データ長が指定通りならば...
                    if persed_data[0] != " " and persed_data[0] != "":            #先頭の文字抜けが無ければ…
                        #print(str(persed_data) + str(len(persed_data)))
                        #receive_time = str(time.time() - self.time_started)    #受信した時間を記録
                        delta_time = time.time() - self.time_last_receive       #最後の受信との時間間隔をPC側で記録
                        self.time_last_receive = time.time()                    #最後の受信時刻を更新  
                        receive_time_ = int(persed_data.pop(4))                 #機体側のマイコンで計測された受信間隔の読み取り（popなので削除もされる）
                        persed_data.pop(-1)                                     #Roll角削除
                        #persed_data:[モータ出力1,モータ出力2,尾翼サーボ,重心移動機構サーボ,Pitch,Yaw]
                        
                        #状態の整形
                        for i in range(3):
                            persed_data.pop(-2)

                        #persed_data:[モータ出力1,モータ出力2,Yaw]

                        self.dataset_from_esp = persed_data                     #受信データとして記録
                        
                        self.__fail_counter = 0                                 #受信失敗回数をリセット

                        #受信データ、受信間隔（機体計測）、受信間隔(PC)を返す。
                        self.state.append([persed_data[0],persed_data[1],persed_data[2],receive_time_,delta_time])
                        #return self.dataset_from_esp, receive_time_, delta_time
                        #self.__ser.flushInput()         #受信キャッシュ内のデータを破棄（初期化）
                else:
                    #print("Data found but length error.")
                    self.__ser.flushInput()         #受信キャッシュ内のデータを破棄（初期化）
                
            #elif self.__fail_counter > 40:              #受信失敗回数が20回を超えているなら…
                #print("data receive timeout error!")    #タイムアウト（諦める）
                #return False , 0, 0                     #この場合はFalseを返すことに注意
            else:
                pass
                #print("Data not found. Retry.")

            self.__fail_counter += 1                    #受信失敗回数を更新
            #time.sleep(0.005)
            time.sleep(0.02)

    def send_to_esp(self, data_to_send):
        """
        マイコンにデータを送る関数
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushOutput()                    #送信用キャッシュのflush
        send_binary = bytes(data_to_send)
        self.__ser.write(send_binary)
        '''
        for datum in data_to_send:                  #data_to_sendの各要素を...
            self.__ser.write(bytes([int(datum)]))   #2進数に変換したものを送信
            time.sleep(0.001)                       #時間調整（これがないと羽ばたき出力の変更が反映されない）
        self.__data_sent = data_to_send             #送信済みデータとして記録
        #time.sleep(0.001)                           #時間調整(超重要!!!これがないとデータ受信ができない)
        '''
        #self.__ser.flush()

    def termination_switch(self, deta_to_send):
        """
        ターミナルスイッチを確認する関数
        whileを使っているので抜け出せなくなる可能性あり
        Args:
            data_to_send (list): 送信するデータ
        """
        while self.terminal_flag:
            if msvcrt.kbhit():
                key = msvcrt.getch()
                if key == 't'.encode('utf-8'):
                    self.terminal_flag = 1
                elif key == 'y'.encode('utf-8'):
                    self.terminal_flag = 0
                    return True
                print("terminal wait")
        #return self.terminal_flag

    def serial_close(self):
        self.__ser.close()


#------------------------TEST CODE -----------------------------------
if __name__ == "__main__":
    communicator = Communicator()
    #[ヘッダ（定数）,羽モータ1,羽モータ2,角度1,角度2,コントロールモード]
    #output_values_to_esp = [255, 10, 20, 30, 40, 50]    #この値は適当
    #communicator.start_esp(output_values_to_esp)
    #print(output_values_to_esp)
    x = threading.Thread(target=communicator.receive_from_esp)
    x.start()
    while True:
        #pass
        #data, ti, ti2 = communicator.receive_from_esp(byt = 8)
        print(communicator.state[-1])
        #communicator.send_to_esp([255,0,0,0,0,0])