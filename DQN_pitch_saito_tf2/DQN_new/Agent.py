#tensorflow 2

import os
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.optimizers import Adam
#from tensorflow.keras.models import load_model
from collections import deque
from datetime import datetime

#import tensorflow.compat.v1 as tf
#tf.disable_v2_behavior()
tf.get_logger().setLevel("ERROR")
import numpy as np
import csv
import time

import warnings
warnings.filterwarnings('ignore')

import time

import os
#--------------------------const, directory name, model name, etc...-------------------------
MODEL_NAME = "WiflyDual_DQN"# + str(datetime.today())[0:10]
MODEL_DIRECTORY = os.path.join(os.path.dirname(os.path.abspath(__file__)), "models")
CHECKPOINT_NAME = "WiflyDual_DQN"

#適用手法選択
DUELING = False
DOUBLE = False

#行動空間設定
ENABLE_ACTIONS = [0,1,2,3,4,5]
N_ACTIONS = len(ENABLE_ACTIONS)

#hyperparameter各種
LEARNING_RATE = 0.05
DISCOUNT_FACTOR = 0.95
MINIBATCH_SIZE = 64
REPLAY_MEMORY_SIZE = 10000
EPSILON = 0.1
EPSILON_DEC = 1e-3
EPSILON_END = 0.01
KEEP_FRAMES = 4
STATE_VARIABLES = 7     #状態変数の数
COPY_PERIOD = 50
HIDDEN_1 = 30           
HIDDEN_2 = 30

#----------------------------------------------------------------------------------------------

class ReplayBuffer():
    def __init__(self, max_size, input_dims):
        self.mem_size = max_size
        self.mem_cntr = 0           #保存した経験の数をカウントする

        #各リプレイメモリーの初期化
        #state_memoryとnew_state_memoryは3次元arrayであることに注意
        self.state_memory = np.zeros((self.mem_size,KEEP_FRAMES,input_dims),       
                                    dtype=np.float32)
        self.new_state_memory = np.zeros((self.mem_size,KEEP_FRAMES,input_dims),   
                                dtype=np.float32)
        self.action_memory = np.zeros(self.mem_size, dtype=np.int32)
        self.reward_memory = np.zeros(self.mem_size, dtype=np.float32)
        self.terminal_memory = np.zeros(self.mem_size, dtype=np.int32)

    def sample_buffer(self, batch_size):
        max_mem = min(self.mem_cntr, self.mem_size)

        #0~max_mem-1までの整数乱数batch_size個取得（重複無し）
        batch = np.random.choice(max_mem, batch_size, replace=False)

        #state_memory[batch]とすると、state_memoryのうち、batchの要素と一致する添え字だけが抜き出されたリストが得られる。
        #つまり、各メモリーから乱数で選ばれた番号の要素を抜き出している（ミニバッチの作成）
        states = self.state_memory[batch]
        states_ = self.new_state_memory[batch]
        rewards = self.reward_memory[batch]
        actions = self.action_memory[batch]
        terminal = self.terminal_memory[batch]

        return states, actions, rewards, states_, terminal, batch

    def store_transition(self, state, action, reward, state_, done):
        
        #mem_cntrは保存した経験の数
        #mem_sizeを超えると、古いものから上書きされていく。
        index = self.mem_cntr % self.mem_size

        #それぞれを各メモリのindexに保存
        #terminalはbool型ではなく0,1で保存
        #終状態の場合、すなわちdone=Trueの場合に0を保存
        #これにより、終状態におけるTDターゲットにおいて、Q関数部分を0にできる
        self.state_memory[index] = state
        self.new_state_memory[index] = state_
        self.reward_memory[index] = reward
        self.action_memory[index] = action
        self.terminal_memory[index] = int(done)

        self.mem_cntr += 1      #保存した経験の数をカウント

def build_dqn(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    """
    NNの作成
    -NNの入力:4つの状態（Qを求めたい状態sとその3フレーム前までの3つの状態を合わせた合計4つの状態）
    -NNの出力:状態sにおける各Q
    -state dequeの先頭に状態sが入っている
    """

    #Sequential API
    model = keras.Sequential([

        #Denseは全結合ユニット
        #Denseの引数:ユニット数、（入力層のユニット数）、活性化関数
        #入力のユニット数の指定には、"input_dim="と"input_shape="があるらしい。
        keras.layers.Input(shape = (keep_frames,input_dims,)),  #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
        keras.layers.Flatten(),                                 #平滑化‼
        keras.layers.Dense(fc1_dims, activation='relu'),        #中間層1
        keras.layers.Dense(fc2_dims, activation='relu'),        #中間層2
        keras.layers.Dense(n_actions, activation=None)])        #出力層
    
    #最適化アルゴリズム、誤差関数を指定する
    model.compile(optimizer=Adam(learning_rate=lr), loss ='huber_loss')

    model.summary()     #構築されたモデルの情報を表示
    return model,0,0    #Dueling_Networkと返り値の数を合わせている。

def build_dueling_dqn(lr, n_actions, input_dims, keep_frames, fc1_dims, fc2_dims):
    """
    dueling networkの作成
    """
    
    #Functional API
    #まず順伝搬を定義していく。
    x = keras.layers.Input(shape = (keep_frames,input_dims,))    #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
    f = keras.layers.Flatten()(x)                                  #平滑化‼
    
    """
    #案1 2層共有
    h = keras.layers.Dense(fc1_dims, activation='relu', kernel_initializer = 'he_normal')(f)    #中間層1(入力層の情報を加えてあるので要確認)
    h = keras.layers.Dense(fc2_dims, activation='relu', kernel_initializer = 'he_normal')(h)    #中間層2

    V = keras.layers.Dense(1, activation=None, kernel_initializer = 'he_normal')(h)             #V(s)出力
    A = keras.layers.Dense(n_actions, activation=None, kernel_initializer = 'he_normal')(h)     #A(s,a)出力

    #q = keras.layers.Add()([V, A - tf.math.reduce_mean(A, axis = 1, keepdims = True)])
    #q = keras.layers.Add()([V, A - tf.stop_gradient(tf.math.reduce_mean(A, axis = 1, keepdims = True))])
    #Q = keras.layers.Dense(n_actions)(q)

    Q = V +  A - tf.math.reduce_mean(A, axis = 1, keepdims = True)
    """
    
    #案2 1層のみ共有
    h = keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = 'he_normal')(f)    #中間層1(入力層の情報を加えてあるので要確認)
    v_dense = keras.layers.Dense(fc2_dims//2, activation ='relu', kernel_initializer = 'he_normal')(h)
    a_dense = keras.layers.Dense(fc2_dims//2, activation = 'relu', kernel_initializer = 'he_normal')(h)
    
    V = keras.layers.Dense(1, activation = None, kernel_initializer = 'he_normal')(v_dense)                 #V(s)出力
    A = keras.layers.Dense(n_actions, activation = None, kernel_initializer = 'he_normal')(a_dense)         #A(s,a)出力
    q = keras.layers.Add()([V, A - tf.stop_gradient(tf.math.reduce_mean(A, axis = 1, keepdims = True))])    #V,Aを合成
    #q = keras.layers.Add()([V, A - tf.math.reduce_mean(A, axis = 1, keepdims = True)])                     #tf.stop_gradientなしver
    Q = keras.layers.Dense(n_actions, activation = None)(q)                                                 #Q(s,a)出力

    #Q,V,Aを出力とするモデルを作成(V,Aはlog用)
    #入力と出力を指定すると、上で定義した順伝搬ネットワークができる。
    model_Q = keras.Model(inputs = [x], outputs = [Q])
    model_V = keras.Model(inputs = [x], outputs = [V])
    model_A = keras.Model(inputs = [x], outputs = [A])

    """
    #最適化アルゴリズム、誤差関数を指定する
    model_Q.compile(optimizer = Adam(learning_rate=lr), loss='huber_loss')
    model_V.compile(optimizer = Adam(learning_rate=lr), loss='huber_loss')
    model_A.compile(optimizer = Adam(learning_rate=lr), loss='huber_loss')
    """

    #最適化アルゴリズム、誤差関数を指定する
    model_Q.compile(optimizer = Adam(learning_rate=lr), loss='huber_loss')
    model_Q.summary()

    return model_Q, model_V, model_A


class DQNAgent:
    def __init__(self, folder='log'):
        #ファイル関係
        self.name = os.path.splitext(os.path.basename(__file__))[0] #このスクリプトの拡張子を含まないファイル名を取得
        self.path = os.path.dirname(__file__)                       #このスクリプトのディレクトリを取得
        self.model_dir = MODEL_DIRECTORY
        self.model_name = MODEL_NAME
        self.checkpoint_name = CHECKPOINT_NAME

        #適用手法のフラグ
        self.dueling = DUELING
        self.double = DOUBLE

        #行動空間
        self.action_space = ENABLE_ACTIONS
        self.n_action = N_ACTIONS

        self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,STATE_VARIABLES)   #ReplayBufferクラスのインスタンス作成
        self.learning_rate = LEARNING_RATE
        self.gamma = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.eps_dec = EPSILON_DEC                 
        self.eps_min = EPSILON_END
        self.batch_size = MINIBATCH_SIZE
        self.keep_frames = KEEP_FRAMES
        self.copy_period = COPY_PERIOD
        self.hidden_1 = HIDDEN_1
        self.hidden_2 = HIDDEN_2
        
        self.global_step = 0

        #log用
        self.log_states = []                    #状態のlog
        self.minibatch_index_log = np.empty(0)  
        self.log_q = []                         #行動価値関数Qのlog
        self.log_act = []                       #行動aのlog
        self.log_minibatch_index = []           #ミニバッチに採用された遷移reply_buffer内のindex
        self.log_loss = []                      #損失関数のlog
        self.log_v = []                         #NNの状態価値関数Vのlog
        self.log_adv = []                       #NNのアドバンテージ関数Aのlog
        #self.epsilon_act = 0
        #self.action_old = 0

        self.folder = folder

        #NNの構築
        #Dueling or Normal
        if self.dueling:
            self.q_eval,self.v_eval,self.adv_eval = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES,KEEP_FRAMES,HIDDEN_1, HIDDEN_2)
            self.q_target, self.v_target, self.adv_target = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES,KEEP_FRAMES,HIDDEN_1, HIDDEN_2)
        else:
            self.q_eval, self.v_eval,self.adv_eval = build_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, HIDDEN_1, HIDDEN_2)
        # create TensorFlow graph (model)(tf1)
        #self.init_model()

        # reset current loss
        self.current_loss = 0.0

        #ダミーデータ処理
        #predict_on_batchやtrain_on_batchの初回呼び出しが遅いので、先に呼び出しておく。
        data_dummy = np.array([[[0]*STATE_VARIABLES]*self.keep_frames]*self.batch_size)
        buf1 = self.q_eval.predict_on_batch(data_dummy)
        buf2 = self.q_target.predict_on_batch(data_dummy)
        buf3 = np.copy(self.q_eval)
        self.q_eval.train_on_batch(data_dummy, buf1)
        self.q_eval.set_weights(self.q_eval.get_weights())
        self.q_target.set_weights(self.q_target.get_weights())

        if self.dueling:
            buf4 = self.v_eval.predict_on_batch(data_dummy)
            buf5 = self.adv_eval.predict_on_batch(data_dummy)
    """
    def build_dqn(lr, n_actions, input_dims, fc1_dims, fc2_dims):
        
        #NNの作成
        
        model = keras.Sequential([

            #Denseは全結合ユニット
            #ユニット数、（入力層のユニット数）、活性化関数が引数
            #入力のユニット数の指定には、input_dim=とinput_shape=があるらしい。
            keras.layers.Dense(fc1_dims, input_shape=(input_dims,), activation='relu'), #中間層1(入力層の情報を加えてあるので要確認)
            keras.layers.Dense(fc2_dims, activation='relu'),                            #中間層2
            keras.layers.Dense(n_actions, activation=None)])                            #出力層
        
        #最適化アルゴリズム、誤差関数を指定する
        model.compile(optimizer=Adam(learning_rate=lr), loss='mean_squared_error')

        return model
    """

    def choose_action(self, keep_states):
        """
        ε-greedy方策による行動選択
        """

        #行動log用変数
        log_action_buffer = []      #(行動番号, 行動の選び方)のtupleを作成
        random_action_flag = 0      #random行動が選択された場合は1,argmaxQ行動が選択された場合は0

        states = np.array([keep_states])         #観測された状態をリスト化

        #NNからstateにおける各行動に対する行動価値関数の推定値を受け取る。
        #NNのモデルに対しpredict_on_batchメソッドを実行すると、出力される。
        Q_values = self.q_eval.predict_on_batch(states)

        #行動選択
        if np.random.random() < self.epsilon:
            random_action_flag = 1
            action = np.random.choice(self.action_space)
            """
            self.log_qvalue.append([])
            if self.dueling:
                self.log_v.append([])
                self.log_adv.append([])
            """
        else:            
            action = np.argmax(Q_values)             #行動価値が最大である行動を選択     

        #NNから出力されるQ値のlogを格納
        #predict_on_batchの返り値は[[a,b,c,d]]のように2重リストになっているので、アンパックしておく。
        self.log_q.append(*Q_values)
        if self.dueling:
            V_value = self.v_eval.predict_on_batch(states)
            Adv_value = self.adv_eval.predict_on_batch(states)
            self.log_v.append(*V_value)
            self.log_adv.append(*Adv_value)

        #状態log格納
        self.log_states.append(keep_states)
        
        #行動log格納
        log_action_buffer.append(action)
        log_action_buffer.append(random_action_flag)
        self.log_act.append(log_action_buffer)

        return action

    def select_action_epsilon(self, state, act_count=0):
        """
        行動決定(方策)
        Args:
            state ([deque]): 状態(nフレーム)
        Returns:
            [int]: 決定した行動の番号
        """
        a = self.Q_values(state)
        self.log_q.append(a)
        if self.epsilon_act == 0:
            if np.random.rand() <= self.epsilon:
                # random
                act = np.random.choice(self.enable_actions)
                self.action_old = act
                self.epsilon_act = act_count
            else:
                # max_action Q(state, action)
                act = self.enable_actions[np.argmax(a)]
        else:
            act = self.action_old
            self.epsilon_act -= 1
            
        self.log_act.append([act])
        return act
    
    def select_action_limit(self, state):
        """
        行動決定(方策)
        Args:
            state ([deque]): 状態(nフレーム)
        Returns:
            [int]: 決定した行動の番号
        """
        a = self.Q_values(state)
        self.log_q.append(a)
        angle = float(state[0][0])
        if angle<-45:
            return 6
        elif angle>45:
            return 7
        elif np.random.rand() <= self.epsilon:
            # randomstore_transition
            act = np.random.choice(self.enable_actions)
        else:
            # max_action Q(state, action)
            act = self.enable_actions[np.argmax(a)]
            
        self.log_act.append([act])
        return act

    # train the network by replaying experience

    def store_transition(self, state, action, reward, new_state, done):
        """
        経験の保存
        """
        self.memory.store_transition(state, action, reward, new_state, done)
        
    def learn(self):
        """
        NNの重みとバイアスを学習
        """
        #保存された経験が足りない場合は学習しない
        if self.memory.mem_cntr < self.batch_size:
            return
        #各種ミニバッチ作成
        states, actions, rewards, states_, dones, batch_idxes = self.memory.sample_buffer(self.batch_size)

        #minibatch_indexのlog格納
        self.log_minibatch_index.append(batch_idxes)

        #Fixed-Targetを実装
        #time_start = time.time()
        q_eval = self.q_target.predict(states)
        q_next = self.q_target.predict(states_)       
        #time_start2 = time.time()
        q_target = np.copy(q_eval)      #q_targetの値を書き換えて、教師データとしていく、

        #0~batch_size-1までの連番リストを取得
        batch_index = np.arange(self.batch_size, dtype = np.int32)

        #
        #Double or Fixed Target Network
        if self.double:
            a = np.argmax(q_eval, axis = 1)
            q_target[batch_index, actions] = rewards + self.gamma * q_next[batch_index,a] * dones
        else:
            q_target[batch_index, actions] = rewards + self.gamma * np.max(q_next, axis=1)* dones


        time_start3 = time.time()
        #NNのパラメータ更新
        #self.log_loss.append(self.q_eval.train_on_batch(states, q_target))
        loss = self.q_target.train_on_batch(states, q_target)
        self.log_loss.append(loss)
        """
        float_loss = loss.item()
        print(type(float_loss))
        self.log_loss.append(float_loss)
        """
        #print(self.log_loss)
        a = time.time()

        if (self.global_step % self.copy_period == 0):
            print("Copy Weight")
            '''
            self.q_eval.layers[0].set_weights(self.q_target.layers[0].get_weights())
            self.q_eval.layers[1].set_weights(self.q_target.layers[1].get_weights())
            self.q_eval.layers[2].set_weights(self.q_target.layers[3].get_weights())
            self.q_eval.layers[3].set_weights(self.q_target.layers[4].get_weights())
            '''
            self.target.set_weights(self.q_eval.get_weights())

        #print(loss)
        #print("time:" + str(a-time_start) + " , " + str(time_start2-time_start) + " , "  + str(time_start3-time_start2) + " , "  + str(a-time_start3))
        #self.epsilon = self.epsilon - self.eps_dec if self.epsilon > self.eps_min else self.eps_min


    def create_checkpoint(self):
        #self.saver.save(self.sess, os.path.join(self.model_dir, self.checkpoint_name + datetime.now().strftime('%H%M%S')))
        self.q_eval.save(self.folder + '/' + self.model_name + self.checkpoint_name + datetime.now().strftime('%H%M%S'))

    def load_model(self, model_path):
        # load from model_path
        #self.saver.restore(self.sess,os.path.join(self.model_dir, model_path))

        #保存されたデータが存在しているか確認（存在していればckptはTrue）
        #self.folderは"log"フォルダを指す
        ckpt = tf.train.get_checkpoint_state(self.folder + '/../' + model_path + '/')
        if ckpt:
            #データが読み込まれる
            #self.saver.restore(self.sess, self.folder + '/../' + model_path + '/' + MODEL_NAME)
            self.q_eval = keras.models.load_model(self.folder + '/../' + model_path + '/' + MODEL_NAME)
            return True
        else:
            return False

    def save_model(self):
        #self.saver.save(self.sess, os.path.join(self.model_dir, self.model_name))
        #self.saver.save(self.sess, self.folder + '/' + self.model_name)
        self.q_eval.save(self.folder + '/' + self.model_name)

    def debug_nn(self):
        l1 = self.q_eval.layers[0]
        l2 = self.q_eval.layers[1]
        l3 = self.q_eval.layers[2]
        l4 = self.q_eval.layers[3]
        with open(self.folder + '/debug.csv', 'a') as f:
            np.savetxt(f, l2.get_weights()[0])
            np.savetxt(f, l2.get_weights()[1])
            np.savetxt(f, l3.get_weights()[0])
            np.savetxt(f, l3.get_weights()[1])
            np.savetxt(f, l4.get_weights()[0])
            np.savetxt(f, l4.get_weights()[1])
        
        np.savetxt(self.folder + '/debug_W_fc1.csv', l2.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc1.csv', l2.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/debug_W_fc2.csv', l3.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc2.csv', l3.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/debug_W_out.csv', l4.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_out.csv', l4.get_weights()[1], delimiter=',')

    def debug_memory(self):
        with open(self.folder + '/debug_memory.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.memory.state_memory)

    def debug_minibatch(self):
        #print(self.minibatch_ind)
        np.savetxt(self.folder + '/debug_minibatch.csv', self.minibatch_index_log, delimiter=',', fmt='%s')

    def debug_minibatch_2(self):
        with open(self.folder + "minibatch_index_log.csv", mode = "w", newline = "") as f1:
            writer = csv.writer(f1)
            writer.writerows(self.log_minibatch_index)

    def debug_q(self):
        with open(self.folder + '/debug_q.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.log_q)
        with open(self.folder + '/debug_act.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.log_act)
        if self.dueling:
            with open(self.folder + '/debug_v.csv', 'w') as f:
                writer = csv.writer(f, lineterminator = '\n')
                writer.writerows(self.log_v)
            with open(self.folder + '/debug_adv.csv', 'w') as f:
                writer = csv.writer(f, lineterminator = '\n')
                writer.writerows(self.log_adv)

    def debug_loss(self):
        with open(self.folder + '/debug_loss.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            print(type(self.log_loss))
            print(self.log_loss)
            writer.writerows(list(self.log_loss))

    def check_loss(self):
        return self.log_loss