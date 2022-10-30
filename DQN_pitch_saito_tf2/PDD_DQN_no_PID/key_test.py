import msvcrt
import time
import sys
import serial
import time
import serial.tools.list_ports

while True:
    if msvcrt.kbhit():
        key = msvcrt.getch()
        if key == 't'.encode('utf-8'):
            print("t")
        elif key == 'y'.encode('utf-8'):
            print("y")
print("finish")