import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import os
import statistics
from PIL import Image, ImageDraw, ImageFont
import math
import glob
import itertools
import operator
from scipy import interpolate
import copy

class visual_angle_act:
    def __init__(self, folder='log', data_name=None):
        self.folder = folder
        self.name = data_name

    def load(self):
        files = glob.glob(self.folder + self.name + "_" + "?")
        files_test = glob.glob(self.folder + self.name + "*" +"test_" + "?")
        files_test_0 = glob.glob(self.folder + self.name + "*" +"test_0_" + "?")
        self.train_data = [[0]*2 for i in range(len(files))]
        self.test_data = [[0]*2 for i in range(len(files_test))]
        self.test_0_data = [[0]*2 for i in range(len(files_test_0))]
        self.test_0_reward_data = [[0]*2 for i in range(len(files_test_0))]
        j = 0
        print(self.folder+self.name)
        for i in files:
            name = i+"/log.csv"
            name = name.replace(os.sep,'/')
            name2 = i+"/log2.csv"
            name2 = name2.replace(os.sep,'/')
            #self.train_data[j][0] = np.loadtxt(name, delimiter=',', usecols=[-2])
            self.train_data[j][1] = np.loadtxt(name2, delimiter=',', usecols=[0])
            self.train_data[j][0] = np.array([30.0/len(self.train_data[j][1])]*len(self.train_data[j][1]))
            self.train_data[j][0] = self.train_data[j][0].cumsum(dtype=float)
            j += 1
        j = 0
        for i in files_test_0:
            name = i+"/log.csv"
            name = name.replace(os.sep,'/')
            name2 = i+"/log2.csv"
            name2 = name2.replace(os.sep,'/')
            #self.test_0_data[j][0] = np.loadtxt(name, delimiter=',', usecols=[-2])
            self.test_0_data[j][1] = np.loadtxt(name2, delimiter=',', usecols=[0])
            self.test_0_reward_data[j][1] = abs(self.test_0_data[j][1])/90
            self.test_0_reward_data[j][1] = self.test_0_reward_data[j][1].cumsum(dtype=float)
            self.test_0_data[j][0] = np.array([30.0/len(self.test_0_data[j][1])]*len(self.test_0_data[j][1]))
            self.test_0_data[j][0] = self.test_0_data[j][0].cumsum(dtype=float)
            self.test_0_reward_data[j][0] = self.test_0_data[j][0]
            j += 1
        print(len(self.test_0_data[0][1]))

    def complement(self, mode='linear'):
        # 補間関数を作成
        self.train_data_comp = [[0]*2 for i in range(len(self.train_data))]
        self.test_data_comp = [[0]*2 for i in range(len(self.test_data))]
        self.test_0_data_comp = [[0]*2 for i in range(len(self.test_0_data))]
        self.test_0_reward_data_comp = [[0]*2 for i in range(len(self.test_0_data))]
        num = 750
        t_resample = np.linspace(0, 30.0, num)
        for i in range(len(self.train_data)):
            f = interpolate.interp1d(self.train_data[i][0], self.train_data[i][1], kind=mode, fill_value="extrapolate")
            self.train_data_comp[i][1] = f(t_resample)
            self.train_data_comp[i][0] = np.array([30.0/num]*len(self.train_data_comp[i][1]))
            self.train_data_comp[i][0] = self.train_data_comp[i][0].cumsum(dtype=float)
        for i in range(len(self.test_0_reward_data)):
            f = interpolate.interp1d(self.test_0_reward_data[i][0], self.test_0_reward_data[i][1], kind=mode, fill_value="extrapolate")
            self.test_0_reward_data_comp[i][1] = f(t_resample)*0.04
            self.test_0_reward_data_comp[i][0] = np.array([30.0/num]*len(self.test_0_reward_data_comp[i][1]))
            self.test_0_reward_data_comp[i][0] = self.test_0_reward_data_comp[i][0].cumsum(dtype=float)
        for i in range(len(self.test_0_data)):
            f = interpolate.interp1d(self.test_0_data[i][0], self.test_0_data[i][1], kind=mode, fill_value="extrapolate")
            self.test_0_data_comp[i][1] = f(t_resample)
            self.test_0_data_comp[i][0] = np.array([30.0/num]*len(self.test_0_data_comp[i][1]))
            self.test_0_data_comp[i][0] = self.test_0_data_comp[i][0].cumsum(dtype=float)

    def max_min(self):
        self.train_data_max = copy.copy(self.train_data_comp[0][1])
        self.train_data_min = copy.copy(self.train_data_comp[0][1]) 
        self.test_0_reward_data_max = copy.copy(self.test_0_reward_data_comp[0][1])
        self.test_0_reward_data_min = copy.copy(self.test_0_reward_data_comp[0][1])
        self.test_0_data_max = copy.copy(self.test_0_data_comp[0][1])
        self.test_0_data_min = copy.copy(self.test_0_data_comp[0][1])
        for i in range(750):
            for j in range(len(self.train_data_comp)):
                self.train_data_max[i] = max(self.train_data_max[i],self.train_data_comp[j][1][i])
                self.train_data_min[i] = min(self.train_data_min[i],self.train_data_comp[j][1][i])
        for i in range(750):
            for j in range(len(self.test_0_reward_data_comp)):
                self.test_0_reward_data_max[i] = max(self.test_0_reward_data_max[i],self.test_0_reward_data_comp[j][1][i])
                self.test_0_reward_data_min[i] = min(self.test_0_reward_data_min[i],self.test_0_reward_data_comp[j][1][i])
        for i in range(750):
            for j in range(len(self.test_0_data_comp)):
                self.test_0_data_max[i] = max(self.test_0_data_max[i],self.test_0_data_comp[j][1][i])
                self.test_0_data_min[i] = min(self.test_0_data_min[i],self.test_0_data_comp[j][1][i])

    def comp_data(self, mode=1):
        if mode:
            return self.test_0_data_comp,self.test_0_data,self.test_0_data_max,self.test_0_data_min
        else:
            return self.test_0_reward_data_comp,self.test_0_reward_data,self.test_0_reward_data_max,self.test_0_reward_data_min

    def comp(self):
        self.load()
        self.complement()
        self.max_min()

    def visualize(self):
        target = []
        #for i in self.test_data_comp[0][0]:
        #    target.append(int(20*math.sin(0.1*i*2*math.pi)))
        fig = plt.figure()
        """
        ax = fig.add_subplot(111)
        ax.fill_between(self.train_data_comp[0][0],self.train_data_max,self.train_data_min, alpha=0.3)
        ax.plot(self.train_data[-1][0],self.train_data[-1][1])
        ax.plot(self.train_data_comp[0][0],target)
        """
        #"""
        bx = fig.add_subplot(111)
        #bx.set_ylim([-100,100])
        bx.fill_between(self.test_0_reward_data_comp[0][0],self.test_0_reward_data_max,self.test_0_reward_data_min, color='r',alpha=0.3)
        bx.plot(self.test_0_reward_data[-1][0],self.test_0_reward_data[-1][1], color='r')
        print(self.test_0_reward_data[-1][1][-1])
        #"""
        """
        cx = fig.add_subplot(111)
        cx.set_ylim([-100,60])
        cx.fill_between(self.test_0_data_comp[0][0],self.test_0_data_max,self.test_0_data_min, alpha=0.3)
        cx.plot(self.test_0_data[-1][0],self.test_0_data[-1][1])
        cx.plot([0, self.test_0_data[-1][0][-1]],[0, 0])
        """

        plt.savefig(self.folder + 'data/' + self.name + '_reward.png')
        #plt.show()

if __name__ == "__main__":
    path = os.path.dirname(__file__)
    mode = 1
    
    print("Which data?")
    #data_name  = input()
    #ac = visual_angle_act(folder=path + '/result/syuron/', data_name=data_name)
    ac = visual_angle_act(folder=path + '/result/syuron/', data_name='1209_n')
    ac.comp()
    n_comp, n_test, n_max, n_min = ac.comp_data(mode=mode)
    #ac.visualize()
    ac_con = visual_angle_act(folder=path + '/result/syuron/', data_name='1215_con')
    ac_con.comp()
    con_comp, con_test, con_max, con_min = ac_con.comp_data(mode=mode)
    
    ac_nei = visual_angle_act(folder=path + '/result/syuron/', data_name='1208_nei')
    ac_nei.comp()
    nei_comp, nei_test, nei_max, nei_min = ac_nei.comp_data(mode=mode)

    ac_pre = visual_angle_act(folder=path + '/result/syuron/', data_name='1208_pre')
    ac_pre.comp()
    pre_comp, pre_test, pre_max, pre_min = ac_pre.comp_data(mode=mode)

    ac_beta = visual_angle_act(folder=path + '/result/syuron/', data_name='1209_ls')
    ac_beta.comp()
    beta_comp, beta_test, beta_max, beta_min = ac_beta.comp_data(mode=mode)

    ac_mix = visual_angle_act(folder=path + '/result/syuron/', data_name='23_conprebeta')
    ac_mix.comp()
    mix_comp, mix_test, mix_max, mix_min = ac_nei.comp_data(mode=mode)

    fig = plt.figure()
    ax = fig.add_subplot(111)
    if mode==2:
        ax.plot(n_comp[0][0],n_max-n_min, color='b',alpha=0.6)
        #ax.plot(con_comp[0][0],con_max-con_min, color='g',alpha=0.6)
        #ax.plot(pre_comp[0][0],pre_max-pre_min, color='r',alpha=0.6)
        #ax.plot(nei_comp[0][0],nei_max-nei_min, color='m',alpha=0.6)
        ax.plot(beta_comp[0][0],beta_max-beta_min, color='darkorange',alpha=0.6)
        #ax.plot(mix_comp[0][0],mix_max-mix_min, color='c')
        print(np.mean(n_max-n_min))
        print(np.mean(con_max-con_min))
        print(np.mean(pre_max-pre_min))
        print(np.mean(nei_max-nei_min))
        print(np.mean(beta_max-beta_min))

    else:
        ax.fill_between(n_comp[0][0],n_max,n_min, color='orangered',alpha=0.7)
        ax.fill_between(con_comp[0][0],con_max,con_min, color='b',alpha=0.5)
        #ax.fill_between(pre_comp[0][0],pre_max,pre_min, color='r',alpha=0.3)
        #ax.fill_between(nei_comp[0][0],nei_max,nei_min, color='m',alpha=0.3)
        #ax.fill_between(beta_comp[0][0],beta_max,beta_min, color='r',alpha=0.3)
        #ax.fill_between(mix_comp[0][0],mix_max,mix_min, color='c',alpha=0.3)

    ax.set_xticks([0,5,10,15,20,25,30])
    plt.xlabel("時間[s]", fontname="MS Gothic", fontsize=18)
    if mode==2:
        plt.ylabel("最大角度差[deg]", fontname="MS Gothic", fontsize=18)
        ax.legend(["先行研究","LSTM"], prop={"family":"MS Gothic","size":12}, loc='upper right')
    elif mode:
        plt.ylabel("角度[deg]", fontname="MS Gothic", fontsize=18)
        ax.legend(["先行研究","提案手法"], prop={"family":"MS Gothic","size":12}, loc='upper right')
        ax.plot([0, n_comp[-1][0][-1]],[0, 0], color='r')
    else:
        plt.ylabel("累積偏差[deg・s]", fontname="MS Gothic", fontsize=18)
        #ax.legend(["先行研究","提案手法"], prop={"family":"MS Gothic","size":12}, loc='upper left')
        #ax.legend(["先行研究","潜在変数","報酬予測","報酬近似","ベータ分布","MIX"], prop={"family":"MS Gothic","size":12}, loc='upper left')
    plt.rcParams["font.size"] = 18
    plt.tick_params(labelsize=18)
    plt.tight_layout()
    plt.show()