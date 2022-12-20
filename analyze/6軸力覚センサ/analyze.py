import glob
import pandas as pd

import csv
import pprint

import os
import sys 
import matlab.engine

print("Which folder?")
folder_path = input()
path = folder_path + "/"

eng = matlab.engine.start_matlab()

#結果はdata.csvとして保存
with open(path + "data.xlsx", 'w', newline='') as f:
    writer = csv.writer(f)
    title = ['name','ave','var','hz']
    writer.writerow(title)
    files = glob.glob(path + "*")
    
    for file in files:
        print(file)
    for file in files:
        #結果を保存したdata.csvがあった場合、読み込むのを防ぐため
        if(file != path + "data.csv"):
            name = os.path.splitext(os.path.basename(file))[0]
            ext = os.path.splitext(os.path.basename(file))[1]
            #print(name)
            #print(ext)
            #csvファイルのみを読み込み
            if(ext == '.csv'):
                #excelで上書きするとエンコードタイプがutf_8になってしまうことに注意
                print(name)
                try:
                    df = pd.read_csv(file, encoding="shift_jis", skiprows=4, usecols=[3])
                except:
                    df = pd.read_csv(file, encoding="utf_8", skiprows=4, usecols=[3])
                dft = df.T
                #print(dft)
                lis = dft.values.tolist()
                #print(lis[0])
                mat = matlab.double(lis[0])

                ave = eng.mean(mat)
                var = eng.var(mat)
                #フーリエ解析し、結果を画像として保存する
                F = eng.fft_ori(mat, path + name)
                #print(ave)
                #print(var)
                #print(F)

                data = [name, ave, var, F]
                writer.writerow(data)