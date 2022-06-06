import cv2

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

esp_ip = "192.168.137.49"
vcap = cv2.VideoCapture(f"rtsp://{esp_ip}:8554/mjpeg/1")

while True:
    ret, frame = vcap.read()
    cv2.imshow("Frame", frame)
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break

vcap.release()
cv2.destroyAllWindows()
