import serial
import time
import serial.tools.list_ports
import threading

RECEIVE_BYTE = 9    #receive_from_espの引数

#[受信データ , 送信データ , time]
class Communicator():
    """
    マイコンと通信するためのクラス
    このクラスの使用方法はプログラムの最後にあります
    """
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
        
        time.sleep(0.5)

        self.state = [0,0,0,0,0]
        
        print('Connected to controller')

        self.__fail_counter = 0
        self.__raw_data = ""
        self.terminal_flag = 1
        self.dataset_from_esp = []
        self.time_started = None
        self.time_last_receive = time.time()
        self.mode = 0
        self.old_data = [0,0,0,0]
    
    def set_mode(self, mode):
        self.mode = mode

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

    def receive_from_esp(self, byt = RECEIVE_BYTE):
        """
        マイコンからデータを受け取る関数
        whileを使っているので抜け出せなくなる可能性あり
        Args:
            byt (int): 受け取るデータの数
        Returns:
            list or bool: 通信が成功した場合は、マイコンから送られてきたデータのlist、失敗した場合は、False
            float: 前回受信してからの時間
        """
        start = time.time()
        while True:
            if self.__ser.in_waiting > 0:                                   #in_waitingはキャッシュ内に受信されたデータのbyte数を返す。 
                self.__raw_data =self.__ser.readline().decode('utf-8')      #受信データを1行分読み取り、文字列に変換したものを取得
                persed_data = self.__raw_data.split(",")                    #__raw_dataを","区切りにしたものを取得               
                #出力:[モータ1出力,モータ2出力,サーボ1,サーボ2,受信間隔,Pitch,Yaw,Roll]

                self.__ser.flushInput()         #受信キャッシュ内のデータを破棄（初期化）
                if len(persed_data) == byt:                                     #受信データ長が指定通りならば...
                    if persed_data[0] != " " and persed_data[0] != "":            #先頭の文字抜けが無ければ…
                        #print(str(persed_data) + str(len(persed_data)))
                        #receive_time = str(time.time() - self.time_started)    #受信した時間を記録
                        delta_time = time.time() - self.time_last_receive       #最後の受信との時間間隔をPC側で記録
                        self.time_last_receive = time.time()                    #最後の受信時刻を更新  
                        receive_time_ = int(persed_data.pop(4))                 #機体側のマイコンで計測された受信間隔の読み取り（popなので削除もされる）
                        #persed_data.pop(-1)
                        #persed_data:[モータ出力1,モータ出力2,尾翼サーボ,重心移動機構サーボ,Pitch,Yaw,RC_Yaw]
                        
                        #状態の整形
                        for i in range(3):
                            persed_data.pop(2)

                        #persed_data:[モータ出力1,モータ出力2,Yaw]
                        self.dataset_from_esp = persed_data                     #受信データとして記録
                        
                        self.__fail_counter = 0                                 #受信失敗回数をリセット
                        persed_data[4] = persed_data[4].strip('\r\n')
                        #受信データ、受信間隔（機体計測）、受信間隔(PC)を返す。
                        if self.mode == 1:
                            self.old_data.pop(0)
                            self.old_data.append(persed_data[2])
                            v1 = (self.old_data[0]-self.old_data[2])/delta_time
                            v2 = (self.old_data[1]-self.old_data[3])/delta_time
                            v_ave = (v1+v2)*0.5
                            a = (v1-v2)/delta_time
                            self.state.append([persed_data[0],persed_data[1],persed_data[2],receive_time_,delta_time,persed_data[3],persed_data[4],v_ave,a])
                        else:
                            self.state.append([persed_data[0],persed_data[1],persed_data[2],receive_time_,delta_time,persed_data[3],persed_data[4]])
                        end = time.time()
                        while(end-start<0.04):
                            end=time.time()
                        start = end
                else:
                    #print("Data found but length error.")
                    self.__ser.flushInput()         #受信キャッシュ内のデータを破棄（初期化）
            else:
                pass
                #print("Data not found. Retry.")

            self.__fail_counter += 1                    #受信失敗回数を更新

    def send_to_esp(self, data_to_send):
        """
        マイコンにデータを送る関数
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushOutput()                    #送信用キャッシュのflush
        send_binary = bytes(data_to_send)
        self.__ser.write(send_binary)

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