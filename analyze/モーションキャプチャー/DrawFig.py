import pandas as pd
import mpl_toolkits.mplot3d as a3
import matplotlib.colors as colors
import matplotlib.pyplot as plt
import pylab as pl
import scipy as sp
import csv
import glob
import os
import numpy as np

import pathlib
import shutil

py_path = os.path.dirname(__file__)                        #このスクリプトのディレクトリ名を取得
print("Which folder?")
folder_path = input()
path = py_path + "/" + folder_path + "/"

def change_suffix(file_name, from_suffix, to_suffix):
    # ファイルの拡張子を得る
    sf = pathlib.PurePath(file_name).suffix
    
    # 変更対象かどうか判定する
    if sf == from_suffix:
        # ファイル名(拡張子除く)を得る
        st = pathlib.PurePath(file_name).stem
        # 変更後のファイル名を得る
        to_name = path + st + to_suffix
        # ファイル名を変更する
        shutil.move(file_name, to_name)

def trc2csv():
    files = glob.glob(path+"*.trc")
    for file in files:
        change_suffix(file,'.trc','.csv')

def rewrite():
    files = glob.glob(path+"*.csv")
    for file in files:
        print(file)
        st = pathlib.PurePath(file).stem
        file_ = np.genfromtxt(file)
        for i in range(6):
            file_ = np.delete(file_,0,0)
        np.savetxt(path+st+"_re.csv", file_)
        


if __name__ == "__main__":
    trc2csv()
    #rewrite()
"""
data =[[]]
data_to_plot = []

plt.rcParams["font.size"]=18
f = open('old_gearbox_v8-Unnamed.csv', 'r', encoding='utf-8', errors='', newline='')
csv_file = csv.reader(f, delimiter=",", doublequote=True, lineterminator="\r\n", quotechar='"', skipinitialspace=True)

ax = a3.Axes3D(pl.figure())

x = []
y = []
z = []
for i, row in enumerate(csv_file):
    try:
        if i % 1 == 0:
            print(row[0:3])
            x.append(float(row[0])/1000.0)
            y.append(float(row[1])/1000.0)
            z.append(float(row[2])/1000.0)
    except:
        print('exception')
        pass

ax.scatter(x,y,z, c="red", alpha=0.8)

#ax.set_ylim([-1,3])
#ax.set_xlim([-2,2])
#ax.set_zlim([-1,3])
pl.show()
"""