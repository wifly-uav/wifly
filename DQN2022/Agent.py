#tensorflow 2

from msilib.schema import tables
import os
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.models import load_model
#from keras.layers import Merge
#from tensorflow.keras.models import load_model
from collections import deque
from datetime import datetime
from matplotlib import pyplot as plt

from keras.utils import plot_model

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
N_ACTIONS = 6
ENABLE_ACTIONS = [i for i in range(N_ACTIONS)]

#hyperparameter for DQN
MINIBATCH_SIZE = 8
KEEP_FRAMES = 4
STATE_VARIABLES = 5     #状態変数の数(PWM,PWM,Yaw,Pgain,Igain)

LEARNING_RATE = 0.02
RND_LEARNING_RATE = 0.01
DISCOUNT_FACTOR = 0.95
REPLAY_MEMORY_SIZE = 30000
#EPSILON = 0.1          #モデルの変化を考慮して、スケジューリングをしない。
EPSILON = 0.1           #εの初期値
EPSILON_DEC = 0    #1000stepで1から0.1までεを減少させる。
EPSILON_END = 0.1       #εの最終的な値
COPY_PERIOD = 50
HIDDEN_1 = 10           
HIDDEN_2 = 10           #先行研究では5だが、Duelingでは2等分したいので偶数の10にする。

#for PER
ALPHA = 0.4
BETA = 0
BETA_INCREMENT = 0
LEARNING_PERIOD = 1 #
MARGIN = 0.0001     #優先度が0になるのを防ぐための定数

YAW_INDEX = 2

#----------------------------------------------------------------------------------------------

class ReplayBuffer():
    def __init__(self, max_size, input_dims, beta):
        self.mem_size = max_size
        self.mem_cntr = 0           #保存した経験の数をカウントする
        self.beta = beta

        #各リプレイメモリーの初期化
        #state_memoryとnew_state_memoryは3次元arrayであることに注意
        self.state_memory = np.zeros((self.mem_size,KEEP_FRAMES,input_dims),       
                                    dtype=np.float32)
        self.new_state_memory = np.zeros((self.mem_size,KEEP_FRAMES,input_dims),   
                                dtype=np.float32)
        self.action_memory = np.zeros(self.mem_size, dtype=np.int32)
        self.reward_memory = np.zeros(self.mem_size, dtype=np.float32)
        self.terminal_memory = np.zeros(self.mem_size, dtype=np.int32)
        self.dyaw_memory = np.zeros(self.mem_size, dtype=np.int32)

    def sample_buffer(self, batch_size):
        max_mem = min(self.mem_cntr, self.mem_size)

        if self.beta:
            #betaサンプリング
            batch = []
            while len(batch) != batch_size:
                beta_int = int(max_mem * np.random.beta(2,1))
                batch.append(beta_int)
                batch = list(set(batch))
        else:
            #0~max_mem-1までの整数乱数batch_size個取得（重複無し）
            batch = np.random.choice(max_mem, batch_size, replace=True)

        #state_memory[batch]とすると、state_memoryのうち、batchの要素と一致する添え字だけが抜き出されたリストが得られる。
        #つまり、各メモリーから乱数で選ばれた番号の要素を抜き出している（ミニバッチの作成）
        states = self.state_memory[batch]
        states_ = self.new_state_memory[batch]
        rewards = self.reward_memory[batch]
        actions = self.action_memory[batch]
        terminal = self.terminal_memory[batch]
        dyaw = self.dyaw_memory[batch]

        return states, actions, rewards, states_, terminal, batch, dyaw

    def store_transition(self, state, action, reward, state_, done, dyaw):
        
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
        self.terminal_memory[index] = int(1-done)
        self.dyaw_memory[index] = dyaw

        self.mem_cntr += 1      #保存した経験の数をカウント

    def save_buffer(self, folder):
        np.save(folder+'/state_memory.npy',self.state_memory)
        np.save(folder+'/new_state_memory.npy',self.new_state_memory)
        np.save(folder+'/reward_memory.npy',self.reward_memory)
        np.save(folder+'/action_memory.npy',self.action_memory)
        np.save(folder+'/terminal_memory.npy',self.terminal_memory)
        np.save(folder+'/dyaw_memory.npy',self.dyaw_memory)
        np.save(folder+'/mem_cntr.npy',np.array(self.mem_cntr))

    def load_buffer(self, folder):
        self.state_memory = np.load(folder+'/state_memory.npy')
        self.new_state_memory = np.load(folder+'/new_state_memory.npy')
        self.reward_memory = np.load(folder+'/reward_memory.npy')
        self.action_memory = np.load(folder+'/action_memory.npy')
        self.terminal_memory = np.load(folder+'/terminal_memory.npy')
        self.dyaw_memory = np.load(folder+'/dyaw_memory.npy')
        self.mem_cntr = np.load(folder+'/mem_cntr.npy')
        print(self.mem_cntr)
        
class ReplayBuffer_PER():
    def __init__(self, capacity,input_dims,keep_frames):
        self.write = 0                                   #葉ノード追加の回数
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

def build_lstm_dqn(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    tf.compat.v1.experimental.output_all_intermediates(True)
    #Sequential API
    model = keras.Sequential([
        keras.layers.Input(shape = (keep_frames,input_dims)),
        #keras.layers.Flatten(),                                 #平滑化‼
        keras.layers.LSTM(input_dims, input_shape=(keep_frames, input_dims), return_sequences=True, activation='relu'),
        #keras.layers.LSTM(input_dims, activation='relu'),
        keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層1
        keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層2
        keras.layers.Dense(n_actions, activation = None, kernel_initializer = "he_normal")])       #出力層
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')

    model.summary()     #構築されたモデルの情報を表示
    #plot_model(model,show_shapes=True, to_file='nn_model.png')
    return model,0,0    #Dueling_Networkと返り値の数を合わせている。

def build_dueling_dqn(lr, n_actions, input_dims, keep_frames, fc1_dims, fc2_dims):
    #Functional API
    #まず順伝搬を定義していく。
    x = keras.layers.Input(shape = (keep_frames,input_dims,))    #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
    f = keras.layers.Flatten()(x)                                  #平滑化‼
    
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

    #最適化アルゴリズム、誤差関数を指定する
    model_Q.compile(optimizer = Adam(learning_rate=lr), loss='huber_loss')
    model_Q.summary()

    return model_Q, model_V, model_A

def build_act_dqn(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    state_branch = keras.layers.Input(shape=(keep_frames,input_dims,))
    f_state_branch = keras.layers.Flatten()(state_branch)
    action_branch = keras.layers.Input(shape=(n_actions,))
    act_fc = keras.layers.Dense(keep_frames*input_dims, activation ='relu', kernel_initializer = 'he_normal')(action_branch)
    marged = keras.layers.Add()([f_state_branch, act_fc])
    fc1 = keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = 'he_normal')(marged)
    fc2 = keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = 'he_normal')(fc1)
    Q = keras.layers.Dense(2, activation = None)(fc2)

    model = keras.Model(inputs=[state_branch,action_branch], outputs=[Q])
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')
    model.summary()
    plot_model(model,show_shapes=True, to_file='nn_model.png')
    return model,0,0 

def build_rnd_dqn(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    state_branch = keras.layers.Input(shape=(keep_frames,input_dims,))
    f_state_branch = keras.layers.Flatten()(state_branch)
    reward_branch = keras.layers.Input(shape=(3,))
    reward_fc = keras.layers.Dense(keep_frames*input_dims, activation ='relu', kernel_initializer = 'he_normal')(reward_branch)
    marged = keras.layers.Add()([f_state_branch, reward_fc])
    fc1 = keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = 'he_normal')(marged)
    fc2 = keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = 'he_normal')(fc1)
    Q = keras.layers.Dense(n_actions, activation = None)(fc2)

    model = keras.Model(inputs=[state_branch,reward_branch], outputs=[Q])
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')
    model.summary()
    plot_model(model,show_shapes=True, to_file='nn_model.png')
    return model,0,0 

def build_condition_dqn(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    state_branch = keras.layers.Input(shape=(keep_frames,input_dims,))
    f_state_branch = keras.layers.Flatten()(state_branch)
    condition_branch = keras.layers.Input(shape=(1,))
    condition_fc = keras.layers.Dense(keep_frames*input_dims, activation ='relu', kernel_initializer = 'he_normal')(condition_branch)
    marged = keras.layers.Add()([f_state_branch, condition_fc])
    fc1 = keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = 'he_normal')(marged)
    fc2 = keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = 'he_normal')(fc1)
    Q = keras.layers.Dense(n_actions, activation = None)(fc2)

    model = keras.Model(inputs=[state_branch,condition_branch], outputs=[Q])
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')
    model.summary()
    plot_model(model,show_shapes=True, to_file='nn_model.png')
    return model,0,0 

def build_condition(lr, n_actions, input_dims, keep_frames ,fc1_dims, fc2_dims):
    model = keras.Sequential([
        keras.layers.Input(shape = (keep_frames,input_dims,)),  #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
        keras.layers.Flatten(),                                 #平滑化‼
        keras.layers.Dense(fc1_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層1
        keras.layers.Dense(fc2_dims, activation ='relu', kernel_initializer = "he_normal"),        #中間層2
        keras.layers.Dense(1, activation = None, kernel_initializer = "he_normal")])       #出力層
    model.compile(optimizer = Adam(learning_rate=lr), loss ='huber_loss')

    model.summary()     #構築されたモデルの情報を表示
    return model,0,0    #Dueling_Networkと返り値の数を合わせている。

class DQNAgent:
    def __init__(self, folder ='log', RND=False, LSTM=False, parallel=False, neighbor=False, pre_reward=False, condition=False, beta=False):

        self.RND = RND
        self.LSTM = LSTM
        self.parallel = parallel
        self.folder = folder
        self.neighbor = neighbor
        self.pre_reward = pre_reward
        self.condition = condition

        if self.parallel:
            self.learn_counter = 0

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
        self.n_actions = N_ACTIONS

        #vanilla-DQN
        self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,STATE_VARIABLES, beta=beta)   #ReplayBufferクラスのインスタンス作成
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
        self.q_state_model_file = "pre_reward.h5"
        self.adv_target_model_file = "adv_target.h5"
        self.rnd_target_model_file = "rnd_target.h5"
        self.rnd_predictor_model_file = "rnd_predictor.h5"
        self.condition_model_file = "condition.h5"
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
        #self.is_weight = np.power(self.mem_size,-self.beta)         #重点サンプリング重みの初期値
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
        self.log_loss_buffer = []               #1エピソード分の損失関数のlog（ep.終了時にlog_lossに連結）
        self.log_v = []                         #NNの状態価値関数Vのlog
        self.log_adv = []                       #NNのアドバンテージ関数Aのlog
        self.log_p = []
        self.con_log = []
        self.rnd_rewards_log = []
        #self.epsilon_act = 0
        #self.action_old = 0

        self.rnd_reward = []
        self.target_nn,_,_= build_dqn(RND_LEARNING_RATE, 1, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        self.predictor_nn,_,_= build_dqn(RND_LEARNING_RATE, 1, STATE_VARIABLES, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)

        state_num = STATE_VARIABLES

        #NNの構築
        #Dueling or Normal
        if self.dueling:
            self.q_eval,self.v_eval,self.adv_eval = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.v_target, self.adv_target = build_dueling_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        elif self.LSTM:
            self.q_eval, self.v_eval,self.adv_eval = build_lstm_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_lstm_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        elif self.RND:
            self.q_eval, self.v_eval,self.adv_eval = build_rnd_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_rnd_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        elif self.condition:
            self.q_eval, self.v_eval,self.adv_eval = build_condition_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_condition_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        else:
            self.q_eval, self.v_eval,self.adv_eval = build_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
            self.q_target, self.target, self.adv_target = build_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)

        if self.parallel:
            self.q_choose = self.q_eval
        if self.pre_reward:
            self.q_state, _, _ = build_act_dqn(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)
        if self.condition:
            self.con_net, _, _ = build_condition(LEARNING_RATE, N_ACTIONS, state_num, KEEP_FRAMES, HIDDEN_1, HIDDEN_2)

        # create TensorFlow graph (model)(tf1)
        #self.init_model()

        # reset current loss
        self.current_loss = 0.0

        #ダミーデータ処理
        #predict_on_batchやtrain_on_batchの初回呼び出しが遅いので、先に呼び出しておく。
        if self.RND:
            self.NN_RND_avoid_overhead()
            self.NN_RND_dqn_avoid_overhead()
        elif self.condition:
            self.NN_condition_avoid_overhead()
            self.NN_condition_dqn_avoid_overhead()
        else:
            self.NN_avoid_overhead()

        if self.pre_reward:
            self.NN_preact_avoid_overhead()

        #学習の経過を記録
        self.episode = 0                #episode
        self.episode_in_advance = 0     #事前に学習済みのエピソード数
        self.trained_episode = 0        #学習済みのエピソード数の合計
        self.trained_step = 0           #学習済みのステップ数
        self.buffer_param(filepath = folder)

    def set_batchsize(self, size):
        self.batch_size = size

    def NN_avoid_overhead(self):
        data_dummy = np.array([[[0]*self.state_variables]*self.keep_frames]*self.batch_size)
        if self.LSTM:
            data_dummy = data_dummy.reshape(-1,self.keep_frames,self.state_variables)
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

    def NN_condition_dqn_avoid_overhead(self):
        data_dummy = np.array([[[0]*self.state_variables]*self.keep_frames]*self.batch_size)
        reward_data_dummy = np.array([[0]*1]*self.batch_size)
        buf1 = self.q_eval.predict_on_batch((data_dummy,reward_data_dummy))
        buf2 = self.q_target.predict_on_batch((data_dummy,reward_data_dummy))
        buf3 = np.copy(self.q_eval)
        self.q_eval.train_on_batch((data_dummy,reward_data_dummy), buf1)
        self.q_eval.set_weights(self.q_eval.get_weights())
        self.q_target.set_weights(self.q_target.get_weights())
        buf4 = self.memory_per.total_p()
        buf5 = np.empty((self.batch_size,1))   

    def NN_RND_dqn_avoid_overhead(self):
        data_dummy = np.array([[[0]*self.state_variables]*self.keep_frames]*self.batch_size)
        reward_data_dummy = np.array([[0]*3]*self.batch_size)
        buf1 = self.q_eval.predict_on_batch((data_dummy,reward_data_dummy))
        buf2 = self.q_target.predict_on_batch((data_dummy,reward_data_dummy))
        buf3 = np.copy(self.q_eval)
        self.q_eval.train_on_batch((data_dummy,reward_data_dummy), buf1)
        self.q_eval.set_weights(self.q_eval.get_weights())
        self.q_target.set_weights(self.q_target.get_weights())
        buf4 = self.memory_per.total_p()
        buf5 = np.empty((self.batch_size,1))    

    def NN_RND_avoid_overhead(self):
        data_dummy = np.array([[[0]*STATE_VARIABLES]*self.keep_frames]*self.batch_size)
        buf1 = self.target_nn.predict_on_batch(data_dummy)
        buf2 = self.predictor_nn.predict_on_batch(data_dummy)
        self.predictor_nn.train_on_batch(data_dummy, buf2)
    
    def NN_preact_avoid_overhead(self):
        data_dummy = np.array([[[0]*STATE_VARIABLES]*self.keep_frames]*self.batch_size)
        act_data_dummy = np.array([[0]*self.n_actions]*self.batch_size)
        buf1 = self.q_state.predict_on_batch((data_dummy, act_data_dummy))
        self.q_state.train_on_batch((data_dummy, act_data_dummy), buf1)
    
    def NN_condition_avoid_overhead(self):
        data_dummy = np.array([[[0]*STATE_VARIABLES]*self.keep_frames]*self.batch_size)
        buf1 = self.con_net.predict_on_batch(data_dummy)
        self.con_net.train_on_batch(data_dummy, buf1)

    def _per_loss(self, y_target, y_pred):
        #return tf.reduce_mean(self.is_weight * tf.math.squared_difference(y_target, y_pred))
        huber_loss = tf.keras.losses.Huber()
        return tf.reduce_mean(self.is_weight * huber_loss(y_target, y_pred))

    def rnd_thr(self, keep_states, thr):
        states = np.array([keep_states])
        target_val = self.target_nn.predict_on_batch(states)
        predict_val = self.predictor_nn.predict_on_batch(states)
        error = np.square(target_val-predict_val)
        if error > thr:
            flag = 0
        else:
            flag = 1
        return flag

    def choose_action(self, keep_states, limit, dyaw=0):
        """
        ε-greedy方策による行動選択
        """
        #print(keep_states)
        #行動log用変数
        log_action_buffer = []      #(行動番号, 行動の選び方)のtupleを作成
        random_action_flag = 0      #random行動が選択された場合は1,argmaxQ行動が選択された場合は0

        states = np.array([keep_states])         #観測された状態をリスト化
        angle = states[0][0][2]
        if self.RND:
            extend = np.array([[0]*3])
        if self.LSTM:
            states = states.reshape(-1,self.keep_frames,self.state_variables)

        if self.parallel:
            Q_values = self.q_choose.predict_on_batch(states)
        elif self.RND:
            Q_values = self.q_eval.predict_on_batch((states,extend))
        elif self.condition:
            con = abs(self.con_net.predict_on_batch(states))-abs(float(dyaw))
            self.con_log.append(con[0])
            Q_values = self.q_eval.predict_on_batch((states,con))
        else:
            Q_values = self.q_eval.predict_on_batch(states)

        if self.LSTM:
            buf = Q_values
            for i in range(self.keep_frames-1):
                buf = np.delete(buf,0,1)
            Q_values = buf

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

        if limit:
            p_gain = 9
            while 1:
                if action == 4:
                    p_gain = 6
                elif action == 3:
                    p_gain = 4.5
                elif action == 2:
                    p_gain = 4
                elif action == 1:
                    p_gain = 3.5
                elif action == 0:
                    p_gain = 2
                    break
                if p_gain*abs(angle)<210:
                    break
                else:
                    action -= 1
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

    def update_epsilon(self):
        self.epsilon = self.epsilon - self.eps_dec if self.epsilon > self.eps_min else self.eps_min

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

    def store_transition(self, state, action, reward, new_state, done, dyaw):
        """
        経験の保存
        """
        self.memory.store_transition(state, action, reward, new_state, done, dyaw)
        self.num_in_buffer = min(self.num_in_buffer + 1, self.mem_size) #保存されている経験の数を記録
    
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
            
            #randomサンプリング
            idxes_batch = random.sample(range(self.num_in_buffer), batch_size)
            
            """
            #betaサンプリング
            idxes_batch = []
            while len(idxes_batch) != self.batch_size:
                beta_int = int(self.num_in_buffer * np.random.beta(4,1))
                idxes_batch.append(beta_int)
                idxes_batch = list(set(idxes_batch))
            """


            transitions = self.memory_per.data[idxes_batch]
            #print(transitions.shape)
            for tran in transitions:
                states.append(tran[0])
                actions.append(tran[1])
                rewards.append(tran[2])
                states_.append(tran[3])
                terminal.append(1 - tran[4])    #（1-True or 1-False）
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

    def learn(self, beta=1):
        #time_start = time.time()
        """
        NNの重みとバイアスを学習
        """
        #保存された経験が足りない場合は学習しない
        if self.LSTM:
            if self.num_in_buffer < self.batch_size+self.keep_frames-1:
                #self.global_step += 1
                return
        elif self.num_in_buffer < self.batch_size:
            #self.global_step += 1
            return
        #各種ミニバッチ作成
        states, actions, rewards, states_, dones, batch_idxes, dyaw= self.memory.sample_buffer(self.batch_size)
        #states, actions, rewards, states_, dones, batch_idxes, self.is_weight, ps = self.sample_buffer_per(self.batch_size)
        
        #0~batch_size-1までの連番リストを取得
        batch_index = np.arange(self.batch_size, dtype = np.int32)
        #報酬予測の学習----------------------------------------------------------------------------------------------------------
        if self.pre_reward:
            act_index = np.ravel(actions-1)
            act = np.array([[0]*self.n_actions]*self.batch_size)
            act[batch_index,act_index] = 1
            Qs = self.q_target.predict(states_)
            Q = np.max(Qs, axis=1)
            rewards_ = np.array([rewards])
            Q_ = np.array([Q])
            rewards_ = rewards_.T
            Q_ = Q_.T
            back = np.concatenate([rewards_, Q_],1)
            self.q_state.train_on_batch((states,act),back)

        #RNDの学習---------------------------------------------------------------------------------------------------------------
        if self.RND:
            beta_list = np.array([beta]*self.batch_size)
            target_val = self.target_nn.predict_on_batch(states)
            predict_val = self.predictor_nn.predict_on_batch(states)
            error = np.square(target_val-predict_val)*0.01
            rewards_in = np.ravel(np.clip(error,0,50)*beta)
            self.predictor_nn.train_on_batch(states,target_val)

            #print(states)
            #print(beta_list)
            rewards_in = np.ravel(rewards_in)
            self.rnd_reward.append(rewards_in) #for Debug
            state_reward = np.concatenate([rewards.reshape(-1,1), rewards_in.reshape(-1,1), beta_list.reshape(-1,1)],axis=1)
            rnd_rewards = rewards + rewards_in
            self.rnd_rewards_log.append([np.mean(rewards), np.mean(rewards_in)])

        if self.LSTM:
            states = states.reshape(-1,self.keep_frames,self.state_variables)
            states_ = states_.reshape(-1,self.keep_frames,self.state_variables)
        #minibatch_indexのlog格納
        self.log_minibatch_index.append(batch_idxes)
        #self.log_p.append(ps)
        #Fixed-Targetを実装
        #RND ver-----------------------------------------------------------------------------------------------------------------
        if self.RND:
            extend = np.array([[0]*3])
            q_eval = self.q_target.predict((states,extend))
            q_next = self.q_target.predict((states_,extend))
        #コンディション ver-----------------------------------------------------------------------------------------------------------------
        elif self.condition:
            dyaw_ = dyaw.reshape(self.batch_size,-1)
            con = abs(self.con_net.predict_on_batch(states))-abs(dyaw_)
            q_eval = self.q_target.predict((states,con))
            q_next = self.q_target.predict((states_,con))
        #通常 ver-----------------------------------------------------------------------------------------------------------------
        else:
            q_eval = self.q_target.predict(states)
            q_next = self.q_target.predict(states_)

        q_target = np.copy(q_eval)      #q_targetの値を書き換えて、教師データとしていく
        batch_index_ = batch_idxes

        frames = np.zeros(self.batch_size, dtype=np.int32)
        #DQNの学習-----------------------------------------------------------------------------------------------------------------
        #LSTM ver-----------------------------------------------------------------------------------------------------------------
        if self.LSTM:
            for i in range(self.keep_frames-1):
                actions_ = self.memory.action_memory[batch_index_]
                rewards_ = self.memory.reward_memory[batch_index_]
                states_ = self.memory.new_state_memory[batch_index_]
                states_ = states_.reshape(-1,self.keep_frames,self.state_variables)
                q_next = self.q_target.predict(states_)

                buf = q_next
                for i in range(self.keep_frames-1):
                    buf = np.delete(buf,0,1)
                q_next = buf.reshape(self.batch_size,self.n_actions)
                q_target[batch_index, frames, actions_] = rewards + self.gamma * np.max(q_next, axis=1)* dones
                batch_index_ -= 1
                frames -= 1
        #RND ver-----------------------------------------------------------------------------------------------------------------
        elif self.RND:
            q_target[batch_index, actions] = rnd_rewards + self.gamma * np.max(q_next, axis=1)* dones
        #周辺近似 ver-----------------------------------------------------------------------------------------------------------------
        elif self.neighbor:
            q_target[batch_index, actions] = rewards + self.gamma * np.max(q_next, axis=1)* dones
            actions_ = actions-1
            n_ = np.where(actions_<0,0,1)
            n__ = np.where(actions_>self.n_actions,0,1)
            dones_ = n_*n__
            actions_ = actions_*dones_
            q_target[batch_index, actions_] = dones_*(0.5*(0.5*rewards + self.gamma * np.max(q_next, axis=1)* dones+q_target[batch_index, actions_]))+(1-dones_)*q_target[batch_index, actions]
            actions_ = actions+1
            n_ = np.where(actions_<0,0,1)
            n__ = np.where(actions_>self.n_actions-1,0,1)
            dones_ = n_*n__
            actions_ = actions_*dones_
            q_target[batch_index, actions] = dones_*(0.5*(0.5*rewards + self.gamma * np.max(q_next, axis=1)* dones+q_target[batch_index, actions_]))+(1-dones_)*q_target[batch_index, actions]
        #報酬予測　ver-----------------------------------------------------------------------------------------------------------------
        elif self.pre_reward:
            index_act_ = np.array(np.identity(self.n_actions))
            index_act = np.tile(index_act_,(self.batch_size,1))
            states_ = np.repeat(states,self.n_actions, axis=0)
            pre_rewards = self.q_state.predict_on_batch((states_, index_act))
            pre_rewards , pre_q = np.split(pre_rewards,2,1)
            pre_rewards = np.clip(pre_rewards,-1,1)
            pre_rewards = pre_rewards.reshape([self.batch_size,self.n_actions])
            dones_ = np.tile(dones,(1,self.n_actions))
            dones_ = dones_.T
            pre_q = pre_q * dones_
            pre_q = pre_q.reshape([self.batch_size,self.n_actions])
            q_target = pre_rewards + pre_q
        #通常 ver-----------------------------------------------------------------------------------------------------------------
        else:
            #Double or Fixed Target Network
            if self.double:
                a = np.argmax(q_eval, axis = 1)
                q_target[batch_index, actions] = rewards + self.gamma * q_next[batch_index,a] * dones
            else:
                q_target[batch_index, actions] = rewards + self.gamma * np.max(q_next, axis=1)* dones
        '''
        #優先度pの更新
        #clipped error(安定性のためにTDerrorを-1~1にクリッピング(論文にも書かれている))
        abs_td_error_list = np.abs(q_target[batch_index, actions] - q_eval[batch_index, actions]) + self.margin
        clipped_error = np.where(abs_td_error_list < 1, abs_td_error_list, 1)
        p_list = np.power(clipped_error, self.alpha)
        #print(p_list)
        self.update_priorities(p_list,batch_idxes)
        '''
        if self.LSTM:
            states = states.reshape(-1,self.keep_frames,self.state_variables)
        #NNのパラメータ更新
        if self.global_step % self.learning_period == 0 or self.num_in_buffer == self.batch_size:
            #RND ver-----------------------------------------------------------------------------------------------------------------
            if self.RND:
                loss = self.q_eval.train_on_batch((states,state_reward), q_target) 
                self.past_state_reward = np.copy(state_reward)
            #コンディション ver-----------------------------------------------------------------------------------------------------------------
            elif self.condition:
                loss = self.q_eval.train_on_batch((states,con), q_target)
                self.past_con = np.copy(con)
            else:
                loss = self.q_eval.train_on_batch(states, q_target)
            self.log_loss_buffer.append(loss)
            self.past_states = np.copy(states)
            self.past_q_target = np.copy(q_target)
        else:
            #RND ver-----------------------------------------------------------------------------------------------------------------
            if self.RND:
                loss = self.q_eval.train_on_batch((self.past_states,self.past_state_reward), q_target) 
            #コンディション ver-----------------------------------------------------------------------------------------------------------------
            elif self.condition:
                loss = self.q_eval.train_on_batch((self.past_states,self.past_con), q_target)
            else:
                loss = self.q_eval.train_on_batch(self.past_states, self.past_q_target)
            self.log_loss_buffer.append(loss)

        #dyawの学習----------------------------------------------------------------------------------------------------
        if self.condition:
            self.con_net.train_on_batch(states,dyaw)        
        #self.log_loss.append(self.q_eval.train_on_batch(states, q_target))
        #loss = self.q_eval.train_on_batch(states, q_target)
        #self.log_loss.append(loss)
        """
        float_loss = loss.item()
        print(type(float_loss))
        self.log_loss.append(float_loss)
        """
        #print(self.log_loss)

        if (self.global_step % self.copy_period == 0):
            print("Copy Weight")
            '''
            self.q_eval.layers[0].set_weights(self.q_target.layers[0].get_weights())
            self.q_eval.layers[1].set_weights(self.q_target.layers[1].get_weights())
            self.q_eval.layers[2].set_weights(self.q_target.layers[3].get_weights())
            self.q_eval.layers[3].set_weights(self.q_target.layers[4].get_weights())
            '''
            self.q_target.set_weights(self.q_eval.get_weights())

        if self.parallel:
            self.q_choose.set_weights(self.q_eval.get_weights())
            self.learn_counter += 1

        #print(loss)
        #print("time:" + str(time_start2-time_start))
        #self.epsilon = self.epsilon - self.eps_dec if self.epsilon > self.eps_min else self.eps_min

    def observe_reward(self, data, yaw_index=2):
        """
        報酬を定義する
        Args:
            data ([list]): 状態（1フレーム）
        Returns:
            [int]: 報酬
        """
        err = abs(float(data[0][yaw_index])-0.0)
        return 1.0-err/90.0

    def get_angle(self,states):
        self.log_yaw_angle.append(float(states[0][YAW_INDEX]))

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
        i=0
        if self.condition == True or self.RND == True:
            i=4
        l1 = self.q_eval.layers[i]
        l2 = self.q_eval.layers[i+1]
        l3 = self.q_eval.layers[i+2]
        l4 = self.q_eval.layers[i+3]
        with open(self.folder + '/debug.csv', 'a') as f:
            np.savetxt(f, l2.get_weights()[0])
            np.savetxt(f, l2.get_weights()[1])
            np.savetxt(f, l3.get_weights()[0])
            np.savetxt(f, l3.get_weights()[1])
            np.savetxt(f, l4.get_weights()[0])
            np.savetxt(f, l4.get_weights()[1])
        if self.condition == True:
            l = self.q_eval.layers[3]
            np.savetxt(self.folder + '/debug_W_fc_con.csv', l.get_weights()[0], delimiter=',')
        if self.RND == True:
            l = self.q_eval.layers[3]
            np.savetxt(self.folder + '/debug_W_fc_add.csv', l.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_W_fc1.csv', l2.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc1.csv', l2.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/debug_W_fc2.csv', l3.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc2.csv', l3.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/debug_W_out.csv', l4.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/debug_b_out.csv', l4.get_weights()[1], delimiter=',')

    def debug_rnd_target_nn(self):
        l1 = self.target_nn.layers[0]
        l2 = self.target_nn.layers[1]
        l3 = self.target_nn.layers[2]
        l4 = self.target_nn.layers[3]
        with open(self.folder + '/rnd_t_debug.csv', 'a') as f:
            np.savetxt(f, l2.get_weights()[0])
            np.savetxt(f, l2.get_weights()[1])
            np.savetxt(f, l3.get_weights()[0])
            np.savetxt(f, l3.get_weights()[1])
            np.savetxt(f, l4.get_weights()[0])
            np.savetxt(f, l4.get_weights()[1]) 
        np.savetxt(self.folder + '/rnd_t_debug_W_fc1.csv', l2.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_t_debug_b_fc1.csv', l2.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/rnd_t_debug_W_fc2.csv', l3.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_t_debug_b_fc2.csv', l3.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/rnd_t_debug_W_out.csv', l4.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_t_debug_b_out.csv', l4.get_weights()[1], delimiter=',')

    def debug_rnd_predictor_nn(self):
        l1 = self.predictor_nn.layers[0]
        l2 = self.predictor_nn.layers[1]
        l3 = self.predictor_nn.layers[2]
        l4 = self.predictor_nn.layers[3]
        with open(self.folder + '/rnd_p_debug.csv', 'a') as f:
            np.savetxt(f, l2.get_weights()[0])
            np.savetxt(f, l2.get_weights()[1])
            np.savetxt(f, l3.get_weights()[0])
            np.savetxt(f, l3.get_weights()[1])
            np.savetxt(f, l4.get_weights()[0])
            np.savetxt(f, l4.get_weights()[1]) 
        np.savetxt(self.folder + '/rnd_p_debug_W_fc1.csv', l2.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_p_debug_b_fc1.csv', l2.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/rnd_p_debug_W_fc2.csv', l3.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_p_debug_b_fc2.csv', l3.get_weights()[1], delimiter=',')
        np.savetxt(self.folder + '/rnd_p_debug_W_out.csv', l4.get_weights()[0], delimiter=',')
        np.savetxt(self.folder + '/rnd_p_debug_b_out.csv', l4.get_weights()[1], delimiter=',')

    def load_saved_NN(self, save_dir):
        self.q_eval = load_model(save_dir + self.q_eval_model_file, custom_objects = {"_per_loss": self._per_loss})
        self.q_target = load_model(save_dir + self.q_target_model_file, custom_objects = {"_per_loss":self._per_loss})
        if self.dueling:
            self.v_eval = load_model(save_dir  + self.v_eval_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.v_target = load_model(save_dir + self.v_target_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.adv_eval = load_model(save_dir + self.adv_eval_model_file, custom_objects = {"_per_loss":self._per_loss})
            self.adv_target = load_model(save_dir + self.adv_target_model_file, custom_objects = {"_per_loss":self._per_loss})

    def load_state_NN(self, save_dir):
        self.q_state = load_model(save_dir + self.q_state_model_file, custom_objects = {"_per_loss": self._per_loss})

    def load_condition_NN(self, save_dir):
        self.con_net = load_model(save_dir + self.condition_model_file, custom_objects = {"_per_loss": self._per_loss})

    def load_rnd_NN(self, save_dir):
        self.target_nn = load_model(save_dir + self.rnd_target_model_file, custom_objects = {"_per_loss": self._per_loss})
        self.predictor_nn = load_model(save_dir + self.rnd_predictor_model_file, custom_objects = {"_per_loss":self._per_loss})

    def save_con(self):        
        with open(self.folder + '/condition.csv', 'a') as f:
            np.savetxt(f, self.con_log, delimiter=',')
    
    def save_rnd_rewards(self):        
        with open(self.folder + '/rnd_rewards.csv', 'a') as f:
            np.savetxt(f, self.rnd_rewards_log, delimiter=',')

    def save_NN_model(self, filepath):
        self.q_eval.save(filepath + "/" + self.q_eval_model_file)
        self.q_target.save(filepath + "/" + self.q_target_model_file)
        if self.dueling:
            self.v_eval.save(filepath + "/" +self.v_eval_model_file)
            self.v_target.save(filepath + "/"+  self.v_target_model_file)
            self.adv_eval.save(filepath + "/" + self.adv_eval_model_file)
            self.adv_target.save(filepath + "/" + self.adv_target_model_file)

    def save_state_model(self, filepath):
        self.q_state.save(filepath + "/" + self.q_state_model_file)
    
    def save_condition_model(self, filepath):
        self.con_net.save(filepath + "/" + self.condition_model_file)

    def save_rnd_model(self, filepath):
        self.target_nn.save(filepath + "/" + self.rnd_target_model_file)
        self.predictor_nn.save(filepath + "/" + self.rnd_predictor_model_file)

    def load_param(self, filepath):
        with open(filepath + "trained_episode.txt") as f:
            self.episode_in_advance = int(f.read())
        with open(filepath + "trained_step.txt") as f:
            self.global_step = int(f.read())
        with open(filepath + "epsilon.txt") as f:
            self.epsilon = float(f.read())
        if self.per:
            with open(filepath + "beta.txt") as f:
                self.beta = float(f.read())

    def save_counter(self,filepath):
        with open(filepath + "/learn_counter.txt", mode = "w") as name:
            print(self.learn_counter, file = name)

    def save_param(self,filepath):
        with open(filepath + "/trained_episode.txt", mode = "w") as name:
            print(self.trained_episode, file = name)
        with open(filepath + "/trained_step.txt", mode = "w") as name:
            print(self.trained_step, file = name)
        with open(filepath + "/epsilon.txt", mode = "w") as name:
            print(self.last_epsilon, file = name)
        with open(filepath + "/num_in_buffer.txt", mode = "w") as name:
            print(self.num_in_buffer, file = name)
        #with open(filepath + "/write.txt", mode = "w") as name:
        #    print(self.last_write, file = name)
        if self.per:
            with open(filepath + "/beta.txt", mode  = "w") as name:
                print(self.last_beta, file = name)

    def save_score(self, filepath, score):
        with open(filepath + "/score.txt", mode = "w") as name:
            print(score, file = name)

    def buffer_param(self, filepath):
        #最新のエピソード終了時の変数を記録
        self.last_epsilon = self.epsilon
        self.trained_episode = self.episode + self.episode_in_advance
        self.trained_step = self.global_step
        self.last_num_in_buffer = self.num_in_buffer
        '''
        self.last_write = self.memory_per.write
        if self.per:
            self.last_beta = self.beta
        np.save(filepath + "/tree", self.memory_per.tree)
        np.save(filepath + "/data", self.memory_per.data)
        '''

    def load_replay_buffer(self, filepath):
        with open(filepath + "num_in_buffer.txt") as f:
            self.num_in_buffer = int(f.read())
        #with open(filepath + "write.txt") as f:
        #    self.memory_per.write = int(f.read())
        #self.memory_per.tree = np.load(file = filepath + "tree.npy")
        #self.memory_per.data = np.load(file = filepath + "data.npy", allow_pickle = True)

    def debug_memory(self):
        with open(self.folder + '/debug_memory.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.log_states)

    def debug_minibatch(self):
        #print(self.minibatch_ind)
        self.minibatch_index_log = np.array(self.log_minibatch_index)
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

    def debug_rnd(self):
        with open(self.folder + '/debug_rnd.csv', 'w') as f:
            writer = csv.writer(f, lineterminator ='\n')
            writer.writerows(self.rnd_reward)

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

    def load_log_loss(self, filepath):
        with open(filepath + "log_loss.csv") as name:
            reader =list(csv.reader(name))
            for rdr in reader[0]:
                #print(rdr)
                self.log_loss.append(float(rdr))

    def link_log_loss(self):
        self.log_loss += self.log_loss_buffer
        self.log_loss_buffer = []

    def save_log_loss(self, filepath):
        with open(filepath + "/log_loss.csv", mode = "w", newline = "") as f:
            writer = csv.writer(f, lineterminator = "\n")
            writer.writerow(self.log_loss)

    def check_loss(self):
        return self.log_loss