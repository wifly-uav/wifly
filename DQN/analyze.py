import glob
import pandas as pd

import csv
import pprint

import os
import sys 
import matlab.engine

path = os.path.dirname(__file__)
path = os.path.join(path, 'result')

eng = matlab.engine.start_matlab()

#結果はdata.csvとして保存
with open(path + "/data.csv", 'w', newline='') as f:
    writer = csv.writer(f)
    #title = ['name','ave','std']
    #writer.writerow(title)
    print(path + "/*/log2.csv")
    files = glob.glob(path + "/*/log2.csv")
    
    for file in files:
        print(file)
    for file in files:
        #結果を保存したdata.csvがあった場合、読み込むのを防ぐため
        if(file != path + "data.csv"):
            name = os.path.splitext(os.path.basename(file))[0]
            ext = os.path.splitext(os.path.basename(file))[1]
            name = file.split("\\")[-2]
            #print(name)
            #print(ext)
            #csvファイルのみを読み込み
            if(ext == '.csv'):
                #excelで上書きするとエンコードタイプがutf_8になってしまうことに注意
                print(name)
                try:
                    df = pd.read_csv(file, header=None, encoding="shift_jis", usecols=[0])
                except:
                    #df = pd.read_csv(file, header=None, encoding="utf_8", usecols=[0])
                    print(file)
                dft = df.T
                #print(dft)
                lis = dft.values.tolist()
                #print(lis[0])
                mat = matlab.double(lis[0])

                ave = eng.mean(mat)
                std = eng.std(mat)

                data = [name, ave, std]
                writer.writerow(data)