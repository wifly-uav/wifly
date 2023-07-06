import cv2  # オープンCVをインポートして利用可能
import numpy as np
import time
import csv

KEY_PID = ["P", "I", "D", "target"]

class Detector():
    def __init__(self):
        self.middle_point = []  # middle_point(中間点←なんの?)に値を代入するための空のリストを作成
        


    def find_rect_of_target_color(self,image):
        hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV_FULL)
        h = hsv[:, :, 0]
        s = hsv[:, :, 1]
        mask = np.zeros(h.shape, dtype=np.uint8)
        #インカメラ用
        #mask[((h < 5) | (h > 200)) & (s > 125)] = 255
        #Webカメラ用
        #mask[((h < 5) | (h > 200)) & (s > 128)] = 255
        #ESP32-cam用
        mask[((h < 5) | (h > 200)) & (s > 50)] = 255
        contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        rects = []
        for contour in contours:
            approx = cv2.convexHull(contour)
            rect = cv2.boundingRect(approx)
            rects.append(np.array(rect))
        return rects

    def get_PID_params(self):
        params = [0.5, 0, -0.05, 0]      #for slope control    P=0.5 I=0.02 D=-0.05 T=0 H tail
        #params = [0.8, 0.05, -0.1, 0]        #for pitch control
        #params = [0.7, 0.02, -0.1, 0]    #for pitch control  double P=0.7 I=0 D=-0.1 T=0 free s 動画 つった状態  重り
        #self.__ser_PID_parm.flushInput()
        #params = self.__ser_PID_parm.readline().decode('utf-8').split(",")
        params = [float(i) for i in params]     #リスト内包表記 上記で設定したparamsの値をfloat型に変換
        return dict(zip(KEY_PID, params))       #zip():複数のリストをまとめる　dict():辞書を作成する

    def get_PID_params_02(self, a, b, c, d):#それぞれパラメータを変えられるようにした
        params = [a, b, c, d]      #for slope control    P=0.5 I=0.02 D=-0.05 T=0 H tail
        #params = [0.8, 0.05, -0.1, 0]        #for pitch control
        #params = [0.7, 0.02, -0.1, 0]    #for pitch control  double P=0.7 I=0 D=-0.1 T=0 free s 動画 つった状態  重り
        #self.__ser_PID_parm.flushInput()
        #params = self.__ser_PID_parm.readline().decode('utf-8').split(",")
        params = [float(i) for i in params]     #リスト内包表記 上記で設定したparamsの値をfloat型に変換
        return dict(zip(KEY_PID, params))       #zip():複数のリストをまとめる　dict():辞書を作成する


#------------------------TEST CODE -----------------------------------    
if __name__ == "__main__":
    detector = Detector()
    #esp_ip = "192.168.100.192"
    #esp_ip = "192.168.128.100"
    #capture = cv2.VideoCapture(f"rtsp://{esp_ip}:8554/mjpeg/1")
    print("capture completed")
    capture = cv2.VideoCapture(1)
    print(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
    print(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))

    old_time = time.time()

    with open('PID_result_test.csv','w', newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["now_time","middle_point[0]"])
    
        
    while (capture.isOpened()):
        _, frame = capture.read()
        #cv2.imshow('red',frame)
        rects = detector.find_rect_of_target_color(frame)
        #print(rects)
        if len(rects) > 0:
            rect = max(rects, key=(lambda x: x[2] * x[3]))
            print(rect)
            if rect[2] > 22 and rect[3] > 22:
                middle_point = []
                middle_point.append(rect[0]+(rect[2]/2)) 
                middle_point.append(rect[1]+(rect[3]/2))
                
            
                    
                print("Area="+ str(rect[2]*rect[3]))
                print("middle_point="+str(rect[0]+(rect[2]/2))+","+str(rect[1]+(rect[3]/2)))

                now_time = time.time() - old_time
                print("now_time = "+str(now_time))

                #CSVファイルに出力（時間と中点座標）
                with open('PID_result_test.csv','a', newline="") as f:
                    writer = csv.writer(f)
                    writer.writerow([str(now_time),str(middle_point[0])])
                

                cv2.rectangle(frame, tuple(rect[0:2]), tuple(rect[0:2] + rect[2:4]), (0, 0, 255), thickness=2)

                #インカメラ用
                """
                if 280 <= middle_point[0] <= 360:
                    spin = 0
                        #回転しなくてよい
                        
                elif middle_point[0] < 280:
                    spin = 128+50
                        #左に回転
                else:
                    spin = 128-50
                        #右に回転
                print("Spin angle ="+ str(spin))
                """

                #ESP32-cam用
                if 100 <= middle_point[0] <= 220:
                    spin = 0
                        #回転しなくてよい
                        
                elif middle_point[0] < 100:
                    spin = 128+50
                        #左に回転
                else:
                    spin = 128-50
                        #右に回転
                print("Spin angle ="+ str(spin))
            

        cv2.imshow('red', frame)
            
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


     
    f.close()
    capture.release()
    cv2.destroyAllWindows()