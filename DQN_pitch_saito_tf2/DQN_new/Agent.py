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
MINIBATCH_SIZE = 64
REPLAY_MEMORY_SIZE = 10000
LEARNING_RATE = 0.05
DISCOUNT_FACTOR = 0.95
EPSILON = 0.1
EPSILON_DEC=1e-3
EPSILON_END=0.01
ENABLE_ACTIONS = [0,1,2,3,4,5]
N_ACTIONS = len(ENABLE_ACTIONS)
FRAMES = 4
INPUT_DIMS = 5
#INPUT_DIMS = FRAMES*1
#INPUTS = 5
HIDDEN_1 = 30
HIDDEN_2 = 30

#----------------------------------------------------------------------------------------------

class ReplayBuffer():
    def __init__(self, max_size, input_dims):
        self.mem_size = max_size
        self.mem_cntr = 0           #保存した経験の数をカウントする

        #各リプレイメモリーの初期化
        #state_memoryとnew_state_memoryは3次元arrayであることに注意
        self.state_memory = np.zeros((self.mem_size,FRAMES,input_dims),       
                                    dtype=np.float32)
        self.new_state_memory = np.zeros((self.mem_size,FRAMES,input_dims),   
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

        return states, actions, rewards, states_, terminal

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


def build_dqn(lr, n_actions, input_dims, fc1_dims, fc2_dims):
    """
    NNの作成
    -NNの入力:4つの状態（Qを求めたい状態sとその3フレーム前までの3つの状態を合わせた合計4つの状態）
    -NNの出力:状態sにおける各Q
    -state dequeの先頭に状態sが入っている
    """
    model = keras.Sequential([

        #Denseは全結合ユニット
        #ユニット数、（入力層のユニット数）、活性化関数が引数
        #入力のユニット数の指定には、input_dim=とinput_shape=があるらしい。
        keras.layers.Input(shape = (FRAMES,input_dims,)),        #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
        keras.layers.Flatten(),                             #平滑化‼
        keras.layers.Dense(fc1_dims, activation='relu'),    #中間層1
        keras.layers.Dense(fc2_dims, activation='relu'),    #中間層2
        keras.layers.Dense(n_actions, activation=None)])    #出力層
    
    #最適化アルゴリズム、誤差関数を指定する
    model.compile(optimizer=Adam(learning_rate=lr), loss='mean_squared_error')

    #構築されたモデルの情報を表示
    model.summary()

    return model

def build_dqn_target(lr, n_actions, input_dims, fc1_dims, fc2_dims):
    """
    NNの作成
    -NNの入力:4つの状態（Qを求めたい状態sとその3フレーム前までの3つの状態を合わせた合計4つの状態）
    -NNの出力:状態sにおける各Q
    -state dequeの先頭に状態sが入っている
    """



    model = keras.Sequential([

        #Denseは全結合ユニット
        #ユニット数、（入力層のユニット数）、活性化関数が引数
        #入力のユニット数の指定には、input_dim=とinput_shape=があるらしい。
        keras.layers.Input(shape = (FRAMES,input_dims,)),        #入力の数はinput_dims*4フレーム（shapeでの指定時は順序が逆なので注意）
        keras.layers.Flatten(),                             #平滑化‼
        keras.layers.Dense(fc1_dims, activation='relu'),    #中間層1
        #keras.layers.BatchNormalization(),    #バッチ正規化
        keras.layers.Dense(fc2_dims, activation='relu'),    #中間層2
        keras.layers.Dense(n_actions, activation=None)])    #出力層
    
    #最適化アルゴリズム、誤差関数を指定する
    model.compile(optimizer=Adam(learning_rate=lr), loss='mean_squared_error')

    #構築されたモデルの情報を表示
    model.summary()

    return model

class DQNAgent:
    def __init__(self, folder='log'):
        # Load parameters
        self.name = os.path.splitext(os.path.basename(__file__))[0] #このスクリプトの拡張子を含まないファイル名を取得
        self.path = os.path.dirname(__file__)                       #このスクリプトのディレクトリを取得
        self.minibatch_size = MINIBATCH_SIZE
        self.batch_size = MINIBATCH_SIZE

        #self.replay_memory_size = REPLAY_MEMORY_SIZE
        #self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,FRAMES)   #ReplayBufferクラスのインスタンス作成
        self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,INPUT_DIMS)   #ReplayBufferクラスのインスタンス作成
        self.learning_rate = LEARNING_RATE
        self.discount_factor = DISCOUNT_FACTOR
        self.gamma = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.eps_dec = EPSILON_DEC                 
        self.eps_min = EPSILON_END
        self.model_dir = MODEL_DIRECTORY
        self.model_name = MODEL_NAME
        self.checkpoint_name = CHECKPOINT_NAME
        self.enable_actions = ENABLE_ACTIONS
        self.action_space = N_ACTIONS

        #以下log用
        self.minibatch_index_log = np.empty(0)
        self.log_q = []
        self.log_act = []
        self.log_loss = []
        self.epsilon_act = 0
        self.action_old = 0

        self.folder = folder

        # create deque object for replay memory
        # self.replay_memory = deque(maxlen=self.replay_memory_size)
        
        #NNの構築（初期化)
        self.q_eval = build_dqn(LEARNING_RATE, N_ACTIONS, INPUT_DIMS, HIDDEN_1, HIDDEN_2)
        self.q_target = build_dqn_target(LEARNING_RATE, N_ACTIONS, INPUT_DIMS, HIDDEN_1, HIDDEN_2)

        # create TensorFlow graph (model)(tf1)
        #self.init_model()

        # reset current loss
        self.current_loss = 0.0

    def build_dqn(lr, n_actions, input_dims, fc1_dims, fc2_dims):
        """
        NNの作成
        """
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
    
    def choose_action(self, keep_states):
        """
        ε-greedy方策による行動選択
        """
        if np.random.random() < self.epsilon:
            action = np.random.choice(self.enable_actions)
            #print("random" + str(action))  
        else:
            #現在保持している状態のリストをnp.array化
            #これによってNNに入力できる。
            self.states = np.array([keep_states])

            #NNからstatesの先頭の状態での各行動に対する行動価値関数の推定値を受け取る。
            #NNのモデルに対しpredictメソッドを実行すると、出力される。
            actions = self.q_eval.predict(self.states)
            #print(actions)
            action = self.enable_actions[np.argmax(actions)]            #行動価値が最大である行動を選択   
            #print("greedy" + str(action))  

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
        
    def learn(self, step_count=0, rate = 10):
        """
        NNの重みとバイアスを学習
        """
        #保存された経験が足りない場合は学習しない
        if self.memory.mem_cntr < self.minibatch_size:
            return
        #各種ミニバッチ作成
        states, actions, rewards, states_, dones = self.memory.sample_buffer(self.minibatch_size)

        #Fixed-Targetは未実装
        time_start = time.time()
        #q_eval = self.q_eval.predict(states)
        q_eval = self.q_target.predict(states)
        #q_eval = self.q_eval(states, training=False)

        #q_next = self.q_eval.predict(states_)
        q_next = self.q_target.predict(states_)       
        #q_next = self.q_eval(states_, training=False)
        time_start2 = time.time()

        q_target = np.copy(q_eval)

        #0~batch_size-1までの連番リストを取得
        batch_index = np.arange(self.batch_size, dtype=np.int32)

        #TDターゲットの計算
        q_target[batch_index, actions] = rewards + self.gamma * np.max(q_next, axis=1)*dones

        time_start3 = time.time()
        #NNのパラメータ更新
        #self.log_loss.append(self.q_eval.train_on_batch(states, q_target))
        self.log_loss.append(self.q_target.train_on_batch(states, q_target))
        a = time.time()

        if (step_count % rate == 0):
            print("set_weight")
            '''
            self.q_eval.layers[0].set_weights(self.q_target.layers[0].get_weights())
            self.q_eval.layers[1].set_weights(self.q_target.layers[1].get_weights())
            self.q_eval.layers[2].set_weights(self.q_target.layers[3].get_weights())
            self.q_eval.layers[3].set_weights(self.q_target.layers[4].get_weights())
            '''
            self.q_eval.set_weights(self.q_target.get_weights())

        #print(loss)
        #print("time:" + str(a-time_start) + " , " + str(time_start2-time_start) + " , "  + str(time_start3-time_start2) + " , "  + str(a-time_start3))
        #self.epsilon = self.epsilon - self.eps_dec if self.epsilon > self.eps_min else self.eps_min
        
        #logの取得が未実装

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
            writer.writerows(self.replay_memory)

    def debug_minibatch(self):
        #print(self.minibatch_ind)
        np.savetxt(self.folder + '/debug_minibatch.csv', self.minibatch_index_log, delimiter=',', fmt='%s')

    def debug_q(self):
        with open(self.folder + '/debug_q.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_q)
        with open(self.folder + '/debug_act.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_act)

    def debug_loss(self):
        with open(self.folder + '/debug_loss.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_loss)

    def check_loss(self):
        return self.log_loss