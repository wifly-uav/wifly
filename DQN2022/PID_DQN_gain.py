import numpy as np
import tensorflow as tf
from Communication import Communicator
from Environment import Environment
from Agent import MINIBATCH_SIZE, DQNAgent
from Logger import logger
import sys
from visualize_nn import visual_nn
from visualize_heatmap import visual_minibach
from visualize_act import visual_act
from Calc_Control import calc_PID
import os
import time
import csv
import threading

N_EPOCHS = 1            #学習epoch数
N_FRAMES = 800          #1epochあたりのステップ数
I_GAIN = 0.00004         #0.00001
D_GAIN = 0              
PWM_DEF = 209           #kitai側では+1されて195になる。
ER = 0
YAW_INDEX = 2           #[モータ出力1,モータ出力2,Yaw,p_gain](logger,environmentで一致しているか確認)

PID = True #STATE_VARIABLES=4
ADD_I = True #STATE_VARIABLES=5
FFPID = False #N_ACTIONS=9
INC = False #N_ACTIONS=5
MIX = False #N_ACTIONS=17,STATE_VARIABLES=3
RND = True
LSTM = True
LOAD = True
LOAD_BATCH = True
LOAD_RND = True
Filter = False
RC_filter = 7
PARALLEL = False
EPISODE_TIME = 30.0

if __name__ == "__main__":
    tf.compat.v1.disable_eager_execution()
    #PID_param
    saturations = [0,100]           #PID操作量の制限
    pwm_def = PWM_DEF               #モーター出力デフォルト値(Environmemtのdefault_paramsもチェック)
    pid = calc_PID(saturations)     #calc_PIDクラスのインスタンス作成（__init__が呼び出され、初期化が行われる）
    param = [3,I_GAIN,D_GAIN,0]   #[P-gain,I-gain,D-gain,Target Yaw angle]
    ti = 40                         #PIDの微積分計算で用いる最小の時間幅
    actions = [pwm_def, pwm_def]    #行動ベクトル（両翼のモータ出力）
    pid.update_params(param)        #paramの値をcalc_PIDクラスに反映

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
    agent = DQNAgent(folder = save_dir, RND=RND, LSTM=LSTM)                      
    
    print('Use saved progress? y/n')               #既存のモデル（学習済みNN）を使うか?
    ans_yn = input()
    if (ans_yn == 'y'):                         #既存のモデルを使用する場合…                      
        print('use model folder name:')         #使用するフォルダ名の入力を指示
        fldr_name = input()
        saved_dir = save_dir + "/../" + fldr_name + "/"
        print("Loading NN model")
        agent.load_saved_NN(saved_dir)
        if RND:
            if LOAD_RND:
                agent.load_rnd_NN(saved_dir)
                agent.NN_RND_avoid_overhead()
        agent.NN_avoid_overhead()
        if LOAD:
            print("Loading log_loss")
            agent.load_log_loss(saved_dir)
            print("Loading parameters")
            agent.load_param(filepath = saved_dir)
            print("Loading replay buffer")
            if LOAD_BATCH:
                agent.load_replay_buffer(filepath = saved_dir)
                agent.memory.load_buffer(folder = saved_dir)
            #print(agent.memory_per.data[:60])
            #print(list(agent.memory_per.data).count(0))
        
        print('training? y/n')              #学習を行うか?（training_flag）
        ans = input()
        if (ans == 'y'):
            training_flag = True                
            print('training')
        else:
            training_flag = False
            print('test')
            agent.epsilon = 0

    else:                                       #既存のモデルを使わない場合…
        print('Progam starts without loading a model')
        training_flag = True
    
    #各種log保存先指定
    log = logger(folder = save_dir)
    env = Environment(agent.keep_frames)                         #Environmentクラスのインスタンス作成
    vi = visual_nn(folder = save_dir)        
    mi = visual_minibach(folder = save_dir)
    ac = visual_act(folder = save_dir)

    env.set_cut_off((int)(RC_filter))
    
    print("2 sec")
    time.sleep(1)
    print("1 sec")
    time.sleep(1)
    print("start")

    for i in range(N_EPOCHS):                   #N_EPOCHSごとに各パラメータを初期化

        #init
        #frame = 0                              #未使用                    
        loss = 0.0                              #NN損失関数
        Q_max = 0.0                             #行動価値関数最大値
        reward = 0.0                              #報酬
        p_gain = 1.5                            #初期Pgain
        terminal = False                        #終状態フラグ（もとはTrue）
        com_fail = False                        #通信に失敗した場合にTrueにする。
        score = 0                               #累積報酬
        rnd_f = []
        if Filter:
            yaw_index = -1
        else:
            yaw_index = 2

        if MIX:
            env.reset_pid(yaw_index=yaw_index)  
        elif PID:
            if ADD_I:
                env.reset_pid(p_gain=p_gain,i_=0,yaw_index=yaw_index)
            else:
                env.reset_pid(p_gain=p_gain,yaw_index=yaw_index)
        else:
            env.reset_pid(yaw_index=yaw_index)  

        state_next = env.observe_state()        #次状態（FRAMES=4個分の初期状態が格納されたstate）を観測

        start = time.time()
        if PARALLEL:
            thread = threading.Thread(target=agent.learn)
            thread.start()
        for j in range(N_FRAMES):
            Time_start = time.time()
            state_current = state_next                      #次状態を現在の状態とする
            agent.get_angle(state_current)                  #現在の状態から、Yaw角を取得して記録する(log用)

            if MIX:
                rnd_flag = agent.rnd_thr(state_current,10)
                rnd_f.append(rnd_flag)
                if rnd_flag:
                    action = agent.choose_action(state_current)
            else:
                action = agent.choose_action(state_current)

            if PID:
                if MIX:
                    p_gain = 3
                else:
                    p_gain = env.execute_action_gain((int)(action))
                param = [p_gain,I_GAIN,D_GAIN,0]
                pid.update_params(param)
                diff = pid.calculate_output(current_value = int(state_current[0][yaw_index]), delta_time = (int)(ti), mode = True)
                if diff > 0:
                    actions[0] = pwm_def - diff
                    actions[1] = pwm_def
                else:
                    actions[0] = pwm_def                
                    actions[1] = pwm_def + diff
                if MIX:
                    if rnd_flag:
                        env.excute_action(action)
                    else:
                        env.execute_action_(actions)            #機体にモータ出力の変更内容を送信
                else:
                    env.execute_action_(actions)            #機体にモータ出力の変更内容を送信
            elif FFPID:
                diff = pid.calculate_output(current_value = int(state_current[0][yaw_index]), delta_time = (int)(ti), mode = True)
                if diff > 0:                            #操作量が正なら…
                    actions[0] = pwm_def - diff         #右側のモータ出力を下げる
                    actions[1] = pwm_def           #ER=0なので気にしなくて良い
                else:                                   #操作量が負なら…
                    actions[0] = pwm_def                
                    actions[1] = pwm_def + diff    #左側のモータ出力を下げる
                env.excute_action_pid((int)(action), actions)
            else:
                if INC:
                    actions[0],actions[1] = env.excute_action_inc((int)(action), actions)
                else:
                    env.excute_action((int)(action))

            try:
                if MIX:
                    state_next, ti, ti_ = env.observe_update_state_pid(yaw_index=yaw_index)
                elif PID:
                    if ADD_I:
                        inte = pid.get_i()
                        state_next, ti, ti_ = env.observe_update_state_pid(p_gain=p_gain,i_=inte,yaw_index=yaw_index)
                    else:
                        state_next, ti, ti_ = env.observe_update_state_pid(p_gain=p_gain,yaw_index=yaw_index)
                else:
                    state_next, ti, ti_ = env.observe_update_state_pid(yaw_index=yaw_index)
            except:
                print("Communication Failure")
                com_fail = True
                break

            reward = env.observe_reward(state_next, yaw_index=yaw_index)     #Yaw角の0.0度からのずれに基づいた報酬を観測
            score += reward

            if j == N_FRAMES - 1:
                terminal = True

            if MIX:
                if rnd_flag==0:
                    action = env.state2action(actions)
            #経験保存
            agent.store_transition(state_current,action,reward, state_next,terminal)
            #agent.store_transition_with_priority(state_current, action, reward, state_next, terminal)

            #進捗表示
            u_i = pid.get_i()
            epoch = i + agent.episode_in_advance
            
            print( "Epoch:%d" % epoch, 
                    "STEP:%d" % j,
                    "Grobal_STEP:%d" % agent.global_step, 
                    "Latest state:" + str(state_next[0]), 
                    "Yaw angle:%f" % float(state_next[0][YAW_INDEX]),
                    "Reward:%f" % reward,
                    "Epsilon:%4f" % agent.epsilon, 
                    "u_I:%6f" % u_i,
                    "actions:" + str(254-actions[0])+","+ str(254-actions[1]),
                    "act:" + str(action),
                    "dt:%d" %ti)

            if training_flag == True:
                if PARALLEL == False:
                    #agent.experience_replay()           #経験再生(NNパラメータのミニバッチ学習を行う)
                    agent.learn()

            #εのスケジューリング            
            if training_flag:                       #学習を行う場合…
                #agent.epsilon -= 0.1/3000          #ランダム行動確率を下げていく。
                agent.update_epsilon()
                pass                                #モデルの変化を考慮して、探索させる確率を下げない。
            else:                                   #学習を行わない場合…
                agent.epsilon = 0                   #ランダム行動はさせない。

            # for loging
            # 次状態、行動、最新の送信データ（の一部）、受信間隔（機体計測）、受信間隔（PC計測）を格納(log)
            # 次状態、報酬、受信間隔（機体計測）(log2)
            log.add_log_state_and_action(state_next, action, env.params_to_send, ti, ti_)
            log.add_log_state(state_next, reward, ti)

            #ステップ数のカウント
            agent.global_step += 1

            Time_end = time.time()
            while (Time_end-Time_start<0.04):
                Time_end = time.time()
            if Time_end-start > EPISODE_TIME:
                break

        if com_fail:
            print(com_fail)
            agent.save_NN_model(filepath = save_dir)
            agent.buffer_param(save_dir)
            if RND:
                agent.save_rnd_model(filepath = save_dir)
            break

        #時間計測用
        Time = time.time() - start
        agent.episode += 1

        #NNの保存
        #エピソードごとに保存しておく。(Wiflyの通信が切れたときを想定)
        #agent.save_model(filepath = save_dir)
        agent.save_NN_model(filepath = save_dir)
        if RND:
            agent.save_rnd_model(filepath = save_dir)

        #エピソード終了時の変数の値を保持しておく。
        #テキスト等への書き出しは、学習終了後に行う。
        agent.buffer_param(save_dir)
        agent.link_log_loss()

    #学習が終了したら各種出力を0
    env.execute_action_([0,0])
    env.execute_action_([0,0])
    env.execute_action_([0,0])

    print('saving buffer')
    agent.memory.save_buffer(folder=save_dir)
    print('saving hyper params')
    agent.hyper_params()
    print('saving debug files')
    agent.debug_nn()            #q_evalの重みとバイアスをtxtファイルで保存
    if RND:
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
    
    #以下をCSV出力
    #次状態、行動、最新の送信データ(の一部)、最新の受信間隔、前回の受信間隔を格納(log)
    #次状態、報酬、最新の受信時刻(log2)
    log.output_log()

    #lossのグラフ表示 
    loss = agent.check_loss()
    log.loss_graph(loss)

    #loss_graph自作ver
    #x = list(range(N_EPOCHS*N_FRAMES))
    x = list(range(agent.batch_size, agent.batch_size + len(agent.log_loss)))
    #print(len(x))
    log.loss_graph_2(x,loss)
    
    log.angle_graph()
    
    #自作
    x = list(range(len(agent.log_yaw_angle)))
    #print(agent.log_yaw_angle)
    #print(type(agent.log_yaw_angle))
    log.angle_graph_2(x,agent.log_yaw_angle)
    
    #vi.visualize()
    #mi.visualize()
    #ac.visualize()

    agent.save_param(filepath = save_dir)
    agent.save_score(save_dir, score)
    agent.save_log_loss(filepath = save_dir)
    if PARALLEL:
        agent.save_counter(filepath= save_dir)
    
    env.communicator.serial_close()

    if MIX:
        with open(save_dir + "/log_rnd_flag.csv", mode = "w", newline = "") as f:
            writer = csv.writer(f, lineterminator = "\n")
            writer.writerow(rnd_f)

    print("finish")
    print(save_dir)
    print(score)
    print("Time:%2f" % Time)
    print("state_len:" + str(len(env.communicator.state)))