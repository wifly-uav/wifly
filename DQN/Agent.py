import os
#import tensorflow as tf
from collections import deque
from datetime import datetime
	
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()
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
MINIBATCH_SIZE = 32
REPLAY_MEMORY_SIZE = 10000
LEARNING_RATE = 0.02
DISCOUNT_FACTOR = 0.95
EPSILON = 0.1
ENABLE_ACTIONS = [1,2,3,4,5]
N_ACTIONS = len(ENABLE_ACTIONS)
FRAMES = 4
INPUTS = 4
HIDDEN_1 = 10
HIDDEN_2 = 5

#----------------------------------------------------------------------------------------------


class DQNAgent:
    def __init__(self, folder='log'):
        # Load parameters
        self.name = os.path.splitext(os.path.basename(__file__))[0]
        self.path = os.path.dirname(__file__)
        self.minibatch_size = MINIBATCH_SIZE
        self.replay_memory_size = REPLAY_MEMORY_SIZE
        self.learning_rate = LEARNING_RATE
        self.discount_factor = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.model_dir = MODEL_DIRECTORY
        self.model_name = MODEL_NAME
        self.checkpoint_name = CHECKPOINT_NAME
        self.enable_actions = ENABLE_ACTIONS

        self.minibatch_index_log = np.empty(0)
        self.log_q = []
        self.log_act = []
        self.log_loss = []

        self.folder = folder

        # create deque object for replay memory
        self.replay_memory = deque(maxlen=self.replay_memory_size)

        # create TensorFlow graph (model)
        self.init_model()

        # reset current loss
        self.current_loss = 0.0

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

    def huber_loss(y_true, y_pred, clip_delta=1.0):
        error = y_true - y_pred
        cond  = tf.keras.backend.abs(error) < clip_delta

        squared_loss = 0.5 * tf.keras.backend.square(error)
        linear_loss  = clip_delta * (tf.keras.backend.abs(error) - 0.5 * clip_delta)

        return tf.where(cond, squared_loss, linear_loss)

    def init_model(self):
        """
        ニューラルネットワークを構築する
        """
        self.x = tf.placeholder(tf.float32, [None, FRAMES, INPUTS], name="x")

        # flatten (FRAMES*INPUTS)
        with tf.name_scope('reshape'):
            x_flat = tf.reshape(self.x, [-1, FRAMES*INPUTS])

        # input layer. fully connected(20)
        with tf.name_scope('fc1'):
            self.W_fc1 = tf.Variable(tf.truncated_normal([FRAMES*INPUTS, HIDDEN_1], stddev=0.01), name="W_fc1")
            self.b_fc1 = tf.Variable(tf.zeros([HIDDEN_1]), name="b_fc1")
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
            self.b_out = tf.Variable(tf.zeros([N_ACTIONS]), name="b_out")
            self.y = tf.matmul(self.h_fc2, self.W_out) + self.b_out

        # loss function
        with tf.name_scope('loss'):
            self.y_ = tf.placeholder(tf.float32, [None, N_ACTIONS])
            self.loss = tf.reduce_mean(tf.square(self.y_ - self.y), name="loss")

        # train operation RMSPropOptimizer
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
        a = self.Q_values(state)
        self.log_q.append(list(state))
        self.log_q.append(a)
        if np.random.rand() <= self.epsilon:
            # random
            act = np.random.choice(self.enable_actions)
        else:
            # max_action Q(state, action)
            act = self.enable_actions[np.argmax(a)]
            
        self.log_act.append([0, act])
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
        self.log_q.append(list(state))
        self.log_q.append(a)
        angle = float(state[0][0])
        if angle<-45:
            return 6
        elif angle>45:
            return 7
        elif np.random.rand() <= self.epsilon:
            # random
            act = np.random.choice(self.enable_actions)
        else:
            # max_action Q(state, action)
            act = self.enable_actions[np.argmax(a)]
            
        self.log_act.append([0, act])
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
        self.replay_memory.append((state, action, reward, state_1, terminal))

    # train the network by replaying experience
    def experience_replay(self):
        """
        ミニバッチ学習を行う
        """
        state_minibatch = []
        y_minibatch = []

        # sample random minibatch
        minibatch_size = min(len(self.replay_memory), self.minibatch_size)
        #minibatch_indexes = np.random.randint(0, len(self.replay_memory), minibatch_size)

        #最新の経験をミニバッチに確定で入れるかどうか
        
        #minibatch_indexes = np.random.randint(0, len(self.replay_memory), minibatch_size-1)
        #minibatch_indexes = np.insert(minibatch_indexes,0,len(self.replay_memory)-1)
    
        beta = np.random.beta(4,1,self.minibatch_size)
        beta = beta * len(self.replay_memory)
        minibatch_indexes = [int(n) for n in beta]

        self.minibatch_index_log = np.concatenate([self.minibatch_index_log, minibatch_indexes])
        k = np.append(self.minibatch_index_log,-1)
        self.minibatch_index_log = k

        # create minibatch dataset
        for j in minibatch_indexes:
            state_j, action_j, reward_j, state_j_1, terminal = self.replay_memory[j]
            action_j_index = self.enable_actions.index(action_j)

            y_j = self.Q_values(state_j)

            if terminal:
                y_j[action_j_index] = reward_j
            else:
                # reward_j + DiscountFactor * max_action' Q(state', action')
                y_j[action_j_index] = reward_j + self.discount_factor * np.max(self.Q_values(state_j_1))  # NOQA

            state_minibatch.append(state_j)
            y_minibatch.append(y_j)

        # training
        self.sess.run(self.training, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})

        # for logging
        self.current_loss = self.sess.run(self.loss, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})
        self.log_loss.append([-1, self.current_loss])

    def create_checkpoint(self):
        self.saver.save(self.sess, os.path.join(self.model_dir, self.checkpoint_name + datetime.now().strftime('%H%M%S')))

    def load_model(self, model_path):
        # load from model_path
        #self.saver.restore(self.sess,os.path.join(self.model_dir, model_path))
        ckpt = tf.train.get_checkpoint_state(self.folder + '/../' + model_path + '/')
        if ckpt:
            self.saver.restore(self.sess, self.folder + '/../' + model_path + '/' + MODEL_NAME)
            return True
        else:
            return False

    def save_model(self):
        #self.saver.save(self.sess, os.path.join(self.model_dir, self.model_name))
        self.saver.save(self.sess, self.folder + '/' + self.model_name)

    def debug_nn(self):
        with open(self.folder + '/debug.csv', 'a') as f:
            np.savetxt(f, self.sess.run(self.W_fc1))
            np.savetxt(f, self.sess.run(self.b_fc1))
            np.savetxt(f, self.sess.run(self.W_fc2))
            np.savetxt(f, self.sess.run(self.b_fc2))
            np.savetxt(f, self.sess.run(self.W_out))
            #np.savetxt(f, self.sess.run(self.b_out))
        np.savetxt(self.folder + '/debug_W_fc1.csv', self.sess.run(self.W_fc1), delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc1.csv', self.sess.run(self.b_fc1), delimiter=',')
        np.savetxt(self.folder + '/debug_W_fc2.csv', self.sess.run(self.W_fc2), delimiter=',')
        np.savetxt(self.folder + '/debug_b_fc2.csv', self.sess.run(self.b_fc2), delimiter=',')
        np.savetxt(self.folder + '/debug_W_out.csv', self.sess.run(self.W_out), delimiter=',')
        np.savetxt(self.folder + '/debug_b_out.csv', self.sess.run(self.b_out), delimiter=',')
        '''
        with open('debug_nn' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')  # 改行コード（\n）を指定しておく
            writer.writerows(self.sess.run(self.W_fc1))
            writer.writerows(self.sess.run(self.b_fc1))
            writer.writerows(self.sess.run(self.W_fc2))
            writer.writerows(self.sess.run(self.b_fc2))
            writer.writerows(self.sess.run(self.W_out))
            writer.writerows(self.sess.run(self.b_out))
            f.close()
        '''

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