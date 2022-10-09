#tensorflow 2

from msilib.schema import tables
import os
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.models import load_model
#from tensorflow.keras.models import load_model
from collections import deque
from datetime import datetime
from matplotlib import pyplot as plt

#import tensorflow.compat.v1 as tf
#tf.disable_v2_behavior()
tf.get_logger().setLevel("ERROR")
import numpy as np
import csv
import time
import random

import warnings
warnings.filterwarnings('ignore')
import time
import os

#--------------------------const, directory name, model name, etc...-------------------------
MODEL_NAME = "WiflyDual_DQN"# + str(datetime.today())[0:10]
MODEL_DIRECTORY = os.path.join(os.path.dirname(os.path.abspath(__file__)), "models")
CHECKPOINT_NAME = "WiflyDual_DQN"

#適用手法選択
PER = False
DUELING = False
DOUBLE = False

#行動空間設定
N_ACTIONS = 5
ENABLE_ACTIONS = [i for i in range(N_ACTIONS)]

#hyperparameter for DQN
LEARNING_RATE = 0.02
DISCOUNT_FACTOR = 0.95
MINIBATCH_SIZE = 32
REPLAY_MEMORY_SIZE = 10000
EPSILON = 0.1
EPSILON_DEC = 1e-3
EPSILON_END = 0.01
KEEP_FRAMES = 4
STATE_VARIABLES = 7     #状態変数の数
COPY_PERIOD = 20
HIDDEN_1 = 30           
HIDDEN_2 = 30

#for PER
ALPHA = 0.4
BETA = 0
BETA_INCREMENT = 0
LEARNING_PERIOD = 1
MARGIN = 0.0001     #優先度が0になるのを防ぐための定数

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

class ReplayBuffer_PER():
    write = 0   #葉ノード追加の回数
    
    def __init__(self, capacity,input_dims,keep_frames):
        self.capacity = capacity                         #Sumtreeの葉の最大数（格納できる要素の数）
        self.tree = np.zeros(2*capacity - 1)             #葉を含む全ノードの値を保持
        self.data = np.zeros(capacity, dtype = object)   #葉に対応する要素を保持
        """
        self.state_memory = np.zeros((capacity,keep_frames,input_dims),       
                                            dtype=np.float32)
        self.new_state_memory = np.zeros((capacity,keep_frames,input_dims), 
                                dtype=np.float32)
        self.action_memory = np.zeros(capacity, dtype=np.int32)
        self.reward_memory = np.zeros(capacity, dtype=np.float32)
        self.terminal_memory = np.zeros(capacity, dtype=np.int32)
        """
    #子ノードの更新を親ノードに伝搬
    def _back_propagate(self, idx, change):
        #親ノードの添え字(parent)と子ノードの添え字の関係
        parent = (idx - 1) // 2

        #親ノードの値を更新
        self.tree[parent] += change

        #更新した親ノードがrootでない場合は、伝搬&更新を続ける
        if parent != 0:
            #print(parent , end = "")
            self._back_propagate(parent, change)

    def _retrieve(self, idx, s):
        #今いるノードから見た左右ノードの番号
        left = 2 * idx + 1
        right = left + 1

        #子ノードがない場合は、現在のidxを返す。
        if left >= len(self.tree):
            return idx

        #子ノードがある場合は、左右のノードの数字と比較して、
        #左右どちらかのノードに移動
        if s <= self.tree[left]:
            return self._retrieve(left, s)
        else:
            return self._retrieve(right, s-self.tree[left])

    #root_nodeの値を返す
    def total_p(self):
        return self.tree[0]

    #treeに要素（葉）を追加する
    def add(self, data, p):
        #追加された要素（葉）の値をtreeリストの何番目に書き込むか
        #葉でないノードはself.capacity - 1個存在するので、それ以降の番目に書き込む。
        idx = self.write + (self.capacity - 1)

        #追加された要素（名前etc）を保持
        self.data[self.write] = data

        #葉と各ノードの値を更新する
        #idxは今いる葉のtree_list中での位置に相当する
        self.update(idx, p)
        self.write += 1
        if self.write >= self.capacity:
            self.write = 0

    #要素の追加に伴う葉ノードの値変更（初期値は0）&親ノードへの伝搬を開始
    def update(self, idx, p):
        #値の変化量を記録
        change = p - self.tree[idx]

        #葉の値を更新
        self.tree[idx] = p

        #葉の値の変化を親ノードに伝搬する
        self._back_propagate(idx, change)

    #サンプリング
    def get(self, s):
        idx = self._retrieve(0, s)              #0は親ノードから辿ることを意味する
        dataIdx = idx - (self.capacity - 1)     #葉ノードのみを考えた場合の添え字

        #葉ノード番号、優先度、対応する要素を返す
        return (dataIdx, self.tree[idx], self.data[dataIdx])

        #サンプリング要素のtreeリストにおける位置、優先度、要素名を返す。
        #return (idx, self.tree[idx], self.data[dataIdx])

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
        keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層1
        keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層2
        keras.layers.Dense(n_actions, activation = None, kernel_initializer = "he_normal")])       #出力層
    
    #最適化アルゴリズム、誤差関数を指定する
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')

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
        self.per = PER
        self.dueling = DUELING
        self.double = DOUBLE

        #行動空間
        self.action_space = ENABLE_ACTIONS
        self.n_action = N_ACTIONS

        #vanilla-DQN
        #self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,STATE_VARIABLES)   #ReplayBufferクラスのインスタンス作成
        self.learning_rate = LEARNING_RATE
        self.gamma = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.eps_dec = EPSILON_DEC                 
        self.eps_min = EPSILON_END
        self.batch_size = MINIBATCH_SIZE
        self.mem_size = REPLAY_MEMORY_SIZE
        self.num_in_buffer = 0
        self.keep_frames = KEEP_FRAMES
        self.state_variables = STATE_VARIABLES
        self.copy_period = COPY_PERIOD
        self.hidden_1 = HIDDEN_1
        self.hidden_2 = HIDDEN_2
        
        #各ネットワークのモデル保存名
        self.q_eval_model_file = "q_eval.h5"
        self.q_target_model_file = "q_target.h5"
        self.v_eval_model_file = "v_eval.h5"
        self.v_target_model_file = "v_target.h5"
        self.adv_eval_model_file = "adv_eval.h5"
        self.adv_target_model_file = "adv_target.h5"

        #PER
        self.memory_per = ReplayBuffer_PER(self.mem_size,self.state_variables,self.keep_frames)    
        self.p_initial = 1                                          #経験を保存する際の優先度（最大値）
        self.margin = MARGIN                                        #サンプリング確率が0になることを防ぐ定数
        self.alpha = ALPHA                                          #サンプリング確率に対する優先度の重視度を表すパラメータ
        if self.per:
            self.beta = BETA                                          #優先度付きサンプリングによるバイアスの修正具合を表すパラメータ
            self.beta_increment = BETA_INCREMENT                        #betaを増加させる量
        else:
            self.beta = 0
            self.beta_increment = 0
        
        self.is_weight = np.power(self.mem_size,-self.beta)         #重点サンプリング重みの初期値
        self.learning_period = LEARNING_PERIOD
        self.past_states = 0
        self.past_q_target = 0

        self.global_step = 0

        #log用
        self.log_states = []                    #状態のlog
        self.log_yaw_angle = []
        self.minibatch_index_log = np.empty(0)  
        self.log_q = []                         #行動価値関数Qのlog
        self.log_act = []                       #行動aのlog
        self.log_minibatch_index = []           #ミニバッチに採用された遷移reply_buffer内のindex
        self.log_loss = []                      #損失関数のlog
        self.log_v = []                         #NNの状態価値関数Vのlog
        self.log_adv = []                       #NNのアドバンテージ関数Aのlog
        self.log_p = []
        #self.epsilon_act = 0
        #self.action_old = 0

        self.folder = folder

        #NNの構築
        #Dueling or Normal
        if self.dueling:
            self.q_eval,self.v_eval,self.adv_eval = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.v_target, self.adv_target = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        else:
            self.q_eval, self.v_eval,self.adv_eval = build_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_dqn(LEARNING_RATE, N_ACTIONS, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        # create TensorFlow graph (model)(tf1)
        #self.init_model()

        # reset current loss
        self.current_loss = 0.0

        #ダミーデータ処理
        #predict_on_batchやtrain_on_batchの初回呼び出しが遅いので、先に呼び出しておく。
        self.NN_avoid_overhead()

        #学習の経過を記録
        self.episode = 0                #episode
        self.episode_in_advance = 0     #事前に学習済みのエピソード数
        self.trained_episode = 0        #学習済みのエピソード数の合計
        self.trained_step = 0           #学習済みのステップ数


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

    def NN_avoid_overhead(self):
        data_dummy = np.array([[[0]*self.state_variables]*self.keep_frames]*self.batch_size)
        buf1 = self.q_eval.predict_on_batch(data_dummy)
        buf2 = self.q_target.predict_on_batch(data_dummy)
        buf3 = np.copy(self.q_eval)
        self.q_eval.train_on_batch(data_dummy, buf1)
        self.q_eval.set_weights(self.q_eval.get_weights())
        self.q_target.set_weights(self.q_target.get_weights())
        buf4 = self.memory_per.total_p()
        buf5 = np.empty((self.batch_size,1))
        if self.dueling:
            buf6 = self.v_eval.predict_on_batch(data_dummy)
            buf7 = self.adv_eval.predict_on_batch(data_dummy)

    def _per_loss(self, y_target, y_pred):
        #return tf.reduce_mean(self.is_weight * tf.math.squared_difference(y_target, y_pred))
        huber_loss = tf.keras.losses.Huber()
        return tf.reduce_mean(self.is_weight * huber_loss(y_target, y_pred))

    def choose_action(self, keep_states):
        """
        ε-greedy方策による行動選択
        """
        #print(keep_states)
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
        self.log_states.append(list(keep_states))
        
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
    
    def store_transition_with_priority(self, state, action, reward, state_, done):

        #一番最初の遷移を保存する際は、優先度をp_initial(=1)とする。
        #それ以降は、保存されているもののうち、最大のものとする。
        if self.global_step == 0:
            print("Initial storing")
            priority = self.p_initial
        else:
            priority = np.max(self.memory_per.tree[-self.memory_per.capacity:])
        
        transition = [state, action, reward, state_, done]              #遷移をリストにまとめる
        self.memory_per.add(transition, priority)                       #遷移を優先度ともに保存する。
        self.num_in_buffer = min(self.num_in_buffer + 1, self.mem_size) #保存されている経験の数を記録
        #print(self.memory_per.tree[self.memory_per.capacity - 1:])
        #print(self.memory_per.tree[0])

    def sample_buffer_per(self,batch_size):
        
        #betaを更新
        self.beta = min(1., self.beta + self.beta_increment)

        #各種ミニバッチ
        states = []
        states_ = []
        rewards = []
        actions = []
        terminal = []

        if self.per:
            #重要度サンプリング重みを格納するためのリスト
            is_weights = np.empty((batch_size, 1))

            #ミニバッチの要素として採用されたもののindexを格納するリスト
            idxes_batch = []

            #採用されたサンプルの優先度の履歴
            p_sampled = []

            # calculate max_weight
            min_prob = np.min(self.memory_per.tree[-self.memory_per.capacity:]) / self.memory_per.total_p()
            max_weight = np.power(self.mem_size * min_prob, -self.beta)

            #Sumtreeからのサンプル時に生成する乱数sの範囲を区切る。
            #これにより、サンプリング時の重複を抑えることができる（完全に防げてはいない?）。
            segment = self.memory_per.total_p() / batch_size

            #Sumtreeからのサンプリング+重要度サンプリング重みの計算
            for i in range(batch_size):
                s = np.random.uniform(segment * i, segment * (i + 1))
                idx_batch, p, transition = self.memory_per.get(s)
                
                idxes_batch.append(idx_batch)
                p_sampled.append(p)

                states.append(transition[0])
                actions.append(transition[1])
                rewards.append(transition[2])
                states_.append(transition[3])
                terminal.append(1-transition[4])

                #self.b_obs[i], self.b_actions[i], self.b_rewards[i], self.b_next_states[i], self.b_dones[i] = t
                # P(j)
                sampling_probabilities = p / self.memory_per.total_p()     # where p = p ** self.alpha
                is_weights[i, 0] = np.power(self.mem_size * sampling_probabilities, -self.beta) / max_weight
        #print(idxes_batch)
        else:
            #idxes_batch = np.random.choice(self.num_in_buffer, batch_size, replace = False)
            idxes_batch = random.sample(range(self.num_in_buffer), batch_size)
            transitions = self.memory_per.data[idxes_batch]
            print(transitions.shape)
            for tran in transitions:
                states.append(tran[0])
                actions.append(tran[1])
                rewards.append(tran[2])
                states_.append(tran[3])
                terminal.append(1 - tran[4])
            p_in_tree = self.memory_per.tree[-self.memory_per.capacity:]
            p_sampled = p_in_tree[idxes_batch]
            is_weights = [[1] for i in range(batch_size)]

        return np.array(states), actions, rewards, np.array(states_),terminal, idxes_batch ,is_weights, p_sampled

    def update_priorities(self, priorities,idxes):
        #print("sampled index" + str(idxes))
        #print(self.memory_per.tree[0])
        for idx, p in zip(idxes, priorities):
            #print(idx)
            self.memory_per.update(idx + (self.memory_per.capacity - 1), p)
            #pprint(self.memory_per.data)
            #print("update")
        #print("tree_total" + str(self.memory_per.tree[0]))
        #exit()
        
    def learn(self):
        """
        NNの重みとバイアスを学習
        """
        #保存された経験が足りない場合は学習しない
        if self.num_in_buffer < self.batch_size:
            #self.global_step += 1
            return
        #各種ミニバッチ作成
        #states, actions, rewards, states_, dones, batch_idxes = self.memory.sample_buffer(self.batch_size)
        states, actions, rewards, states_, dones, batch_idxes, self.is_weight, ps = self.sample_buffer_per(self.batch_size)

        #minibatch_indexのlog格納
        self.log_minibatch_index.append(batch_idxes)
        self.log_p.append(ps)

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

        #優先度pの更新
        #clipped error(安定性のためにTDerrorを-1~1にクリッピング(論文にも書かれている))
        abs_td_error_list = np.abs(q_target[batch_index, actions] - q_eval[batch_index, actions]) + self.margin
        clipped_error = np.where(abs_td_error_list < 1, abs_td_error_list, 1)
        p_list = np.power(clipped_error, self.alpha)
        #print(p_list)
        self.update_priorities(p_list,batch_idxes)

        time_start3 = time.time()
        #NNのパラメータ更新
        if self.global_step % self.learning_period == 0 or self.num_in_buffer == self.batch_size:
            loss = self.q_eval.train_on_batch(states, q_target)
            self.log_loss.append(loss)
            self.past_states = np.copy(states)
            self.past_q_target = np.copy(q_target)
        else:
            loss = self.q_eval.train_on_batch(self.past_states, self.past_q_target)
            self.log_loss.append(loss)
        
        #self.log_loss.append(self.q_eval.train_on_batch(states, q_target))
        #loss = self.q_eval.train_on_batch(states, q_target)
        #self.log_loss.append(loss)
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
            self.q_target.set_weights(self.q_eval.get_weights())

        #print(loss)
        #print("time:" + str(a-time_start) + " , " + str(time_start2-time_start) + " , "  + str(time_start3-time_start2) + " , "  + str(a-time_start3))
        #self.epsilon = self.epsilon - self.eps_dec if self.epsilon > self.eps_min else self.eps_min

    def get_angle(self,states):
        self.log_yaw_angle.append(float(states[0][5]))

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

    def load_saved_NN(self, save_dir):
        self.q_eval = load_model(save_dir + self.q_eval_model_file, custom_objects = {"_per_loss": self._per_loss})
        self.q_target = load_model(save_dir + self.q_target_model_file, custom_objects = {"_per_loss":self._per_loss})
        if self.dueling:
            self.v_eval = load_model(save_dir  + self.v_eval_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.v_target = load_model(save_dir + self.v_target_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.adv_eval = load_model(save_dir + self.adv_eval_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.adv_target = load_model(save_dir + self.adv_target_model_file, custom_objects = {"_per_loss":self._per_loss})

    def save_NN_model(self, filepath):
        self.q_eval.save(filepath + "/" + self.q_eval_model_file)
        self.q_target.save(filepath + "/" + self.q_target_model_file)
        if self.dueling:
            self.v_eval.save(filepath + "/" +self.v_eval_model_file)
            self.v_target.save(filepath + "/"+  self.v_target_model_file)
            self.adv_eval.save(filepath + "/" + self.adv_eval_model_file)
            self.adv_target.save(filepath + "/" + self.adv_target_model_file)

    def save_param(self,filepath):
        with open(filepath + "/trained_episode.txt", mode = "w") as name:
            print(self.trained_episode, file = name)
        with open(filepath + "/trained_step.txt", mode = "w") as name:
            print(self.trained_step, file = name)
        with open(filepath + "/epsilon.txt", mode = "w") as name:
            print(self.last_epsilon, file = name)
        with open(filepath + "/num_in_buffer.txt", mode = "w") as name:
            print(self.num_in_buffer, file = name)
        if self.per:
            with open(filepath + "/beta.txt", mode  = "w") as name:
                print(self.last_beta, file = name)

    def buffer_param(self, filepath):
        #最新のエピソード終了時の変数を記録
        self.last_epsilon = self.epsilon
        self.trained_episode = self.episode + self.episode_in_advance
        self.trained_step = self.global_step
        self.last_num_in_buffer = self.num_in_buffer
        if self.per:
            self.last_beta = self.beta
        np.save(filepath + "/tree", self.memory_per.tree)
        np.save(filepath + "/data", self.memory_per.data)

    def debug_memory(self):
        with open(self.folder + '/debug_memory.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.log_states)

    def debug_minibatch(self):
        #print(self.minibatch_ind)
        np.savetxt(self.folder + '/debug_minibatch.csv', self.minibatch_index_log, delimiter=',', fmt='%s')

    def debug_minibatch_2(self):
        with open(self.folder + "/minibatch_index_log.csv", mode = "w", newline = "") as f1:
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
    
    def debug_p(self):
        with open(self.folder + '/debug_p.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.log_p)

    def debug_yaw(self):
        with open(self.folder + '/debug_yaw.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerow(list(self.log_yaw_angle))

    def hyper_params(self):
        with open(self.folder + "/hyper_param.txt", mode = "w") as name:
            print("dueling:" + str(DUELING), file = name)
            print("double:" + str(DOUBLE), file = name)
            print("lr:%f" % LEARNING_RATE, file = name)
            print("df:%f" % DISCOUNT_FACTOR, file = name)
            print("ep:%f" % EPSILON, file = name)
            print("ep_end:%f" % EPSILON_END, file = name)
            print("ep_dec:%f" % EPSILON_DEC, file = name)
            print("RM_size:%d" % REPLAY_MEMORY_SIZE, file = name)
            print("MB_size:%d" % MINIBATCH_SIZE, file = name)
            print("CP:%d" % COPY_PERIOD, file = name)
            print("hidden_1:%d" % HIDDEN_1, file = name)
            print("hidden_2:%d" % HIDDEN_2, file = name)
            if self.per:
                print("alpha:%f" % ALPHA, file = name)
                print("beta:%f" % BETA, file = name)
                print("beta_increment:%f" % BETA_INCREMENT, file = name)
                print("lp:%d" % LEARNING_PERIOD, file = name)

    def debug_loss(self):
        with open(self.folder + '/debug_loss.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            print(type(self.log_loss))
            print(self.log_loss)
            writer.writerows(list(self.log_loss))

    def check_loss(self):
        return self.log_loss