import numpy as np
import tensorflow as tf
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

N_EPOCHS = 1            #学習epoch数
N_FRAMES = 200          #1epochあたりのステップ数
I_GAIN = 0.0001 #0.0001
D_GAIN = 0
PWM_DEF = 194           #kitai側では+1されて190になる。
ER = 0
MODEL_NAME_HEADER = "WiflyDual_DQN"
YAW_INDEX = 2           #[モータ出力1,モータ出力2,Yaw,p_gain](logger,environmentで一致しているか確認)

if __name__ == "__main__":
    tf.compat.v1.disable_eager_execution()
    #PID_param
    saturations = [0,150]           #PID操作量の制限
    pwm_def = PWM_DEF                   #モーター出力デフォルト値(Environmemtのdefault_paramsもチェック)
    pid = calc_PID(saturations)     #calc_PIDクラスのインスタンス作成（__init__が呼び出され、初期化が行われる）
    param = [1.5,I_GAIN,D_GAIN,0]   #[P-gain,I-gain,D-gain,Target Yaw angle]
    ti = 10                         #PIDの微積分計算で用いる最小の時間幅
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
    agent = DQNAgent(folder = save_dir)                      
    
    print('Use saved progress? y/n')               #既存のモデル（学習済みNN）を使うか?
    ans_yn = input()
    if (ans_yn == 'y'):                         #既存のモデルを使用する場合…                      
        print('use model folder name:')         #使用するフォルダ名の入力を指示
        fldr_name = input()
        saved_dir = save_dir + "/../" + fldr_name + "/"
        print("Loading NN model")
        agent.load_saved_NN(saved_dir)
        agent.NN_avoid_overhead()
        print("Loading log_loss")
        agent.load_log_loss(saved_dir)
        print("Loading parameters")
        agent.load_param(filepath = saved_dir)
        print("Loading replay buffer")
        agent.load_replay_buffer(filepath = saved_dir)
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

        """
        use_folder = input()                                   
        #指定フォルダの存在確認とデータの読み込み
        #データがあればload_flagはTrueになり、データが読み込まれる。
        load_flag = agent.load_model(model_path= use_folder)
        if load_flag:                           #データが存在している場合…
            print('Model load has been done')
            print('training? y/n')              #学習を行うか?（training_flag）
            ans = input()
            if (ans == 'y'):
                training_flag = True                
                print('training')
            else:
                training_flag = False
                print('test')
        else:                                   #データが存在していない場合…
            print('No model data')
            sys.exit()                          #終了
        """

    else:                                       #既存のモデルを使わない場合…
        print('Progam starts without loading a model')
        training_flag = True
    
    #各種log保存先指定
    log = logger(folder = save_dir)
    env = Environment(agent.keep_frames)                         #Environmentクラスのインスタンス作成
    vi = visual_nn(folder = save_dir)        
    mi = visual_minibach(folder = save_dir)
    ac = visual_act(folder = save_dir)
    
    #print("press y to start")                   #未実装
    #print("Start after 3 seconds")
    #stime.sleep(3)

    Time_start = time.time()
#try:
    for i in range(N_EPOCHS):                   #N_EPOCHSごとに各パラメータを初期化
        #init
        #frame = 0                              #未使用                    
        loss = 0.0                              #NN損失関数
        Q_max = 0.0                             #行動価値関数最大値
        reward = 0                              #報酬
        p_gain = 1.5                            #初期Pgain
        terminal = False                        #終状態フラグ（もとはTrue）
        data = True                             #?
        com_fail = False                        #通信に失敗した場合にTrueにする。

        #状態を格納するdequeを作成
        #この中でstart_espも行われる。（現在の初期送信データ長は4）
        #最初にNNの入力に必要なKEEP_FRAMES個の状態をLazuriteから取得し、#state([deque])に格納
        #ver2では、dequeにmaxlenを設定して、古い状態の削除を自動で行っている。
        env.reset_pid_2(add = p_gain)   
        #env.reset_pid(add=p_gain)      

        state_next = env.observe_state()        #次状態（FRAMES=4個分の初期状態が格納されたstate）を観測

        for j in range(N_FRAMES):
            t_start = time.time()
            #terminal = env.observe_terminal()              #未使用
            state_current = state_next                      #次状態を現在の状態とする
            agent.get_angle(state_current)                  #現在の状態から、Yaw角を取得して記録する(log用)
            action = agent.choose_action(state_current)     #ε-greedy方策によってactionを決定
            p_gain = env.execute_action_gain(action)        #actionに対応するPgainを取得
            param = [p_gain,I_GAIN,D_GAIN,0]                #paramを更新（Pgainを更新）
            pid.update_params(param)                        #calc_PIDクラスにparamの変更を反映
            #print(i,j,state_current[0][0],ti)
            
            #操作量をPID計算
            #state_currentはFRAMES個の状態を保持
            #state_current[0]が最新の状態で、state_current[0][YAW_INDEX]が最新の状態におけるYaw角
            #delta_timeは微積分の近似で用いる時間幅
            #modeはSaturationブロック有効化を決めるフラグ
            #t_1 = time.time() - t_start
            #print("t_1:", end = "")
            #print(t_1)
            diff = pid.calculate_output(current_value = int(state_current[0][YAW_INDEX]), delta_time = (int)(ti), mode = True)

            #出力を変えるモータが逆な気がする…
            if diff > 0:                            #操作量が正なら…
                actions[0] = pwm_def - diff         #右側のモータ出力を下げる
                actions[1] = pwm_def - ER           #ER=0なので気にしなくて良い
            else:                                   #操作量が負なら…
                actions[0] = pwm_def                
                actions[1] = pwm_def + diff - ER    #左側のモータ出力を下げる

            #print(actions)
            env.execute_action_(actions)            #機体にモータ出力の変更内容を送信

            """
            if (j != 0 and training_flag == True):
                agent.experience_replay()           #経験再生
            """

            #t_2 = time.time() - t_start
            #print("t_2:", end = "")
            #print(t_2)

            #新たな状態を観測
            #state_next:新たな状態が1つ加わり、古い状態が削除されたもの
            #更新されたstateデック、受信間隔（機体計測）、受信側（PC計測）が返ってくる
            #state_next, ti, ti_ = env.observe_update_state_pid(pid=p_gain)
            try:
                state_next, ti, ti_ = env.observe_update_state_pid_2(pid = p_gain)
            except:
                print("Communication Failure")
                com_fail = True
                break
            #t_20 = time.time() - t_start
            #print("t_20:", end = "")
            #print(t_20)

            reward = env.observe_reward(state_next)     #Yaw角の0.0度からのずれに基づいた報酬を観測

            #t_21 = time.time() - t_start
            #print("t_21:", end = "")
            #print(t_21)

            #EPOCHの最後(各EpochのN_FRAMES目)ならば、terminalをTrueにする。
            if j == N_FRAMES - 1:
                terminal = True

            #経験保存
            #agent.store_experience(state_current, action, reward, state_next, terminal)
            #agent.store_transition(state_current,action,reward, state_next,terminal)
            agent.store_transition_with_priority(state_current, action, reward, state_next, terminal)
            
            #t_3 = time.time() - t_start
            #print("t_3:", end = "")
            #print(t_3)

            #進捗表示
            u_i = pid.I*I_GAIN  #Igainによる操作量（=I_gain*偏差の蓄積（積分））
            epoch = i + agent.episode_in_advance
            print( "Epoch:%d" % epoch, 
                    "STEP:%d" % j,
                    "Grobal_STEP:%d" % agent.global_step, 
                    "Latest state:" + str(state_next[0]), 
                    "Yaw angle:%f" % agent.log_yaw_angle[-1],
                    "Reward:%d" % reward,
                    "Epsilon:%4f" % agent.epsilon, 
                    "u_I:%6f" % u_i)

            #if (j != 0 and training_flag == True):
            if training_flag == True:
                #agent.experience_replay()           #経験再生(NNパラメータのミニバッチ学習を行う)
                agent.learn()
            
            #t_4 = time.time() - t_start
            #print("t_4:", end = "")
            #print(t_4)

            #εのスケジューリング
            
            if training_flag:                       #学習を行う場合…
                #agent.epsilon -= 0.1/3000          #ランダム行動確率を下げていく。
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

            #t_5 = time.time() - t_start

        if com_fail:
            print(com_fail)
            agent.save_NN_model(filepath = save_dir)
            agent.buffer_param(save_dir)
            break

        agent.episode += 1    
            #print("t_5:", end = "")
            #print(t_5)

        #NNの保存
        #エピソードごとに保存しておく。(Wiflyの通信が切れたときを想定)
        #agent.save_model(filepath = save_dir)
        agent.save_NN_model(filepath = save_dir)

        #エピソード終了時の変数の値を保持しておく。
        #テキスト等への書き出しは、学習終了後に行う。
        agent.buffer_param(save_dir)
        agent.link_log_loss()
    
    #時間計測用
    Time = time.time() - Time_start
    
#except :
#except KeyboardInterrupt:
    #print("except finish")
    #print(state_current)
    #print(state_next)

    #学習が終了したら各種出力を0
    #保険用に3回繰り返し
    env.execute_action_([0,0])
    env.execute_action_([0,0])
    env.execute_action_([0,0])

    agent.hyper_params()
    #agent.save_NN_model()      #NNモデルの保存
    agent.debug_nn()            #q_evalの重みとバイアスをtxtファイルで保存
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
    
    vi.visualize()
    mi.visualize()
    #ac.visualize()

    agent.save_param(filepath = save_dir)
    agent.save_log_loss(filepath = save_dir)

    print("finish")
    print(save_dir)
    print("Time:%2f" % Time)