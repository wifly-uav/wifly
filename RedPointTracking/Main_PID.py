from Communication import Communicator
from Calc_Control import calc_PID
from detect import Detector
import csv
import datetime
import random as rd
import time
import cv2
import numpy as np
import os
import ffmpeg
#from vidstab import VidStab #補正用

if __name__ == "__main__":
    communicator = Communicator()
    detector = Detector()
    output_values_to_esp = [255, 1, 2, 3, 4]  # [ヘッダ, LDC, RDC, servo, mode]
    saturation = [0 , 254]
    print("test1")
    communicator.start_esp(output_values_to_esp)
    communicator.receive_from_esp() 
    print("test2")
    
    PID_controller = calc_PID(detector.get_PID_params())
    PID_controller_2 = calc_PID(detector.get_PID_params())
    PID_controller_3 = calc_PID(detector.get_PID_params())
    PID_controller_4 = calc_PID(detector.get_PID_params())
    
    terminal = False
    i = 0

    os.mkdir('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()))  # おおもとのディレクトリ作成
    new_path = 'C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) # その下のディレクトリのパス
    os.mkdir(new_path) #　上のパスのディレクトリの作成

    LDC=0
    RDC=0
    servo = 0
    #servo=128 # いったんservo = 0はあり
    mode=0
    pwm_def = 200 # pwm_def = 126ではない？
    
    detector = Detector()
    #esp_ip = "192.168.128.101"  
    #esp_ip = "192.168.137.233" # 新しいカメラのipアドレス
    #esp_ip = "192.168.137.119" # 新しいカメラのipアドレス
    esp_ip = "192.168.137.39" #epeeyeのipを随時打ち込む、随時変更
    framewidth = 1200 # 横幅指定 1200 値はピクセル
    frameheight = 600 # 縦幅指定 600
    # framewidth_2 = 1200 # 失敗
    # frameheight_2 = 600 # 失敗q
    capture = cv2.VideoCapture(f"rtsp://{esp_ip}:8554/mjpeg/1") # カメラの番号がesp_ipに入る
    
    # 動画ファイル保存用の設定
    fps = int(capture.get(cv2.CAP_PROP_FPS))             # カメラのfpsを取得
    print("camera fps is " + str(fps))
    if fps > 65535: # fpsは最大65535しか取れない
        fps = 65535
    #w = int(capture.get(cv2.CAP_PROP_FRAME_WIDTH))       # カメラの横幅を取得
    #h = int(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))      # カメラの縦幅を取得
    fourcc = cv2.VideoWriter_fourcc('m', 'p', '4', 'v')  # 動画保存時のfourcc設定 (mp4用)、コーデック(画像のつながりを圧縮するときに使われる) → H264フォーマットにするのもあり結果として意味なし
    #fourcc = cv2.VideoWriter_fourcc('M', "J", "P", "G") # 補正のため
    video = cv2.VideoWriter('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/camera.mp4', fourcc, fps, (framewidth, frameheight)) # 動画の仕様(ファイル名, fourcc, FPS, サイズ) サイズはウィンドウのサイズで指定する
    #video = cv2.VideoWriter('C:/Users/naush/Downloads/result/1106/camera.avi', fourcc, fps, (framewidth, frameheight)) # ブレ補正をかける
    #stabilizer = VidStab(kp_method = 'ORB')
    #stabilizer.stabilize(input_path = 'C:/Users/naush/Downloads/result/1106/camera.mp4', output_path = 'C:/Users/naush/Downloads/result/1106/camera.avi' )
    
    # エンコーディングオプションを設定して、ファイルを指定した場所に保存する
    #input_file = 'C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/camera.mp4'
    #output_file = 'C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/Redpoint_camera.mp4'

    #ffmpeg.input(input_file).output(output_file, codec = 'libx264', crf = 23).run()

    #print(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
    #print(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))
    
    # 保存先の番号を必ず変更すること
    with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_result_esp_test.csv','w', newline="") as f: # 番号の部分変更
        writer = csv.writer(f)
        writer.writerow(["now_time","Defference"])
        
    with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_result_esp.02_test.csv','w', newline="") as f: # 番号の部分変更
        writer = csv.writer(f)
        writer.writerow(["now_time","Area"])
    
    old_time = time.time()


    while not terminal:
        terminal = False
        
        _, frame =  capture.read() # カメラから取得した映像のデータ
        # time.sleep(0.001)
        
        #frame_new = cv2.resize(frame, dsize = (framewidth, frameheight)) # ウィンドウに表示するフレームのサイズ変更
        middle_point = []
        # width = 160
        # height = 120
        middle_point_capture = [160, 120] # カメラの中央点を調査 横、縦の順
        rects = detector.find_rect_of_target_color(frame) # 長方形の大きさの変数
        
        communicator.receive_from_esp()
        # print(communicator.dataset_from_esp) # 出力値を確認,一応いるかどうか確認
        #print(communicator.dataset_from_esp[0], communicator.dataset_from_esp[1], communicator.dataset_from_esp[2])
        print("communicator.dataset_from_esp = " + str(communicator.dataset_from_esp[0:3]))
        
        """
        if communicator.dataset_from_esp[0] == 255 or RDC == communicator.dataset_from_esp[1] == 255:
            output_values_to_esp[1] = 200
            output_values_to_esp[2] = 200
            communicator.send_to_esp(output_values_to_esp)
            communicator.receive_from_esp()
            print("communicator.dataset_from_esp = " + str(communicator.dataset_from_esp[0:3]))
        """

        # PID出力がそもそも差が0だから無理
        out4 = PID_controller_4.calculate_output(detector.get_PID_params_02(2.3, 0.0001, 0.1, 0), float(communicator.dataset_from_esp[0])) # これ使用しない
        
        # 以下の値wifly2はサーボがどちらかしかないのでこの値をどうするか
        # servo = 108
        #servo_L = 148
        #RDCはカメラを正対させて右側
        #LDCはカメラを正対させて左側
        
        if len(rects) > 0:
            rect = max(rects, key=(lambda x: x[2] * x[3]))
            print("rect = "+str(rect))
            
            #外接四角形の条件（赤いノイズを無視するため）
            if rect[2] > 22 and rect[3] > 22:
                
                middle_point.append(rect[0]+(rect[2]/2))    # 外接四角形の横幅の真ん中の座標
                middle_point.append(rect[1]+(rect[3]/2))    # 外接四角形の縦幅の真ん中の座標、この二つをmiddle_pointリストとして追加[x/2,y/2]となっている。
                print("middle_point = "+str(middle_point))  # 外接四角形の中心座標出力
                
                #グラフ描写用の時間定義
                now_time = time.time() - old_time
                print("now_time = "+str(now_time))
                
                #画面の中心点と目標物の中点のズレ
                deference = [0,0]   #　ずれのリスト作成、初手[0,0]
                deference[0] = middle_point[0] - middle_point_capture[0]    # middlepoint(x座標の方)からカメラの中心座標を引く
                deference[1] = middle_point[1] - middle_point_capture[1]    # middlepoint(y座標の方)からカメラの中心座標を引く
                print("middle_point_diffecence" + str(deference))

                #外接四角形の面積
                Area = rect[2]*rect[3]  #　外接四角形の面積計算
                print("Area ="+str(Area))
                
                #CSVファイルに出力（時間と目標数値）随時ファイル番号変更
                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_result_esp.x.csv','a', newline="") as f:   # 'a'は追記モードで開く。ファイルで使われている改行コードを自動認識、自動変換はなし。newline = ""
                    writer = csv.writer(f)
                    writer.writerow([str(now_time),str(deference[0])]) #横軸

                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_result_esp.y.csv','a', newline="") as f:
                     writer = csv.writer(f)
                     writer.writerow([str(now_time), str(deference[1])]) #縦軸

                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_result_esp.z.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(now_time),str(Area)]) # 深度(面積)
                
                # 長方形の探索プログラムでは画像から長方形の大きさ、面積までを見積もるという感じで画像にその長方形を画像には書きこまないので、ここで画像に書き込む感じだと思う
                cv2.rectangle(frame, tuple(rect[0:2]), tuple(rect[0:2] + rect[2:4]), (0, 0, 255), thickness=2)
                vectoring = 0   # vectoringはどこで使う？
                
                #PID
                #PWM
                out1 = PID_controller.calculate_output(detector.get_PID_params_02(0.5, 0.01, -0.02, 120), middle_point[1]) # 縦幅　middle_point[]は現在の赤玉がいる位置
                # 引数は(0.5, 0.01, -0.05, 60)はPIDの(Pの係数, Iの係数, Dの係数, 目標値として使用される値(セットポイント))
                #gain = (0.5, 0.01, -0.05, 120)
                
                #spin 2の場合spinでなくなる
                out2 = PID_controller_2.calculate_output(detector.get_PID_params_02(0.4, 0.3, 0.13, 160), middle_point[0]) # 横幅
                #gain =(0.4, 0.3, 0.09, 160)

                #Area
                out3 = PID_controller_3.calculate_output(detector.get_PID_params_02(0.05, 0.01, 0.002, 8000), Area) # 深度
                #gain =(0.02, 0.01, 0.002, 2000)

                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_out1.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(now_time), str(out1), str(deference[1])])

                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_out2.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(now_time), str(out2), str(deference[0])])
                
                with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/PID_out3.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(now_time), str(out3), str(Area)])

                # print(out1, out2, out3)

                #if out1 !=0 or out2 != 0 or out3 != 0:
                #    LDC = 0
                #    RDC = 255

                """
                if out1 > 0 or out1 < 0:
                    RDC = 254
                    LDC = 254
                elif out2 > 0 or out2 < 0:
                    RDC = 254
                    LDC = 254 
                elif out3 > 0 or out3 <0:
                    RDC = 254
                    LDC = 254
                """

                """
                # 手動で離陸が出来なかった場合
                if (RDC == 0 and LDC == 0) or ( 250 <= RDC <= 254 and 250 <= LDC <= 254):
                    RDC = 250
                    LDC = 255
                """

                #ボールの上下 以下値は調整
                lift_power = 200 + out1
                """
                if lift_power >= 201 and lift_power <= 255:
                    LDC = lift_power
                    RDC = lift_power
                elif lift_power > 150 and lift_power < 175:
                    LDC = 200
                    RDC =200
                elif lift_power < 150: 
                    LDC = 150
                    RDC = 150
                """
                if lift_power != 200 and lift_power < 255:
                    LDC = lift_power
                    RDC = lift_power
                elif out1 == 0 and lift_power == 200:
                    LDC = 255
                    RDC = 220
                elif lift_power >= 255:
                   LDC = 255
                   RDC = 220

                # ボールの左右 以下の値は調整 マイナスよりも少なくなっていたら機体が反時計回りに回転しているのでカメラをつけている方から見てLDC(後ろからRDC)のモータを弱める、逆ならもう一つのモータ(RDC(後ろだとLDC))を弱める
                """
                spin = lift_power + out2
                if spin <= 200 and spin >= 170: 
                    RDC = RDC -30
                elif spin < 170 and spin >= 135:
                    RDC = RDC - 25
                elif spin < 135 and spin >= 100:
                    LDC = LDC - 30
                elif spin < 100:
                    LDC = LDC -25
                """
                # 引くだけでなく、場合によっては足し算もあり

                lift_power_L = lift_power
                lift_power_R = lift_power

                if lift_power > 255:
                    lift_powr = 255
                    lift_power_L = lift_power
                    lift_power_R = lift_powr - 55

                if out2 < 0 and out2 >= -50:
                    LDC = LDC - 45
                    RDC = lift_power_R
                elif out2 < -50 and out2 >= -100:
                    LDC = LDC - 55
                    RDC = lift_power_R
                elif out2 < -100:
                    LDC = LDC - 65
                    RDC = lift_power_R 
                elif out2 > 0 and out2 <= 50:
                    RDC = RDC - 45
                    LDC = lift_power_L
                elif out2 > 50 and out2 <= 100:
                    RDC = RDC - 55
                    LDC = lift_power_L
                elif out2 > 100:
                    RDC = RDC - 65
                    LDC = lift_power_L
                elif out2 == 0 and communicator.dataset_from_esp[0] == 0 and communicator.dataset_from_esp[1] == 0:
                    LDC = 255
                    RDC = 220

                #深度
                depth = 108 + out3
                if depth >= 400 or (depth < 400 and depth >= - 600):
                    servo = 165 
                elif depth < -600 and depth >= -800:
                    servo = 90
                elif depth < -800:
                    servo = 100
                elif depth < -1000:
                    servo = 0
                elif depth == 108:
                    servo = 60
                
                """
                    #前傾か後傾か
                depth_R = 108 + out3    # 右サーボの値?、深度の値(サーボに関する値なの？)、深度からどのくらい離れているか計算してそれによって出力調整?
                if depth_R > 185:
                    depth_R = 185   # 185より大きいなら深度が185これはサーボ値を変えている？
                elif depth_R < 0:   
                    depth_R = 0
                    
                print("depth_R ="+ str(depth_R))
                    
                depth_L =148 - out3 # 119行目で足してるのにこっち引いてる理由 基本引き算をやめる、足し算にすれば値がマイナスになってもプラスになることはない
                # if depth_L > 255:
                       # depth_L = 255   # ワンチャン255がサーボ値の限界?
                #elif depth_L < 70:
                       # depth_L = 70
                        
                print("depth_L ="+ str(depth_L)) 
                    
                    #サーボの左右のずれ←ずれとは? 今回左右にサーボ無いのでこれはいらないかも
                spin_R = depth_R - out2 # ずれたときの値を計算？
                if spin_R > 255:
                        spin_R = 255
                elif spin_R < 0:
                        spin_R = 0
                        
                spin_L = depth_L - out2
                if spin_L > 255:
                        spin_L = 255
                elif spin_L < 0:
                        spin_L = 0
                        
                    # サーボの関数を新しくすること    
                servo = spin_R    # ここでサーボ値へと変換？、2ではサーボに値を変換はしない
                #servo_L = spin_L

                print("spin_R ="+ str(spin_R))
                print("spin_L ="+ str(spin_L))
                    # ここで行っている計算、実験時にどこの値として作用しているの確認
                    
                    
                    #羽ばたき周波数制御PID ←これはDCモータに関わるはずである
                            
                lift_power = 128 + out1
                if lift_power > 255:
                        lift_power = 255

                if lift_power < 0:
                        lift_power = 0

                print("Lift power ="+ str(lift_power))
                            


                LDC = lift_power
                RDC = lift_power
                    #LDC = 255
                    #RDC = 255
                """
        else:
            #目標物を見失ってもPID計算の時間は更新しておく
            PID_controller.update_elapsed_time_from_last_step() # Calc_Control.pyの31行目の処理を行う
            PID_controller_2.update_elapsed_time_from_last_step()   # 176行目と同様
            PID_controller_3.update_elapsed_time_from_last_step()   # 176行目と同様
            
        
        #LDC = 250
        #RDC = 250
        mode = 1 # ここでmode=1にしている理由は?そもそもmodeの違いとは何か 多分重心移動機構の0or1
        
        
    # 14行目で設定したリストの中身[1~5]は適当に値が設定されていたのでそこにそれぞれの値を代入していく
    # persed_data = [0, 1, 2, 3, 4, 5, 6, 7] , persed_data[2] = output_values_to_esp[3], persed_data[3] = output_values_to_esp[4]
        if RDC > 255:
            RDC = 220
        elif LDC > 255:
            LDC = 255

        output_values_to_esp[1] = RDC # モータ出力の番号がどちらになるかは調整
        output_values_to_esp[3] = servo # ここのサーボどちらの値にするか
        output_values_to_esp[2] = LDC # RDCと同様
        output_values_to_esp[4] = mode #cogの位置

        with open('C:/Users/naush/Downloads/result/{0:%Y%m%d}'.format(datetime.datetime.now()) + '/{0:%Y%m%d_%H}'.format(datetime.datetime.now()) + '/Datasetlog.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(time.time()), str(communicator.dataset_from_esp[0:3]), str(output_values_to_esp[1:5])])
        
    # output_values_to_laz[5] = servo_R
        print("output_values_to_esp = "+str(output_values_to_esp)) # output_values_to_put = [ヘッダ, RDC, servo, LDC, mode]
        print(".............")
        communicator.send_to_esp(output_values_to_esp) # espnowに値を送る関数
        
        frame_new = cv2.resize(frame, dsize = (framewidth, frameheight)) # ウィンドウに表示するフレームのサイズ変更
        video.write(frame_new) # もしかしたら書き込めるかも
        cv2.imshow('red',frame_new) # 画像出力のコマンド、第一引数が出力するwindowのコマンド名、第二引数が出力する画像が格納されている変数名(62行目のframe(画像を格納))
        # imshowを実行するためにはwaitkeyを実行してキー入力待ち状態とする必要がある
        # waitkey(1)は1ミリ秒だけキーボードの入力を待機してキーが押された場合、その押されたキーのASCIIコードを返す
        # & 0xFFは返されたASCIIコードを0xFFとのAND演算で下位8ビットに変換する。これにより正確なASCIIコードを取得する。
        # ord('q')は文字qのASCIIコードを取得
        if cv2.waitKey(1) & 0xFF == ord('q'): # キーボードからqを押されたか確認する、qを押されればtrue、押されなければfalse
            break   # while文終了　qキーが押された場合
        # 主に上の操作はwhile文で適用されキー入力を待機している間にbreakする、これをすることでユーザーがキーボードからプログラムを終了できるようにしてる
        

    f.close()   # ファイル閉じる
    communicator.save_communicate_log() 
    communicator.serial_close() 
    print("Logging End. Serial closed")

    capture.release()   # caputure.release()はカメラやビデオファイルからのキャプチャを行う場合、それに対応するリソースがオープンしている場合、リソース開放でキャプチャが停止される
    # 62行目のcaputureでビデオファイルをcapture開始している、カメラやビデオファイルが不要になったときこの動作を行いリソースの無駄を省き、プログラムをスムーズに動かす
    cv2.destroyAllWindows() # opencvを使用して開いているウィンドウをすべて閉じる 