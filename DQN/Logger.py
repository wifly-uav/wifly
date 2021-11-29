import csv
import datetime
import copy

import os

class logger():
    def __init__(self):
        self.log = [["pitch"], ["yaw"], ["left"], ["right"]]
        self.log2 = []
        self.path = os.path.dirname(__file__)
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
        with open(os.path.join(self.path, 'log/log_{0:%H%M%S}'.format(datetime.datetime.now()) + ".csv"), 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log)
            f.close()
        with open(os.path.join(self.path, 'log/log2_{0:%H%M%S}'.format(datetime.datetime.now()) + ".csv"), 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log2)
            f.close()