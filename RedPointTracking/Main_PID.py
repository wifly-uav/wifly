from Communication import Communicator  # from ファイル名　import 関数名  formを使用してファイル名を指定すると、関数名を直接記述することができる。つまり今回はCommunicationというファイルの中のCommunicator関数を使用できるようにする
from Calc_Control import calc_PID   # Calc_Controlファイル内のcalc_PID関数を使用
from detect import Detector # detectファイル内のDetector関数を使用するたまimport
import csv  # CSVファイルの読み込みと書き込みを行うモジュール ここでテキストデータを使う意味は?? CSVの説明 : https://ja.wikipedia.org/wiki/Comma-Separated_Values
import datetime
import random as rd # randomモジュールをas rdとして使用する
import time
import cv2 # openCVのcv2.cvtColorを用いるためのモジュール??
import numpy as np  # numpyはpythonで数値計算を高速に行うためのライブラリであり、多次元配列の扱いに役立つ

if __name__ == "__main__":
    communicator = Communicator()   # Class Communicator内のコンストラクタに引数()を渡して、communicatorインスタンスを生成している
    detector = Detector()   # Class Detector内のコンストラクタに引数()を渡して、detectorインスタンスを生成している
    output_values_to_laz = [255, 1, 2, 3, 4, 5] # 送る値の初期値 lazを送信モードにするために値を送る必要があるのでテキトーに設定した値
    # [ヘッダ, LDC, RDC, servo_R, servo_L, mode]
    saturation = [0 , 254] #　この値何?? のちに出てきたら理解する
    print("test1")
    communicator.start_laz(output_values_to_laz)    # Communicatorクラス内のstart_lazメソッドを呼び出す output_values_to_lazのリストの値をstart_lazメソッドに渡す
    #傾きPID用
    communicator.recieve_from_laz() # Communicatorクラス内のrecieve_from_lazメソッドを呼び出す
    print("test2")
    
    PID_controller = calc_PID(detector.get_PID_params())    # class calc_PID内のコンストラクタに引数(クラスdetector内のget_PID_params()メソッド)を渡して、PID_controllerインスタンスを生成する
    PID_controller_2 = calc_PID(detector.get_PID_params())  # 上と同様にそれぞれPID_controller2~4インスタンスを生成
    PID_controller_3 = calc_PID(detector.get_PID_params())
    PID_controller_4 = calc_PID(detector.get_PID_params())

    
    terminal = False
    i = 0

    LDC=0
    RDC=0
    servo_L=128
    servo_R=128
    mode=0
    pwm_def = 200

    detector = Detector()
    esp_ip = "192.168.128.101"
    capture = cv2.VideoCapture(f"rtsp://{esp_ip}:8554/mjpeg/1")
    #capture = cv2.VideoCapture(0)
    print(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
    print(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))

    
    with open('PID_result_esp.csv','w', newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["now_time","Defference"])

    with open('PID_result_esp.02.csv','w', newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["now_time","Area"])

    old_time = time.time()
    


while not terminal:
            terminal = False # if terminal or not ループを続けるかどうか

            _, frame = capture.read()
            middle_point = []
            middle_point_capture = [80, 60]
            rects = detector.find_rect_of_target_color(frame)

            communicator.recieve_from_laz()
            print(communicator.dataset_from_laz)

            #ラズライトセンサー情報でのRoll_PID
            out4 = PID_controller_4.calculate_output(detector.get_PID_params_02(2.3, 0.0001, 0.1, 0), float(communicator.dataset_from_laz[0]))
            #深度コントロールで目標物を見失ったときサーボを初期値に戻すため
            servo_R = 108
            servo_L = 148
            
            if len(rects) > 0:
                rect = max(rects, key=(lambda x: x[2] * x[3]))
                print("rect = "+str(rect))

                #外接四角形の条件（赤いノイズを無視するため）
                if rect[2] > 22 and rect[3] > 22:
                    
                    middle_point.append(rect[0]+(rect[2]/2)) 
                    middle_point.append(rect[1]+(rect[3]/2))
                    print("middle_point = "+str(middle_point))

                    #グラフ描写用の時間定義
                    now_time = time.time() - old_time
                    print("now_time = "+str(now_time))

                    
                    #画面の中心点と目標物の中点のズレ
                    deference = [0,0]
                    deference[0] = middle_point[0] - middle_point_capture[0]
                    deference[1] = middle_point[1] - middle_point_capture[1]

                    #外接四角形の面積
                    Area = rect[2]*rect[3]
                    print("Area ="+str(Area))
                    

                    #CSVファイルに出力（時間と目標数値）
                    with open('PID_result_esp.csv','a', newline="") as f:
                        writer = csv.writer(f)
                        writer.writerow([str(now_time),str(deference[0])])

                    with open('PID_result_esp.02.csv','a', newline="") as f:
                        writer = csv.writer(f)
                        writer.writerow([str(now_time),str(Area)])

                    


                    cv2.rectangle(frame, tuple(rect[0:2]), tuple(rect[0:2] + rect[2:4]), (0, 0, 255), thickness=2)
                    vectoring = 0
                    #cv2.imshow('red',frame)

                    #PID
                    #PWM
                    out1 = PID_controller.calculate_output(detector.get_PID_params_02(0.5, 0.01, -0.05, 60), middle_point[1])
                    #spin
                    #out2 = PID_controller_2.calculate_output(detector.get_PID_params_02(0.6, 0.2, 0.09, 80), middle_point[0])
                    out2 = PID_controller_2.calculate_output(detector.get_PID_params_02(0.4, 0.3, 0.09, 80), middle_point[0])
                    #Area
                    #out3 = PID_controller_3.calculate_output(detector.get_PID_params_02(0.02, 0.01, 0.002, 3500), Area)
                    out3 = PID_controller_3.calculate_output(detector.get_PID_params_02(0.02, 0.01, 0.002, 2000), Area)
                    #傾きPID
                    #out4 = PID_controller_4.calculate_output(detector.get_PID_params_02(2.0, 0.0001, 0.0, 0), float(communicator.dataset_from_laz[0]))

                    
                
                    

                
                    #PIDなし制御
                    """
                    if 40 <= middle_point[0] <= 120:
                        spin = 128

                        
                        #面積によって前か後か
                        if 4000 <= Area <= 30000:
                            vectoring = 0
                                #なにもしない
                            
                        elif Area < 4000:
                            vectoring = -100
                                #前進
                        else:
                            vectoring = 100
                                #後退
                        print("vectoring ="+ str(vectoring))
                        
                        
                            #回転しなくてよい

                        
        
                    elif middle_point[0] < 40:
                        spin = 128+100
                            #左に回転
                    else:
                        spin = 128-100
                            #右に回転
                    print("Spin angle ="+ str(spin))

                    servo_R = spin + vectoring
                    servo_L = spin - vectoring
                    """

                    #前傾か後傾か
                    depth_R = 108 + out3
                    if depth_R > 185:
                        depth_R = 185
                    elif depth_R < 0:
                        depth_R = 0

                    print("depth_R ="+ str(depth_R))

                    depth_L =148 - out3
                    if depth_L > 255:
                        depth_L = 255
                    elif depth_L < 70:
                        depth_L = 70

                    print("depth_L ="+ str(depth_L))

                    #サーボの左右のずれ
                    spin_R = depth_R - out2
                    if spin_R > 255:
                        spin_R = 255
                    elif spin_R < 0:
                        spin_R = 0

                    spin_L = depth_L - out2
                    if spin_L > 255:
                        spin_L = 255
                    elif spin_L < 0:
                        spin_L = 0

                    servo_R = spin_R 
                    servo_L = spin_L

                    print("spin_R ="+ str(spin_R))
                    print("spin_L ="+ str(spin_L))



                   
                    
                    #ベクタリングPID 
                    """
                    spin = 128 - out2
                    if spin > 255:
                        spin = 255
                    elif spin < 0:
                        spin = 0
                    

                    servo_R = spin 
                    servo_L = spin 

                    print("spin ="+ str(spin))
                    """



                    #面積によってPID
                    """
                    depth_R = 108 + out3
                    if depth_R > 185:
                        depth_R = 185
                    elif depth_R < 0:
                        depth_R = 0

                    print("depth_R ="+ str(depth_R))

                    depth_L =148 - out3
                    if depth_L > 255:
                        depth_L = 255
                    elif depth_L < 70:
                        depth_L = 70

                    print("depth_L ="+ str(depth_L))

                    servo_R = depth_R
                    servo_L = depth_L
                    """



                

                    #羽ばたき周波数制御[PIDなし]
                    """""
                    if 160 <= middle_point[1] <= 320:
                        lift_power = 128
                        #ちょうどいいバタつき
                                
                    elif middle_point[1] < 160:
                        lift_power = 128+out1
                        if lift_power > 255:
                            lift_power = 255
                        #上昇
                    else:
                        lift_power = 128-out1
                        if lift_power < 0:
                            lift_power = 0
                        #下降
                    """""

                    
                

                    #羽ばたき周波数制御PID
                    
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

            else:
                #目標物を見失ってもPID計算の時間は更新しておく
                PID_controller.update_elapsed_time_from_last_step()
                PID_controller_2.update_elapsed_time_from_last_step()
                PID_controller_3.update_elapsed_time_from_last_step()





            #ジャイロセンサー値でPID
            """
            if out4 > 0 :
                LDC = pwm_def - out4
                RDC = pwm_def
                if LDC < 0 :
                    LDC = 0

            else :
                LDC = pwm_def
                RDC = pwm_def + out4
                if RDC < 0 :
                    RDC = 0 
            """       
            

            #LDC = 250
            #RDC = 250
            mode = 1
            


            output_values_to_laz[1] = RDC
            output_values_to_laz[2] = servo_L
            output_values_to_laz[3] = LDC
            output_values_to_laz[4] = mode
            output_values_to_laz[5] = servo_R
            print("output_values_to_laz = "+str(output_values_to_laz))
            print(".............")
            communicator.send_to_laz(output_values_to_laz) # ラズライトに値を送る関数

            cv2.imshow('red',frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break



f.close()
communicator.save_communicate_log()
communicator.serial_close()
print("Logging End. Serial closed")
            
capture.release()
cv2.destroyAllWindows()
