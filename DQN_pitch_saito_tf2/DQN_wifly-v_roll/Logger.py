import csv
import datetime
import copy
import matplotlib.pyplot as plt
import numpy as np
import statistics
import datetime as dt
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
        
        #要修正(env.default_paramsを修正→sent_paramの添え字を修正の流れ！！！)
        #row:[4フレームを1セットとした状態,行動番号,羽ばたき出力1,羽ばたき出力2,受信間隔(機体計測), 受信間隔(PC計測)]
        row = [state_list, action, sent_param[1], sent_param[2], time, time2]
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

        #row_ = [state_list_[0][1],state_list_[0][-2],reward,time]
        
        #row_:[Roll角,報酬,時間]
        row_ = [state_list_[0][2],reward,time]
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

    def loss_graph_2(self,x,loss):
        fig = plt.figure()                                    #白紙のグラフの作成
        #1つのグラフを作成
        ax = fig.add_subplot(111)
        N = len(loss)                                       #累計ステップ数
        running_avg = np.empty(N)                           #移動平均を格納するarray
        for t in range(N):
            #t個目のプロットは、その前10個分のlossの平均値（移動平均）
            running_avg[t] = np.mean(loss[max(0, t-10):(t+1)])

        ax.plot(x, running_avg, label = "Loss" ,color="C3")     #lossの移動平均をプロット
        ax.set_xlabel("Step")
        ax.set_ylabel("Loss")
        ax.tick_params(axis = "x",direction = "in")
        ax.tick_params(axis = "y",direction = "in")
        plt.savefig(self.folder + '/loss.png')
        plt.show()

        """
        now = dt.datetime.now()             #年月日時間を取得
        now_str = now.strftime('%m%d%H%M')  #月日時間の文字列（ex.07042244）
        filename_dt = filename + now_str + ".png"
        fig.savefig(filename_dt,bbox_inches = "tight")
        """

    def angle_graph(self):
        angle = []
        time_ = []
        for i in self.log2:
            angle.append(int(i[0]))
            time_.append(int(i[-2]))
        
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
        #plt.ylim(-90,90)
        plt.plot([0, time[-1]],[10, 10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[-10, -10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[0, 0], "black")
        plt.title("ANGLE",fontsize = 25)
        plt.savefig(self.folder + '/angle.png')
        plt.show()

    def angle_graph_2(self, x, lst_angle):
        fig = plt.figure()                                              #白紙のグラフの作成
        #1つのグラフを作成
        ax = fig.add_subplot(111)
        ax.plot(x, lst_angle, label = "Roll angle" ,color="C3")        #lossの移動平均をプロット
        ax.set_xlabel("Step")
        ax.set_ylabel("Roll angle")
        ax.tick_params(axis = "x",direction = "in")
        ax.tick_params(axis = "y",direction = "in")
        plt.savefig(self.folder + '/Roll.png')
        plt.show()