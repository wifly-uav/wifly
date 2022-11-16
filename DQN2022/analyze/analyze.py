import os
import pandas as pd
import glob
import itertools
import operator
import matplotlib.pyplot as plt
import numpy as np

path = os.path.dirname(__file__)
with open(path+'/folder.txt','r') as f:
    data = f.read().splitlines()

for i in data:
    print(i)

angle = []
time = []
action = []

for i in data:
    act_file = path+'/../result/'+i+'/debug_act.csv'
    try:
        act = pd.read_csv(act_file, encoding='shift_jis', usecols=[0])
    except:
        act = pd.read_csv(act_file, encoding='utf_8', usecols=[0])
    act = act.T
    act = list(itertools.chain.from_iterable(act.values.tolist()))
    action.append(act)

    angle_file = path+'/../result/'+i+'/log2.csv'
    try:
        ang = pd.read_csv(angle_file, encoding='shift_jis', usecols=[0])
    except:
        ang = pd.read_csv(angle_file, encoding='utf_8', usecols=[0])
    ang = ang.T
    ang = list(itertools.chain.from_iterable(ang.values.tolist()))
    angle.append(ang)

    time_file = path+'/../result/'+i+'/log.csv'
    try:
        ti = pd.read_csv(time_file, encoding='shift_jis', usecols=[5])
    except:
        ti = pd.read_csv(time_file, encoding='utf_8', usecols=[5])
    ti = ti.T
    ti = ti.values.tolist()
    ti = np.around(ti, decimals=3)
    ti = list(itertools.chain.from_iterable(ti))
    ti = np.around(ti, decimals=3)
    time.append(ti)

act_ = list(itertools.chain.from_iterable(action))
ti_ = list(itertools.chain.from_iterable(time))
ti_ = list(itertools.accumulate(ti_))
#print(ti_)
plt.scatter(ti_,act_)
for i in range(len(action)-1):
    plt.vlines(ti_[500*(i+1)],0,5,color='red')
plt.show()