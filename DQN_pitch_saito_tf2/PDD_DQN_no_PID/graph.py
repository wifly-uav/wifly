import glob
from numpy import double
import pandas as pd
import matplotlib.pyplot as plt
import statistics

import csv
import pprint

import os
import sys 



class Graph():

    def __init__(self, path, path2, save_place=None):
        
        files = glob.glob(path + 'debug_loss.csv')
        files2 = glob.glob(path2 + 'log2_*.csv')
        self.file = files
        self.file_a = files2
        self.save_place = save_place

    def graph(self):
        #-----------------loss----------------------------
        try:
            df = pd.read_csv(self.file, encoding="shift_jis", skiprows=0, usecols=[1])
        except:
            df = pd.read_csv(self.file, encoding="utf_8", skiprows=0, usecols=[1])
        dft = df.T
        lis = dft.values.tolist()

        plt.plot(lis[0])
        plt.ylim(0,)
        plt.title("LOSS",fontsize=25)
        if self.save_place == None:
            plt.savefig("log/loss.png")
        else:
            plt.savefig(self.save_place + "loss.png")
        plt.show()

        #-----------------angle----------------------------
        try:
            df = pd.read_csv(self.file_a, encoding="shift_jis", skiprows=0, usecols=[0])
        except:
            df = pd.read_csv(self.file_a, encoding="utf_8", skiprows=0, usecols=[0])
        dft = df.T
        lis = dft.values.tolist()

        try:
            df_t = pd.read_csv(self.file_a, encoding="shift_jis", skiprows=0, usecols=[2])
        except:
            df_t = pd.read_csv(self.file_a, encoding="utf_8", skiprows=0, usecols=[2])
        dft_t = df_t.T
        lis_t = dft_t.values.tolist()
        sum = 0
        time = []

        med = statistics.median(lis_t[0])

        for i in lis_t[0]:
            if i < 0:
                i = med
            if i > 200:
                i = med
            sum += i
            time.append(sum/1000)

        plt.plot(time,lis[0])
        plt.ylim(-90,90)
        plt.plot([0, time[-1]],[10, 10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[-10, -10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[0, 0], "black")
        plt.title("ANGLE",fontsize=25)
        if self.save_place == None:
            plt.savefig("log/angle.png")
        else:
            plt.savefig(self.save_place + "angle.png")
        plt.show()



if __name__ == "__main__":
    print("Which folder?")
    folder_path = input()
    path = folder_path + "/"
    

    gra = Graph(path=path, path2=path, save_place=path)
    gra.graph()
    