import numpy as np
import tensorflow as tf
from Environment import Environment
from Agent import MINIBATCH_SIZE, DQNAgent
from Logger import logger
import sys
from visualize_nn import visual_nn
from visualize_heatmap import visual_minibach
from visualize_act import visual_act
import os
import time

NUM = 1000

PID = 'False'
ADD_I = 'False'
FFPID = 'False'
INC = 'False'
MODE = 'RND'
LOAD = 'None'

if __name__ == "__main__":
    tf.compat.v1.disable_eager_execution()

    path = os.path.dirname(__file__)                        #このスクリプトのディレクトリ名を取得
    print('save folder name:')                              #学習内容を保存するためのフォルダ名の入力を指示
    save_folder = input()                                   
    save_dir = os.path.join(path, 'result', save_folder)   #･･･/result/save_folderのpath取得
    print(save_dir)

    if not os.path.exists(save_dir):                       #ディレクトリが存在しない場合、ディレクトリを作成する
        os.makedirs(save_dir)                              
    else:
        print('The folder exists.') 
        print('override? y/n')                              #上書きの確認
        override = input()
        if (override == 'y'):
            pass
        else:
            print('Quit')                                   #上書きしない場合終了
            sys.exit()
    
    #DQNAgentクラスのインスタンス作成（NNの初期化やReplayMemoryの用意がされる）
    agent = DQNAgent(folder = save_dir, mode=MODE)                      
                     
    print('use model folder name:')         #使用するフォルダ名の入力を指示
    fldr_name = input()
    saved_dir = save_dir + "/../" + fldr_name + "/"
    if LOAD == 'NN':
        print("Loading NN model")
        agent.load_saved_NN(saved_dir)
        if MODE == "RND":
            agent.load_rnd_NN(saved_dir)
            agent.NN_RND_avoid_overhead()
        agent.NN_avoid_overhead()
    print("Loading log_loss")
    agent.load_log_loss(saved_dir)
    print("Loading parameters")
    agent.load_param(filepath = saved_dir)
    print("Loading replay buffer")
    agent.load_replay_buffer(filepath = saved_dir)
    agent.memory.load_buffer(folder = saved_dir)
    agent.set_batchsize(agent.memory.mem_cntr)
    #print(agent.memory_per.data[:60])
    #print(list(agent.memory_per.data).count(0))

    #各種log保存先指定
    log = logger(folder = save_dir)
    vi = visual_nn(folder = save_dir)        
    mi = visual_minibach(folder = save_dir)
    ac = visual_act(folder = save_dir)
    
    print("start")

    agent.global_step = 1
    for j in range(NUM-1):
        agent.learn()
        print(j)
    agent.global_step = 0
    agent.learn()
    print('fin')

    #NNの保存
    #エピソードごとに保存しておく。(Wiflyの通信が切れたときを想定)
    #agent.save_model(filepath = save_dir)
    agent.save_NN_model(filepath = save_dir)
    if MODE == 'RND':
        agent.save_rnd_model(filepath = save_dir)

    #エピソード終了時の変数の値を保持しておく。
    #テキスト等への書き出しは、学習終了後に行う。
    agent.buffer_param(save_dir)
    agent.link_log_loss()
    
    agent.memory.save_buffer(folder=save_dir)
    agent.hyper_params()
    #agent.save_NN_model()      #NNモデルの保存
    agent.debug_nn()            #q_evalの重みとバイアスをtxtファイルで保存
    if MODE == 'RND':
        agent.debug_rnd_target_nn()
        agent.debug_rnd_predictor_nn()
        agent.debug_rnd()
    agent.debug_memory()        #リプレイバッファに保存されている遷移のうち、状態のみをcsv出力
    agent.debug_minibatch()     #minibatch_indexのlogをCSV出力(未実装)
    agent.debug_minibatch_2()   #自作ver!
    agent.debug_q()             #行動価値関数Qと行動aのlogをCSV出力
    agent.debug_yaw()           #Yaw角のlogをCSV出力
    agent.debug_p()             #選択した遷移の優先度の履歴をCSV出力
    #agent.debug_loss()         #listがfloatと認識されている…

    #lossのグラフ表示 
    loss = agent.check_loss()
    log.loss_graph(loss)
    
    vi.visualize()
    mi.visualize()
    #ac.visualize()

    agent.save_param(filepath = save_dir)
    agent.save_log_loss(filepath = save_dir)

    print("finish")
    print(save_dir)