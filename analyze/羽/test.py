import cv2
import os
import numpy as np
import math
import csv
import copy


video_path = "wing2_trim.mp4"

path = os.path.dirname(__file__)
video_file = os.path.join(path, video_path)


i = 0      # カウント変数
th = 30    # 差分画像の閾値

# 動画ファイルのキャプチャ
cap = cv2.VideoCapture(video_file)

width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = int(cap.get(cv2.CAP_PROP_FPS))
print(f"size: ({width}, {height}), fps: {fps}")

fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, fps, (width,height),isColor=False)

# 最初のフレームを背景画像に設定
ret, bg = cap.read()

# HSV変換
bg = cv2.cvtColor(bg, cv2.COLOR_BGR2HSV)

while(cap.isOpened()):
    # フレームの取得
    ret, frame = cap.read()
    if ret==True:

        #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        cv2.imshow("frame_hsv", hsv)

        bgrLower = np.array([0, 0, 0])    # 抽出する色の下限(HSV)
        bgrUpper = np.array([255, 100, 100])    # 抽出する色の上限(HSV)
        img_mask = cv2.inRange(hsv, bgrLower, bgrUpper) # hsvからマスクを作成    
        cv2.imshow("frame_mask", img_mask)

        frame_ext = cv2.bitwise_and(hsv, hsv, mask=img_mask) # 元画像とマスクを合成
        frame_bgr = cv2.cvtColor(frame_ext, cv2.COLOR_HSV2BGR)
        cv2.imshow("frame_bgr", frame_bgr)

        # 差分の絶対値を計算
        #mask = cv2.absdiff(gray, bg)

        # 差分画像を二値化してマスク画像を算出
        #mask[mask < th] = 0
        #mask[mask >= th] = 255

        # フレームとマスク画像を表示
        #cv2.imshow("Mask", mask)
        #cv2.imshow("Flame", gray)
        #cv2.imshow("Background", bg)

        
        out.write(img_mask)

        i += 1    # カウントを1増やす

        '''
        # 背景画像の更新（一定間隔）
        if(i > 1):
            ret, bg = cap.read()
            bg = cv2.cvtColor(bg, cv2.COLOR_BGR2GRAY)
            i = 0  # カウント変数の初期化
        '''

        # qキーが押されたら途中終了
        if cv2.waitKey(0) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
out.release()
cv2.destroyAllWindows()