import csv
import datetime
import copy
import matplotlib.pyplot as plt

import statistics

import os
from graph import Graph

class logger():
    def __init__(self, folder='log'):
        self.log = []
        self.log2 = []
        self.path = os.path.dirname(__file__)
        self.folder = folder
        ##self.log = [["pitch,yaw,slope,roll"]]

    def add_log_state_and_action(self, state, action, sent_param, time, time2):
        state_list = list(state)
        row = [state_list, action, sent_param[3], sent_param[1], time, time2]
        """
        row = copy.copy(state)
        row.extend(sent_param)
        #print(time)
        ti = [time]
        row.extend(ti)
        """
        self.log.append(row)

    def add_log(self, row):
        self.log.append(row)

    def add_log_state(self, state, reward, time):
        state_list_ = list(state)
        row_ = [state_list_[0][0],state_list_[0][-2],reward,time]
        self.log2.append(row_)

    def output_log(self):
        with open(self.folder + '/log.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log)
            f.close()
        with open(self.folder + '/log2.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log2)
            f.close()

    def loss_graph(self, loss):
        plt.plot(loss)
        plt.ylim(0,64)
        plt.title("LOSS",fontsize=25)
        plt.savefig(self.folder + '/loss.png')
        plt.show()

    def angle_graph(self):
        angle = []
        time_ = []
        for i in self.log2:
            angle.append(int(i[0]))
            time_.append(int(i[2]))
        
        med = statistics.median(time_)
        sum = 0
        time = []

        for i in time_:
            if i < 0:
                i = med
            if i > 200:
                i = med
            sum += i
            time.append(sum/1000)
                
        plt.plot(time,angle)
        plt.ylim(-90,90)
        plt.plot([0, time[-1]],[10, 10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[-10, -10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[0, 0], "black")
        plt.title("ANGLE",fontsize=25)
        plt.savefig(self.folder + '/angle.png')
        plt.show()