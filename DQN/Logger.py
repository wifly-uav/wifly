import csv
import datetime
import copy

import os
from graph import Graph

class logger():
    def __init__(self, flag==True):
        self.log = [["pitch"], ["yaw"], ["left"], ["right"]]
        self.log2 = []
        self.path = os.path.dirname(__file__)
        self.flag = flag
        ##self.log = [["pitch,yaw,slope,roll"]]

    def add_log_state_and_action(self, state, action, sent_param, time, time2):
        state_list = list(state)
        row = [state_list[0], state_list[1], state_list[2], action, sent_param[3], sent_param[1], time, time2]
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
        row_ = [state_list_[0][0],reward,time]
        self.log2.append(row_)

    def output_log(self):
        name = '{0:%H%M%S}'.format(datetime.datetime.now())
        with open(os.path.join(self.path, 'log/log_'+ name + ".csv"), 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log)
            f.close()
        with open(os.path.join(self.path, 'log/log2_'+ name + ".csv"), 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log2)
            f.close()
        if self.flag:
            self.gra = Graph(file='log/debug_loss.csv', file2='log/log2_' + name + '.csv')
            self.gra.graph()