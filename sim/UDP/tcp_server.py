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
x = 255
y = 50
while count<50:
    count = count + 1
    print("count:"+str(count))


    s = f'{x:03}{y:03}'
    s_l = s.encode("utf-8")
    
    sock.send(s_l)
    for i in range(800):
        re = sock.recv(1024)
        #time.sleep(0.0001)
    print("send"+str(len(s_l))+":"+str(s_l))

    #re = sock.recv(1024)
    re_ = re.decode('utf-8')
    print("receive"+":"+str(re_))
    time.sleep(0.1)
    y += 1

sock.close()