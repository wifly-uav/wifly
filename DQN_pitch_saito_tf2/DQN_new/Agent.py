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

import warnings
warnings.filterwarnings('ignore')


import os
#--------------------------const, directory name, model name, etc...-------------------------
MODEL_NAME = "WiflyDual_DQN"# + str(datetime.today())[0:10]
MODEL_DIRECTORY = os.path.join(os.path.dirname(os.path.abspath(__file__)), "models")
CHECKPOINT_NAME = "WiflyDual_DQN"
MINIBATCH_SIZE = 16
REPLAY_MEMORY_SIZE = 10000
LEARNING_RATE = 0.02
DISCOUNT_FACTOR = 0.95
EPSILON = 0.1
EPSILON_DEC=1e-3
EPSILON_END=0.01
ENABLE_ACTIONS = [1,2,3,4,5]
N_ACTIONS = len(ENABLE_ACTIONS)
FRAMES = 4
INPUT_DIMS = FRAMES*1
#INPUTS = 5
HIDDEN_1 = 10
HIDDEN_2 = 5

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
        self.terminal_memory[index] = 1 - int(done)

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


class DQNAgent:
    def __init__(self, folder='log'):
        # Load parameters
        self.name = os.path.splitext(os.path.basename(__file__))[0] #このスクリプトの拡張子を含まないファイル名を取得
        self.path = os.path.dirname(__file__)                       #このスクリプトのディレクトリを取得
        self.minibatch_size = MINIBATCH_SIZE
        self.batch_size = MINIBATCH_SIZE

        #self.replay_memory_size = REPLAY_MEMORY_SIZE
        self.memory = ReplayBuffer(REPLAY_MEMORY_SIZE,FRAMES)   #ReplayBufferクラスのインスタンス作成
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

        # create TensorFlow graph (model)(tf1)
        #self.init_model()

        # reset current loss
        self.current_loss = 0.0

    #未使用
    def batch_norm_wrapper(inputs, is_training = True, decay = 0.999):
        """
        バッチの正規化
        """
        variance_epsilon = 1e-3
        scale = tf.Variable(tf.ones([inputs.get_shape()[-1]]))
        scale = tf.Variable(tf.ones([inputs.get_shape()[-1]]))
        beta = tf.Variable(tf.zeros([inputs.get_shape()[-1]]))
        pop_mean = tf.Variable(tf.zeros([inputs.get_shape()[-1]]), trainable=False)
        pop_var = tf.Variable(tf.ones([inputs.get_shape()[-1]]), trainable=False)

        if is_training:
            batch_mean, batch_var = tf.nn.moments(inputs,[0])
            train_mean = tf.assign(pop_mean,
                                pop_mean * decay + batch_mean * (1 - decay))
            train_var = tf.assign(pop_var,
                                pop_var * decay + batch_var * (1 - decay))
            with tf.control_dependencies([train_mean, train_var]):
                return tf.nn.batch_normalization(inputs,
                    batch_mean, batch_var, beta, scale, variance_epsilon)
        else:
            return tf.nn.batch_normalization(inputs,
                pop_mean, pop_var, beta, scale, variance_epsilon)

    def huber_loss(self, y_true, y_pred, clip_delta=1.0):
        error = y_true - y_pred
        cond  = tf.keras.backend.abs(error) < clip_delta

        squared_loss = 0.5 * tf.keras.backend.square(error)
        linear_loss  = clip_delta * (tf.keras.backend.abs(error) - 0.5 * clip_delta)

        return tf.where(cond, squared_loss, linear_loss)

    #huber関数
    def huber_loss_mean(self, y_true, y_pred, clip_delta=1.0):
        return tf.keras.backend.mean(self.huber_loss(y_true, y_pred, clip_delta))

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
    
    """
    def init_model(self):
        
        ニューラルネットワークを構築する
        
        self.x = tf.placeholder(tf.float32, [None, FRAMES, INPUTS], name="x")   #入力層と同じ次元を持つ2次元配列

        # flatten (FRAMES*INPUTS)
        with tf.name_scope('reshape'):
            x_flat = tf.reshape(self.x, [-1, FRAMES*INPUTS])                    #1次元配列に直す（これが入力層）

        # input layer. fully connected(20)
        with tf.name_scope('fc1'):
            #重みの行列の次元は入力層ユニット数*隠れ層1のユニット数
            #切断正規分布から取得される乱数で重みを初期化
            self.W_fc1 = tf.Variable(tf.truncated_normal([FRAMES*INPUTS, HIDDEN_1], stddev=0.01), name="W_fc1")

            #各ユニットのバイアスは0で初期化
            self.b_fc1 = tf.Variable(tf.zeros([HIDDEN_1]), name="b_fc1")

            #出力（ベクトル）の計算
            #活性化関数はReLU
            self.h_fc1 = tf.nn.relu(tf.matmul(x_flat, self.W_fc1) + self.b_fc1)

        # hidden layer. fully connected (20)
        with tf.name_scope('fc2'):
            self.W_fc2 = tf.Variable(tf.truncated_normal([HIDDEN_1, HIDDEN_2], stddev=0.01), name="W_fc2")
            self.b_fc2 = tf.Variable(tf.zeros([HIDDEN_2]),  name="b_fc2")
            self.h_fc2 = tf.nn.relu(tf.matmul(self.h_fc1, self.W_fc2) + self.b_fc2)

        # output layer. fully connected (3)
        with tf.name_scope('output'):
            # output layer (N_ACTIONS)
            self.W_out = tf.Variable(tf.truncated_normal([HIDDEN_2, N_ACTIONS], stddev=0.01), name="W_out")
            
            #self.b_out = tf.Variable(tf.zeros([N_ACTIONS]), name="b_out")
            #出力層のバイアスは[10,5,1,0.1,0]で初期化されている。
            self.b_out = tf.Variable([10,5,1,0.1,0], name="b_out")

            #出力層の活性化関数は恒等写像
            self.y = tf.matmul(self.h_fc2, self.W_out) + self.b_out

        # loss function
        with tf.name_scope('loss'):
            #self.y_は教師データ
            #DQNにおける教師データはr+γ*maxQ(s,a)
            #各状態において、行動aの数（N_ACTIONS）分のデータがある
            self.y_ = tf.placeholder(tf.float32, [None, N_ACTIONS])

            #損失関数は平均二乗誤差
            self.loss = tf.reduce_mean(tf.square(self.y_ - self.y), name="loss")
            #self.loss = tf.reduce_mean(self.huber_loss_mean(self.y_, self.y), name="loss")

        # train operation RMSPropOptimizer
        #重みとバイアスの調整に用いるアルゴリズムがoptimizer
        #基本的には（確率的）勾配降下法の応用
        with tf.name_scope('Optimizer'):
            optimizer = tf.train.RMSPropOptimizer(self.learning_rate)
            self.training = optimizer.minimize(self.loss)

        # saver for TensorBoard
        self.saver = tf.train.Saver()
        # session
        self.sess = tf.Session()
        self.sess.run(tf.global_variables_initializer())
        # write out for TensorBoard
        #self.summary_writer = tf.summary.FileWriter("WiFly_DQN_TensorBoard", graph=self.sess.graph)
    """

    # return Q(state, action) for each
    def Q_values(self, state):
        """
        ニューラルネットワークから各行動のQ値を算出する
        Args:
            state ([deque]): 状態(nフレーム)
        Returns:
            [list?]: 各行動のQ値
        """
        return self.sess.run(self.y, feed_dict={self.x: [state]})[0]

    def select_action(self, state):
        """
        行動決定(方策)
        Args:
            state ([deque]): 状態(nフレーム)
        Returns:
            [int]: 決定した行動の番号
        """
        a = self.Q_values(state)                            #NNから行動価値関数のリストを受け取る。
        self.log_q.append(a)                                #log用
        if np.random.rand() <= self.epsilon:                #εの確率で…
            # random
            act = np.random.choice(self.enable_actions)     #randomに行動選択
        else:                                               #それ以外で…
            # max_action Q(state, action)
            act = self.enable_actions[np.argmax(a)]         #greedyに行動選択
            
        self.log_act.append([act])                          #log用
        return act
    
    def choose_action(self, keep_states):
        """
        ε-greedy方策による行動選択
        """
        if np.random.random() < self.epsilon:
            action = np.random.choice(self.action_space)
        else:
            #現在保持している状態のリストをnp.array化
            #これによってNNに入力できる。
            self.states = np.array([keep_states])

            #NNからstatesの先頭の状態での各行動に対する行動価値関数の推定値を受け取る。
            #NNのモデルに対しpredictメソッドを実行すると、出力される。
            actions = self.q_eval.predict(self.states)
            #print(actions)
            action = np.argmax(actions)             #行動価値が最大である行動を選択     

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

    # store experience to replay memory
    def store_experience(self, state, action, reward, state_1, terminal):
        """
        経験を保存する
        Args:
            state ([deque]): 現在の状態
            action ([int]): 直前の行動の番号
            reward ([int]): 現在の状態に対する報酬
            state_1 ([deque]): 1フレーム前の状態
            terminal ([int]): ターミナル
        """
        self.replay_memory.append((state.copy(), action, reward, state_1.copy(), terminal))

    # train the network by replaying experience

    def store_transition(self, state, action, reward, new_state, done):
        """
        経験の保存
        """
        self.memory.store_transition(state, action, reward, new_state, done)

    def experience_replay(self, a=4, b=1):
        """
        NNの重みとバイアスを学習（ミニバッチ学習）
        """
            
        state_minibatch = []    #状態を格納するミニバッチ
        y_minibatch = []        #教師データ(r'+γmaxQ(s',a'))を格納するミニバッチ

        # sample random minibatch
        #replay_memoryに保存されたデータ数がminibatch_sizeよりも少なければ、今保存されているデータのみを使って行う。
        minibatch_size = min(len(self.replay_memory), self.minibatch_size)

        #minibatch_indexes = np.random.randint(0, len(self.replay_memory), minibatch_size)

        #最新の経験をミニバッチに確定で入れるかどうか
        
        #minibatch_indexes = np.random.randint(0, len(self.replay_memory), minibatch_size-1)
        #minibatch_indexes = np.insert(minibatch_indexes,0,len(self.replay_memory)-1)
    
        beta = np.random.beta(a,b,self.minibatch_size)  #β分布に基づいたminibatch_size個の乱数リストを取得
        
        #取得した乱数を全てreplay_memory倍する
        #これにより0~1の乱数から、0~len(self.replay_memory)までのランダムな番号を得られる
        beta = beta * len(self.replay_memory)

        minibatch_indexes = [int(n) for n in beta]      #乱数によって得られた添え字をリストに格納

        #log用
        self.minibatch_index_log = np.concatenate([self.minibatch_index_log, minibatch_indexes])
        k = np.append(self.minibatch_index_log,-1)
        self.minibatch_index_log = k

        #create minibatch dataset
        #replay_memoryのうち、乱数で取得した番号のものを取得していく。
        
        for j in minibatch_indexes:
            state_j, action_j, reward_j, state_j_1, terminal = self.replay_memory[j]    #経験を各変数に分解
            action_j_index = self.enable_actions.index(action_j)                        #action_jがenable_actionsの何番目かを調べる

            y_j = self.Q_values(state_j)                                                #state_jにおける各行動に対する行動価値関数のリスト
        
            #y_j[action_j_index]のみ教師データ（TDターゲット）に基づく値に書き換える。
            #他のy_j[i](state_jにおける他の行動に対するQ)はそのまま
            if terminal:
                y_j[action_j_index] = reward_j
            else:
                # reward_j + DiscountFactor * max_action' Q(state', action')
                y_j[action_j_index] = reward_j + self.discount_factor * np.max(self.Q_values(state_j_1))  # NOQA

            state_minibatch.append(state_j)         #学習に使う状態を格納
            y_minibatch.append(y_j)                 #それに対応する教師データ（TDターゲット）を格納

        #training
        #RMSpropOptimizerを用いて、損失関数が最小になるようにNNの重みとバイアスを調整
        self.sess.run(self.training, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})

        # for logging
        self.current_loss = self.sess.run(self.loss, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})
        self.log_loss.append([-1, self.current_loss])
        
    def learn(self):
        """
        NNの重みとバイアスを学習
        """
        #保存された経験が足りない場合は学習しない
        if self.memory.mem_cntr < self.minibatch_size:
            return
        #各種ミニバッチ作成
        states, actions, rewards, states_, dones = self.memory.sample_buffer(self.minibatch_size)

        #Fixed-Targetは未実装
        
        q_eval = self.q_eval.predict(states)

        q_next = self.q_eval.predict(states_)       

        q_target = np.copy(q_eval)

        #0~batch_size-1までの連番リストを取得
        batch_index = np.arange(self.batch_size, dtype=np.int32)

        #TDターゲットの計算
        q_target[batch_index, actions] = rewards + self.gamma * np.max(q_next, axis=1)*dones

        #NNのパラメータ更新
        self.q_eval.train_on_batch(states, q_target)

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