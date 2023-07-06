import serial #シリアル通信を始めるためのimport、シリアル通信とはデータを送受信するための伝送路を1本、または2本使用して、データを1ビットずつ連続的に送受信する通信方式
import time #timeモジュールの実装、実行時間の計測が可能
import serial.tools.list_ports #シリアルポートポートの一覧を取得するメソッド
import datetime #日付や時刻を操作するができるモジュール
import csv #CSVファイルの読み込みと書き込みを行うモジュール ここでテキストデータを使う意味は?? CSVの説明 : https://ja.wikipedia.org/wiki/Comma-Separated_Values
import msvcrt # キー入力をそのまま受け取るモジュール
import sys #sysとはPythonのインタプリタや実行環境に関する情報を扱うためのライブラリである。使用しているプラットフォームを調べるときや、スクリプトの起動パラメータを取得する場合などに利用 https://freestyle.nvo.jp/archives/3632

KEYS_LOG = ["Slope", "Pitch", "R-servo", "L-servo", "R-DC", "L-DC", "time"] # KEYS_LOGリスト作成　DCモータの左と右をL-DC，R-DC
#[受信データ , 送信データ , time]
class Communicator():   # Communicatorクラスの作成
    """
    マイコンと通信するためのクラス
    このクラスの使用方法はプログラムの最後にあります ←TEST CODE以下
    """
    def __init__(self): # コンストラクタ インスタンスを生成した際にまず自動的に呼び出すメソッド　ここでインスタンスとはclass Communicatorをもとに生成した実体(class Cmomunicator()全体で起こったこと)
        """
        初期化
        COMポートの自動選択をしています     COMポートとはhttps://e-words.jp/w/COM%E3%83%9D%E3%83%BC%E3%83%88.html
        """
        print('======================START========================')
        ports = list(serial.tools.list_ports.comports())    #　シリアルポートの一覧を取得
        devices = [info.device for info in ports]   #　ポート名をリストとしてdevicesに格納する、ただしリストなので複数存在する場合もあるためそれを調べることも可能
        if len(devices) == 0:   # シリアル通信できるデバイスが見つからなかった場合
            print("ポートが見つかりませんでした")
        elif len(devices) == 1: #　ポートが一つ見つかった場合(devicesはリストよりlen(devices)で要素数の判定を行っている)はport_controllerにdevicesのポート名(文字列)を代入
            port_controller = devices[0]    #　リストdevicesの中にある要素は文字列
        else:   # ポートが複数見つかった場合はそれらを表示させる
            for p in ports: #　デバイスに代入したポート名だけを出力するのではなく、シリアルポートにある一覧の中の細かい情報までprintするためにfor i in range(len(devices[i]))を使用せずにfor p in portsとしている
                print(p)    # これによってex) COM3 - USBシリアルデバイス(COM3)のような情報が出てくる https://ganbaranai.tech/tech-blog/python-pySerial-listPorts/
                print(p.hwid)   # これによってex)USB VID:PID=2341:0042 SER=85734323331351C0F1A0 LOCATION=1-2のような情報が出る hwidとはwindowsがドライバーパッケージにデバイスを照合するたえに使用するベンダー定義の識別文字列
            print('Input port number of the controller:')   # コントローラーのポート番号をインプットさせる
            port_controller = 'COM' + input()   #　COMとinput関数によって入力した番号をport_controllerに代入する(ここではprintからfor文を抜け出しているのでfor文でプリントされたポート番号の中からどれがよいか自分でポート番号を選ぶことによってport_controllerに代入する)
        #self.__ser = serial.Serial(port_controller, 115200) 基本的にはこれでデバイス名とボーレートを設定しポートをオープンする
        self.__ser = serial.Serial( #SERIAL通信の設定 defしたときに第一引数をselfとしているためself.にしている　この作業によってポートを開く際にオプションの指定が可能
                        port_controller, #COMの番号
                        baudrate = 57600,   #　ボーレート(1秒あたり何ビットのデータを送るかという単位で通信速度を表す)　つまり1秒あたり57600回変調・復調できる
                        parity = serial.PARITY_NONE,    # パリティの初期値をparityに代入 通信の信頼性を確保するためパリティビットを設定することができる。そもそもパリティは誤り検出に用いられる技術
                        bytesize = serial.EIGHTBITS,    # データのビット数を指定する 初期値を代入する bytesizeとは文字列のバイト長を整数で返すことが可能、byteseizeを8bitにするとカタカナや漢字を送信可能
                        stopbits = serial.STOPBITS_ONE, # ストップビットを指定する 初期値を代入 シリアル通信において、ひとまとまりのデータの終了を通知するためのマークとして付けられるビット情報
                        timeout = None, #　タイムアウトの時間　読み取り時のタイムアウトを指定する　Noneなら無限に待つ
                        xonxoff = 0, # XON/XOFFの使用を指定する、無手順通信方式において、通信の一時停止と再開とを指示するために用いるフロー制御方式のこと、もしくはその制御に用いられる符号のこと 受信者のバッファがあふれそうになった、あるいは受信データに処理が追いつかない、といった場合に、受信側が送信側に対してデータの送信を一旦停止するよう要請するときに「X-OFF」符号が用いられる
                        rtscts = 0, # RTS/CTSの使用を指定する、RTS/CTSフロー制御は、無線通信が行われる際に使用される一種の通信制御方式。RTSは送信側が通信開始の意思を送信先に伝えるために使用、CTSとは通信先が送信側に通信してもよいと伝えるために使用
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
        
        time.sleep(0.5) # 引き数にした時間の間(秒)、プログラムが停止する 一定の間隔で処理を実行するとか指定した時間に処理を開始する、猶予時間を経て処理を実行するなどの場合に便利
        
        print('Connected to controller')

        self.__fail_counter = 0 # 62~69行目これは何をしたい？？そもそもおいてる変数の意味がわからない 一応このような変数を定義しているとする、それのみで
        self.__test_count = 0
        self.__raw_data = "" # 空の文字列をつくる
        self.terminal_flag = 1
        self.dataset_from_laz = []  # Lazriteからのデータセットを格納するためのリストを作成
        self.log = [KEYS_LOG]   # リストの中にリストつまり二次元配列を作る self.log = [["Slope", "Pitch", "R-servo", "L-servo", "R-DC", "L-DC", "time"]] self.log[0][0] = "Slope" self.log[0][1] = "Pitch"
        self.time_started = None
        self.time_last_receive = time.time()    #　UNIXエポックからの経過秒数を代入

    def start_laz(self, data_to_send):  # data_to_send = output_values_to_laz = [255, 1, 2, 3, 4, 5](ただしこの値は初期値)
        """
        シリアル通信の準備とラズライトに準備させるための関数
        適当なデータを一回送信する
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushInput() # 入力バッファをflushする　入力バッファとは本器で受信データを貯めておくところつまり準備なら一回キャッシュするということ
        self.__ser.flushOutput()    # 出力バッファをflushする　出力バッファとは通信機器において、一時的に通信データを格納する場所なので準備段階で一回キャッシュするということ
        self.send_to_laz(data_to_send)  #data_to_sendをlazriteに送信
        self.time_started = time.time() # 最初に送信した時間を記録
        #self.recieve_from_laz(False, 5)
        self.time_last_receive = time.time()    #　最新の受信時間を記録する?

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

    def recieve_from_laz(self, mode=False, byt=4):
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
        self.__ser.flushInput() #　受信バッファをフラッシュする
        while True:
            #print(self.__ser.in_waiting)
            if self.__ser.in_waiting > 0: # シリアルバッファに受信データがあるか(バッファに含まれるバイト数)を調べる https://qiita.com/mml/items/ccc66ecc46d8299b3346
                self.__raw_data =self.__ser.readline().decode('utf-8')  # decode : バイト列を文字列に戻す  utf-8の意味→https://zerofromlight.com/blogs/detail/89/#_2 self.__ser.readline()のバイト列を文字列に戻したものに64行目で空の文字列を作ったものに代入する
                #print(self.__raw_data)
                #self.__ser.flushInput()
                persed_data = self.__raw_data.split(",")
                #print(str(persed_data) + str(len(persed_data)))
                if len(persed_data) == byt:
                    recieve_time = str(time.time() - self.time_started)
                    delta_time = time.time() - self.time_last_receive
                    self.time_last_receive = time.time()
                    if (persed_data.pop(0).startswith('S') and persed_data.pop(-1).startswith('E')):
                        if (persed_data[0] != '' or persed_data[0] != '-'):
                            #recieve_time_ = 0
                            #add_log = self.create_log(persed_data, recieve_time)
                            #if mode == True:
                            #    self.log.append(add_log)
                            self.dataset_from_laz = persed_data
                            #print(str(self.dataset_from_laz) + ":" + str(recieve_time))
                            self.__fail_counter = 0
                            return self.dataset_from_laz
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
                return False , 0, 0 # これによってFalseにすることでwhileを抜け出す

            self.__fail_counter += 1
            #time.sleep(0.005)


    def send_to_laz(self, data_to_send):    # send_tp_lazは引数でdata_to_sendをとる、そもそもこのdata_to_sendは71行目にmainからもらったものである。80行目でdata_to_sendを引数としてこのメソッドを使用、そのときにdata_to_sendの値がここに送られてくる
        """
        マイコンにデータを送る関数
        Args:
            data_to_send (list): 送信するデータ
        """
        self.__ser.flushOutput()    # 出力バッファをflushする 
        for datum in data_to_send:  # data_to_sendの要素0~5までをdatumに代入してself._ser.write(bytes([int(datum)]))の処理を行う
            self.__ser.write(bytes([int(datum)]))   # ポートオブジェクトserに対してwrite()を使用することで送信が可能、バイト型にするためにbytes()としてそれを送信する　int(datum)そもそもdatumがfloatの可能性があるのでintにする(floatからbyteに変換は不可能だから)　[]は必要これがないと求めている数字にならないことを実験的に証明。あとbytes型というのはb'文字列'という形式であるこの形覚えておく
        #print("SENT{0}".format(data_to_send))
        self.__data_sent = data_to_send # self._data_sent = data_to_send = [255, 1, 2, 3, 4, 5]
        time.sleep(0.001)   # 0.001秒間プログラムを停止させる

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
        self.__ser.close()  # ポートのクローズ


#------------------------TEST CODE -----------------------------------
if __name__ == "__main__": #　インスタンスの実体 ただしこれは_name_ == "_main_"はこのCommunication.py自体を実行しない限り、絶対に走らない
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