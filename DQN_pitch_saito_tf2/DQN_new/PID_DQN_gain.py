import numpy as np
from Environment import Environment
from Agent import DQNAgent
from Logger import logger
import sys
from visualize_nn import visual_nn
from visualize_heatmap import visual_minibach
from visualize_act import visual_act
from Calc_Control import calc_PID
import os

N_EPOCHS = 5
N_FRAMES = 500
I_GAIN = 0.0001
D_GAIN = 0
ER = 0
MODEL_NAME_HEADER = "WiflyDual_DQN"

if __name__ == "__main__":

    #PID_param
    saturations = [0,150]           #PID操作量の制限
    pwm_def = 250                   #モーター出力デフォルト値
    pid = calc_PID(saturations)     #calc_PIDクラスのインスタンス作成（__init__が呼び出され、初期化が行われる）
    param = [1.5,I_GAIN,D_GAIN,0]   #[P-gain,I-gain,D-gain,Target Yaw angle]
    ti = 10                         #PIDの微積分計算で用いる最小の時間幅
    actions = [pwm_def, pwm_def]
    pid.update_params(param)        #paramの値をcalc_PIDクラスに反映

    
    path = os.path.dirname(__file__)                        #このスクリプトのディレクトリ名を取得
    print('save folder name:')                              #学習内容を保存するためのフォルダ名の入力を指示
    save_folder = input()                                   
    save_file = os.path.join(path, 'result', save_folder)   #･･･/result/save_folderのpath取得
    print(save_file)

    if not os.path.exists(save_file):                       #ディレクトリが存在しない場合、ディレクトリを作成する
        os.makedirs(save_file)                              
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
    agent = DQNAgent(folder=save_file)                      
    
    print('Use saved model? y/n')               #既存のモデル（学習済みNN）を使うか?
    ans_yn = input()
    if (ans_yn == 'y'):                         #既存のモデルを使用する場合…                      
        print('use model folder name:')         #使用するフォルダ名の入力を指示
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

    else:                                       #既存のモデルを使わない場合…
        print('Progam starts without loading a model')
        training_flag = True
    
    #各種log保存先指定
    log = logger(folder=save_file)
    env = Environment()                         #Environmentクラスのインスタンス作成
    vi = visual_nn(folder=save_file)        
    mi = visual_minibach(folder=save_file)
    ac = visual_act(folder=save_file)
    
    print("press y to start")                   #未実装

#try:
    for i in range(N_EPOCHS):                   #N_EPOCHSごとに各パラメータを初期化
        #init
        frame = 0                               #未使用                    
        loss = 0.0                              #NN損失関数
        Q_max = 0.0                             #行動価値関数最大値
        reward = 0                              #報酬
        p_gain = 1.5                            
        terminal = True                         #終状態フラグ(どこでFalseにする...?)
        data = True                             #?

        #状態を格納するdequeを作成
        #最初にNNの入力に必要なFRAMES個の状態をLazuriteから取得し、#state([deque])に格納
        #ver2では、dequeにmaxlenを設定して、古い状態の削除を自動で行っている。
        env.reset_pid_2(add=p_gain)   
        #env.reset_pid(add=p_gain)          

        state_next = env.observe_state()        #次状態（FRAMES=4個分の初期状態が格納されたstate）を観測

        for j in range(N_FRAMES):
            terminal = env.observe_terminal()               #未使用
            state_current = state_next                      #次状態を現在の状態とする
            
            #action = agent.select_action(state_current)     
            action = agent.choose_action(state_current)     #ε-greedy方策によってactionを決定
            p_gain = env.execute_action_gain(action)        #actionに対応するPgainを取得
            param = [p_gain,I_GAIN,D_GAIN,0]                #paramを更新（Pgainを更新）
            pid.update_params(param)                        #calc_PIDクラスにparamの変更を反映
            #print(i,j,state_current[0][0],ti)
            
            #操作量をPID計算
            #state_currentはFRAMES個の状態を保持
            #state_current[0]が最新の状態で、state_current[0][0]が最新の状態におけるYaw角
            #delta_timeは微積分の近似で用いる時間幅
            #modeはSaturationブロック有効化を決めるフラグ
            diff = pid.calculate_output(current_value=int(state_current[0][0]), delta_time= (int)(ti), mode=True)

            if diff > 0:                            #操作量が正なら…
                actions[0] = pwm_def - diff         #右側のモータ出力を下げる
                actions[1] = pwm_def - ER           #ER=0なので気にしなくて良い
            else:                                   #操作量が負なら…
                actions[0] = pwm_def                
                actions[1] = pwm_def + diff - ER    #左側のモータ出力を下げる

            if training_flag:                       #学習を行う場合…
                agent.epsilon -= 0.1/3000           #ランダム行動確率を下げていく。
            else:                                   #学習を行わない場合…
                agent.epsilon = 0                   #ランダム行動はさせない。
            env.execute_action_(actions)            #機体にモータ出力の変更内容を送信

            """
            if (j != 0 and training_flag == True):
                agent.experience_replay()           #経験再生
            """

            #新たな状態を観測
            #state_next:新たな状態が1つ加わり、古い状態が削除されたもの
            #更新されたstateデック、受信した時間、前回受信との間隔が返ってくる
            #state_next, ti, ti_ = env.observe_update_state_pid(pid=p_gain)
            state_next, ti, ti_ = env.observe_update_state_pid_2(pid=p_gain) 

            reward = env.observe_reward(state_next)     #Yaw角の0.0度からのずれに基づいた報酬を観測

            #経験保存

            #agent.store_experience(state_current, action, reward, state_next, terminal)
            agent.store_transition(state_current,action,reward, state_next,terminal)

            print(i,j,state_next[0], reward, pid.I*I_GAIN)

            if (j != 0 and training_flag == True):
                #agent.experience_replay()           #経験再生(NNパラメータのミニバッチ学習を行う)
                agent.learn()
            

            
            # for loging
            log.add_log_state_and_action(state_next, action, env.params_to_send, ti, ti_)
            log.add_log_state(state_next, reward, ti)

#except :
#except KeyboardInterrupt:
    #print("except finish")
    #print(state_current)
    #print(state_next)

    env.execute_action_([0,0])
    env.execute_action_([0,0])
    env.execute_action_([0,0])
    agent.save_model()
    agent.debug_nn()            #tf1のままなので動かない
    agent.debug_memory()
    agent.debug_minibatch()
    agent.debug_q()
    agent.debug_loss()
    log.output_log()

    
    loss = agent.check_loss()
    log.loss_graph(loss)
    log.angle_graph()

    vi.visualize()
    mi.visualize()
    ac.visualize()

    print("finish")