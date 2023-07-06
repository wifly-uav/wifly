import cv2

# VideoCapture オブジェクトを取得します
#esp_ip = "192.168.100.192" 
#esp_ip = "192.168.0.100"
esp_ip = "192.168.128.101"
capture = cv2.VideoCapture(f"rtsp://{esp_ip}:8554/mjpeg/1")
#capture = cv2.VideoCapture("rtsp://user:password@ip:port/ipcam_h264.sdp")
#capture = cv2.VideoCapture(1)
print("get image complete")

while(True):
    ret, frame = capture.read()
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()