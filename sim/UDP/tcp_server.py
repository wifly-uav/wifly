import socket
import json
import struct
import numpy as np
import time
import matlab.engine

eng = matlab.engine.start_matlab()
#eng.open_system('com_test')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1',9999))
s.listen(1)
print('waiting for connection...')
#eng.sym('com_test')
#time.sleep(1)
sock, addr = s.accept()
print('connected!')

count = 0
while count<50:
    count = count + 1
    print("count:"+str(count))

    signal = [5,1]
    s = str(signal)
    s_ = s.strip("[""]")
    s_l = s_.encode("utf-8")
    sock.send(s_l)
    print("send"+str(len(s_l))+":"+str(s_l))

    re = sock.recv(1024)
    re_ = re.decode('utf-8')
    print("receive"+str(len(re_))+":"+str(re_))
    time.sleep(1)

sock.close()