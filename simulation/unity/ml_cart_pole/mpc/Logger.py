import csv
import datetime
class logger():
    def __init__(self):
        self.log = [["roll"], ["pitch"], ["yaw"], ["height"]]

    def add_log_state_and_action(self, state, sent_param):
        row = state
        #row.extend(sent_param)
        self.log.append(row)

    def add_log(self, row):
        self.log.append(row)

    def output_log(self):
        with open('log_{0:%H%M%S}'.format(datetime.datetime.now()) + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.log)
            f.close()