import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import csv
import collections

class visual_minibach():

    def __init__(self, flag=False, folder='log'):
        self.flag = flag
        self.folder = folder

        self.n = []
        self.min = []
        self.minibatch = []

    def visualize(self):

        self.m = np.loadtxt(self.folder + '/debug_minibatch.csv', delimiter=',')
        #print(list(min))
        for i in list(self.m):
            if i != -1.0:
                self.n.append(i)
                self.minibatch.append(i)
            else:
                self.min.append(self.n)
                self.n = []
        #minibatch[何回目の学習][replay_memoryの何番目を参照したか]

        frame = []
        number = []

        for i in range(len(self.min)):
            for j in range(len(self.min[i])):
                frame.append(i)
                number.append(self.min[i][j])

        fig_3 = plt.figure()

        ax_3 = fig_3.add_subplot(1,1,1)

        ax_3.scatter(frame,number,s=10)

        ax_3.set_title('learning minibach index')
        ax_3.set_xlabel('learning times')
        ax_3.set_ylabel('minibach index')

        plt.ylim([0,2500])
        if self.flag:
            plt.show()
        plt.savefig(self.folder + '/minibach.jpg')


        frame = []
        number = []

        for i in range(len(self.min)):
            for j in range(len(self.min[i])):
                frame.append(i)
                number.append(self.min[i][j])

        fig_3 = plt.figure()

        ax_3 = fig_3.add_subplot(1,1,1)

        ax_3.scatter(frame,number,s=10)

        ax_3.set_title('learning minibach index')
        ax_3.set_xlabel('learning times')
        ax_3.set_ylabel('minibach index')

        plt.ylim([0,2500])
        plt.xlim([len(self.min)-50,len(self.min)])
        if self.flag:
            plt.show()
        plt.savefig(self.folder + '/minibach_detail.jpg')