import csv
import datetime
import copy

class logger():
    def __init__(self):
        self.log = [["pitch"], ["yaw"], ["slope"], ["roll"]]
        ##self.log = [["pitch,yaw,slope,roll"]]

    def add_log_state_and_action(self, state, sent_param, time):
        row = copy.copy(state)
        row.extend(sent_param)
        #print(time)
        ti = [time]
        row.extend(ti)
        self.log.append(row)

    def add_log(self, row):
        self.log.append(row)

    def output_log(self):
        with open('log/log_{0:%H%M%S}'.format(datetime.datetime.now()) + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log)
            f.close()