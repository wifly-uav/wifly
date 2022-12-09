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
        files = glob.glob(self.folder + data_name + "_" + "?")
        files_test = glob.glob(self.folder + data_name + "*" +"test_" + "?")
        files_test_0 = glob.glob(self.folder + data_name + "*" +"test_0_" + "?")
        self.train_data = [[0]*2 for i in range(len(files))]
        self.test_data = [[0]*2 for i in range(len(files_test))]
        self.test_0_data = [[0]*2 for i in range(len(files_test_0))]
        j = 0
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
        for i in files_test:
            name = i+"/log.csv"
            name = name.replace(os.sep,'/')
            name2 = i+"/log2.csv"
            name2 = name2.replace(os.sep,'/')
            #self.test_data[j][0] = np.loadtxt(name, delimiter=',', usecols=[-2])
            self.test_data[j][1] = np.loadtxt(name2, delimiter=',', usecols=[0])
            self.test_data[j][0] = np.array([30.0/len(self.test_data[j][1])]*len(self.test_data[j][1]))
            self.test_data[j][0] = self.test_data[j][0].cumsum(dtype=float)
            j += 1
        j = 0
        for i in files_test_0:
            name = i+"/log.csv"
            name = name.replace(os.sep,'/')
            name2 = i+"/log2.csv"
            name2 = name2.replace(os.sep,'/')
            #self.test_0_data[j][0] = np.loadtxt(name, delimiter=',', usecols=[-2])
            self.test_0_data[j][1] = np.loadtxt(name2, delimiter=',', usecols=[0])
            self.test_0_data[j][0] = np.array([30.0/len(self.test_0_data[j][1])]*len(self.test_0_data[j][1]))
            self.test_0_data[j][0] = self.test_0_data[j][0].cumsum(dtype=float)
            j += 1

    def complement(self, mode='linear'):
        # 補間関数を作成
        self.train_data_comp = [[0]*2 for i in range(len(self.train_data))]
        self.test_data_comp = [[0]*2 for i in range(len(self.test_data))]
        self.test_0_data_comp = [[0]*2 for i in range(len(self.test_0_data))]
        num = 750
        t_resample = np.linspace(0, 30.0, num)
        for i in range(len(self.train_data)):
            f = interpolate.interp1d(self.train_data[i][0], self.train_data[i][1], kind=mode, fill_value="extrapolate")
            self.train_data_comp[i][1] = f(t_resample)
            self.train_data_comp[i][0] = np.array([30.0/num]*len(self.train_data_comp[i][1]))
            self.train_data_comp[i][0] = self.train_data_comp[i][0].cumsum(dtype=float)
        for i in range(len(self.test_data)):
            f = interpolate.interp1d(self.test_data[i][0], self.test_data[i][1], kind=mode, fill_value="extrapolate")
            self.test_data_comp[i][1] = f(t_resample)
            self.test_data_comp[i][0] = np.array([30.0/num]*len(self.test_data_comp[i][1]))
            self.test_data_comp[i][0] = self.test_data_comp[i][0].cumsum(dtype=float)
        for i in range(len(self.test_0_data)):
            f = interpolate.interp1d(self.test_0_data[i][0], self.test_0_data[i][1], kind=mode, fill_value="extrapolate")
            self.test_0_data_comp[i][1] = f(t_resample)
            self.test_0_data_comp[i][0] = np.array([30.0/num]*len(self.test_0_data_comp[i][1]))
            self.test_0_data_comp[i][0] = self.test_0_data_comp[i][0].cumsum(dtype=float)

    def max_min(self):
        self.train_data_max = copy.copy(self.train_data_comp[0][1])
        self.train_data_min = copy.copy(self.train_data_comp[0][1])
        self.test_data_max = copy.copy(self.test_data_comp[0][1])
        self.test_data_min = copy.copy(self.test_data_comp[0][1])
        self.test_0_data_max = copy.copy(self.test_0_data_comp[0][1])
        self.test_0_data_min = copy.copy(self.test_0_data_comp[0][1])
        for i in range(750):
            for j in range(len(self.train_data_comp)):
                self.train_data_max[i] = max(self.train_data_max[i],self.train_data_comp[j][1][i])
                self.train_data_min[i] = min(self.train_data_min[i],self.train_data_comp[j][1][i])
        for i in range(750):
            for j in range(len(self.test_data_comp)):
                self.test_data_max[i] = max(self.test_data_max[i],self.test_data_comp[j][1][i])
                self.test_data_min[i] = min(self.test_data_min[i],self.test_data_comp[j][1][i])
        for i in range(750):
            for j in range(len(self.test_0_data_comp)):
                self.test_0_data_max[i] = max(self.test_0_data_max[i],self.test_0_data_comp[j][1][i])
                self.test_0_data_min[i] = min(self.test_0_data_min[i],self.test_0_data_comp[j][1][i])

    def visualize(self):
        fig = plt.figure()
        ax = fig.add_subplot(111)
        #for i in range(len(self.train_data)):
            #ax.plot(self.train_data[i][0],self.train_data[i][1])
            #ax.plot(self.train_data_comp[i][0],self.train_data_comp[i][1])
        ax.fill_between(self.test_data_comp[0][0],self.test_data_max,self.test_data_min, alpha=0.3)
        ax.plot(self.test_data[-1][0],self.test_data[-1][1])
        plt.show()

if __name__ == "__main__":
    path = os.path.dirname(__file__)
    
    print("Which data?")
    data_name  = input()
    ac = visual_angle_act(folder=path + '/result/syuron/', data_name=data_name)
    ac.load()
    ac.complement()
    ac.max_min()
    ac.visualize()