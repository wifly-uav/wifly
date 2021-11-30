import serial
import time
import serial.tools.list_ports
import datetime
import csv
import msvcrt
import sys

KEYS_LOG = ["Slope", "Pitch", "R-servo", "L-servo", "R-DC", "L-DC", "time"]
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
        ports = list(serial.tools.list_ports.comports())
        devices = [info.device for info in ports]
        if len(devices) == 0:
            print("ポートが見つかりませんでした")
        elif len(devices) == 1:
            port_controller = devices[0]
        else:
            for p in ports:
                print(p)
                print(p.hwid)
            print('Input port number of the controller:')
            port_controller = 'COM' + input()
        #self.__ser = serial.Serial(port_controller, 115200)
        self.__ser = serial.Serial( #SERIAL通信の設定
                        port_controller, #COMの番号
                        baudrate = 57600,
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
        
        print('Connected to controller')

        self.__fail_counter = 0
        self.__test_count = 0
        self.__raw_data = ""
        self.terminal_flag = 1
        self.dataset_from_laz = []
        self.log = [KEYS_LOG]
        self.time_started = None
        self.time_last_receive = time.time()

    def start_laz(self, data_to_send):
        """
        シリアル通信の準備とラズライトに準備させるための関数
        適当なデータを一回送信する
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushInput()
        self.__ser.flushOutput()
        self.send_to_laz(data_to_send)
        self.time_started = time.time()
        #self.recieve_from_laz(False, 5)
        self.time_last_receive = time.time()

    def create_log(self, persed_data,  time):
        """
        記録をとるための関数
        Args:
            persed_data (list): マイコンから送られてきたデータ
            time ([type]): 時間
        Returns:
            list: マイコンのデータと送信したデータ
        """
        #try:
        log_element = [float(i) for i in persed_data[1:-1]]
        log_element.extend([int(i) for i in self.__data_sent])
        log_element.append(float(time))
        return log_element
        #except:
        #    print("error")
        #    print(persed_data)
        #    sys.exit()

    def save_communicate_log(self):
        """
        通信のログをcsvに出力する関数
        """
        with open('com_log_{0:%Y%m%d_%H%M%S}'.format(datetime.datetime.now())+ ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log)

    def recieve_from_laz(self, mode=False, byt=7):
        """
        マイコンからデータを受け取る関数
        whileを使っているので抜け出せなくなる可能性あり
        Args:
            mode (bool): Trueの場合、通信のログを取る
            byt (int): 受け取るデータの数
        Returns:
            list or bool: 通信が成功した場合は、マイコンから送られてきたデータのlist、失敗した場合は、False
            float: 前回受信してからの時間
        """
        self.__ser.flushInput()
        while True:
            #print(self.__ser.in_waiting)
            if self.__ser.in_waiting > 0:
                self.__raw_data =self.__ser.readline().decode('utf-8')
                #print(self.__raw_data)
                #self.__ser.flushInput()
                persed_data = self.__raw_data.split(",")
                #print(str(persed_data) + str(len(persed_data)))
                if len(persed_data) == byt:
                    recieve_time = str(time.time() - self.time_started)
                    delta_time = time.time() - self.time_last_receive
                    self.time_last_receive = time.time()
                    if (persed_data.pop(0).startswith('S') and persed_data.pop(-1).startswith('E')):
                        persed_data.pop(0)
                        if (persed_data[0] != '' or persed_data[0] != '-'):
                            #print(persed_data[0])
                            recieve_time_ = persed_data.pop(-1)
                            #recieve_time_ = 0
                            #add_log = self.create_log(persed_data, recieve_time)
                            #if mode == True:
                            #    self.log.append(add_log)
                            self.dataset_from_laz = persed_data
                            #print(str(self.dataset_from_laz) + ":" + str(recieve_time))
                            self.__fail_counter = 0
                            return self.dataset_from_laz, recieve_time_, delta_time
                        else:
                            print(persed_data[0])
                            print("no data")
                            print(persed_data)
                    else:
                        self.send_to_laz(self.__data_sent)
                        print("error SE")
                        self.__ser.flushInput()
                else:
                    recieve_time = str(time.time() - self.time_started)
                    delta_time = time.time() - self.time_last_receive
                    self.time_last_receive = time.time()
                    print("error byt")
                    print(persed_data)

            elif self.__fail_counter > 10:
                self.send_to_laz(self.__data_sent)
            elif self.__fail_counter > 20:
                print("data receive timeout error!")
                return False , 0, 0

            self.__fail_counter += 1
            #time.sleep(0.005)


    def send_to_laz(self, data_to_send):
        """
        マイコンにデータを送る関数
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushOutput()
        for datum in data_to_send:
            self.__ser.write(bytes([int(datum)]))
        #print("SENT{0}".format(data_to_send))
        self.__data_sent = data_to_send
        time.sleep(0.001)

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

        """
        fail_counter = 0
        self.__ser.flushInput()
        while True:
            flag_termination = self.__ser.readline().decode('utf-8')
            split_data = flag_termination.split(",")
            if len(split_data) == 3:
                #print(split_data)
                if (split_data[0] == "O" or split_data[-1][0] == "N"): # Error check
                    #print(split_data)
                    if split_data[1] == "1":
                        ##通信失敗時に送られる値
                        print("terminal wait")
                        #self.send_to_laz(deta_to_send)
                        time.sleep(0.001)
                    if split_data[1] == "0":
                        return True
                    #return True
            fail_counter += 1
            #if fail_counter > 10:
            #    return False
        """

    def serial_close(self):
        self.__ser.close()


#------------------------TEST CODE -----------------------------------
if __name__ == "__main__":
    communicator = Communicator()
    #output_values_to_laz = [255, 0, 0, 0, 0, 0, 0, 0, 0]
    output_values_to_laz = [255, 10, 20, 30, 40]
    communicator.start_laz(output_values_to_laz)
    print(output_values_to_laz)
    while True:
        a = time.time()
        
        _, _ = communicator.recieve_from_laz(False, 5)
        print("test")
        #data_from_laz , _ = communicator.recieve_from_laz(True, 5)
        communicator.send_to_laz(output_values_to_laz)
        print("test")