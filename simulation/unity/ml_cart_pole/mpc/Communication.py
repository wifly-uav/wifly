#-------------------------------------------------------------#
# module for communication to Lazurite (or Arduino) vie serial#
#-------------------------------------------------------------#

import serial
import time
import random as rd

default_params = [255, 0, 0, 0, 0]

class Communicator():
    # load serial port number for controller and terminal switch
    def __init__(self):
        print('Input port number to controller:')
        self.__ser = serial.Serial(port='COM' + str(input()), baudrate=115200, timeout=1) #change according to the COM port connected to Lazrite
        time.sleep(0.5)
        self.__fail_counter = 0
        self.__test_count = 0
        self.__data_sent = None
        self.__raw_data = ""

        print('Input port number to terminal switch:')
        self.ser_terminal = serial.Serial(port='COM' + str(input()), baudrate=115200, timeout=1)  # change according to the COM port connected to Lazrite

    # flush serial IO buffer of the controller
    def flush_IO_laz(self):
        self.__ser.flushInput()
        self.__ser.flushOutput()


    def perse_raw_data(self):
        persed_data = [float(i) for i in self.__raw_data.split(",")[1:-1]]
        return persed_data #order : pitch, yaw, slope, roll

    # recieve data from controller
    # after 20 times of communication error, return False
    def recieve_from_laz(self):
        while True:
            if self.__ser.in_waiting > 0:
                self.__raw_data =self.__ser.readline().decode('utf-8')
                split_data = self.__raw_data.split(",")
                if (split_data[0] != "STX" or split_data[-1][0] != "E"): # Error check
                    # If the data is not complete, flush Input buffer and send the same data as last transmission
                    time.sleep(0.005)
                    self.__ser.flushInput()
                    self.send_to_laz(self.__data_sent)
                    self.__fail_counter += 1
                else:
                    self.__ser.flushInput()
                    self.__fail_counter = 0
                    return True
            elif self.__fail_counter > 10:
                self.send_to_laz(self.__data_sent)
            elif self.__fail_counter > 20:
                print("data receive timeout error!")
                return False
            else:
                self.__fail_counter += 1
                time.sleep(0.005)


    def send_to_laz(self, data_to_send):
        for datum in data_to_send:
            self.__ser.write(bytes([int(datum)]))
        print("SENT{0}".format(data_to_send))
        self.__data_sent = data_to_send
        time.sleep(0.001)


    # return True when the button is pushed
    def termination_switch(self):
        self.ser_terminal.flushInput()
        flag_termination = self.ser_terminal.readline().decode('utf-8')
        if flag_termination[0] == "1":
            while True:
                ##通信失敗時に送られる値
                self.send_to_laz(default_params)
                time.sleep(0.001)
                flag_termination = self.ser_terminal.readline().decode('utf-8')
                if flag_termination[0] == "0":
                    return True
        else:
            return False


    def serial_close(self):
        self.__ser.close()
        self.ser_terminal.close()


"""
#------------------------TEST CODE -----------------------------------
    def communication_test(self):
        while(True):
            if (self.send_to_laz_random() is False):
                exit()

    def send_to_laz_random(self):
        while(self.__ser.in_waiting > 0):
            print(self.__ser.readline().decode('utf-8'))

        self.__ser.flushInput()

        while True:
            if self.__test_count < 4:
                data_to_send = [255, 0, 0, 0]
            else:
                data_to_send = [255, 128, 0, rd.randint(30, 250)]

            self.send_to_laz(data_to_send)
            time.sleep(0.005)
            self.__test_count += 1
            print(self.__ser.readline().decode('utf-8'))
            time.sleep(0.005)
"""