import os
import numpy as np
import tensorflow as tf
from collections import deque
from datetime import datetime
import collections

import csv


import logging
import warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
warnings.simplefilter(action='ignore', category=FutureWarning)
warnings.simplefilter(action='ignore', category=Warning)
tf.get_logger().setLevel('INFO')
tf.autograph.set_verbosity(0)
tf.get_logger().setLevel(logging.ERROR)

#--------------------------const, directory name, model name, etc...-------------------------
MODEL_NAME = "WiflyDual_DQN" + str(datetime.today())[0:10]
MINIBATCH_SIZE = 8
REPLAY_MEMORY_SIZE = 100000
LEARNING_RATE = 0.001
DISCOUNT_FACTOR = 0.95
EPSILON = 0.05
MODEL_DIRECTORY = os.path.join(os.path.dirname(os.path.abspath(__file__)), "models")
CHECKPOINT_NAME = "WiflyDual_DQN"
N_ACTIONS = 4 # number of actions
ENABLE_ACTIONS = [1,2,3,4]
FRAMES = 2
INPUTS = 2

MIDDLE_1 = 4
MIDDLE_2 = 4
#----------------------------------------------------------------------------------------------


class DQNAgent:
    def __init__(self):
        # Load parameters
        self.name = os.path.splitext(os.path.basename(__file__))[0]
        self.minibatch_size = MINIBATCH_SIZE
        self.replay_memory_size = REPLAY_MEMORY_SIZE
        self.learning_rate = LEARNING_RATE
        self.discount_factor = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.model_dir = MODEL_DIRECTORY
        self.model_name = MODEL_NAME
        self.checkpoint_name = CHECKPOINT_NAME
        self.n_actions = N_ACTIONS
        self.enable_actions = ENABLE_ACTIONS

        self.minibatch_ind = np.empty(0)
        self.loss_y = [1]
        self.loss_x = [1]
        self.loss_plt = []
        self.x_ax = []
        self.log_q = []
        self.log_act = []
        self.log_loss = []
        self.log_loss_detail = []
        self.log_aim = []

        # create deque object for replay memory
        self.replay_memory = deque(maxlen=self.replay_memory_size)

        # create TensorFlow graph (model)
        self.init_model()

    def init_model(self):
        # input layer (4 x 5)
        self.x = tf.placeholder(tf.float32, [None, FRAMES, INPUTS], name="x")

        # flatten (20)
        with tf.name_scope('reshape'):
            x_flat = tf.reshape(self.x, [-1, FRAMES*INPUTS])

        # input layer. fully connected(20)
        with tf.name_scope('fc1'):
            self.W_fc1 = tf.Variable(tf.truncated_normal([FRAMES*INPUTS, MIDDLE_1], stddev=0.01), name="W_fc1")
            self.b_fc1 = tf.Variable(tf.zeros([MIDDLE_1]), name="b_fc1")
            h_fc1 = tf.nn.relu(tf.matmul(x_flat, self.W_fc1) + self.b_fc1)

        # hidden layer. fully connected (20)
        with tf.name_scope('fc2'):
            self.W_fc2 = tf.Variable(tf.truncated_normal([MIDDLE_1, MIDDLE_2], stddev=0.01), name="W_fc2")
            self.b_fc2 = tf.Variable(tf.zeros([MIDDLE_2]),  name="b_fc2")
            self.h_fc2 = tf.nn.relu(tf.matmul(h_fc1, self.W_fc2) + self.b_fc2)

        # output layer. fully connected (3)
        with tf.name_scope('output'):
            # output layer (n_actions)
            self.W_out = tf.Variable(tf.truncated_normal([MIDDLE_2, self.n_actions], stddev=0.01), name="W_out")
            #self.b_out = tf.Variable(tf.zeros([self.n_actions]), name="b_out")
            self.y = tf.matmul(self.h_fc2, self.W_out)
            #self.y = tf.matmul(self.h_fc2, self.W_out) + self.b_out

        # loss function
        with tf.name_scope('loss'):
            self.y_ = tf.placeholder(tf.float32, [None, self.n_actions])
            self.loss = tf.reduce_sum(tf.square(self.y_ - self.y), name="loss")

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
        self.summary_writer = tf.summary.FileWriter("WiFly_DQN_TensorBoard", graph=self.sess.graph)

    # return Q(state, action) for each
    def Q_values(self, state):
        return self.sess.run(self.y, feed_dict={self.x: [state]})[0]

    def select_action(self, state):
        self.Q = self.Q_values(state)
        self.log_q.append(self.Q)

        if np.random.rand() <= self.epsilon:
            self.log_act.append([0,  np.random.choice(self.enable_actions)])
            # random
            return np.random.choice(self.enable_actions)
        else:
            self.log_act.append([1,  self.enable_actions[np.argmax(self.Q)]])
            # max_action Q(state, action)
            return self.enable_actions[np.argmax(self.Q)]

    # store experience to replay memory
    def store_experience(self, state, action, reward, state_1, terminal, act):
        self.replay_memory.append((state, action, reward, state_1, terminal, act))

    # train the network by replaying experience
    def experience_replay(self):
        state_minibatch = []
        y_minibatch = []

        # sample random minibatch
        minibatch_size = min(len(self.replay_memory), self.minibatch_size)
        minibatch_indexes = np.random.randint(0, len(self.replay_memory), minibatch_size-1)
        minibatch_indexes_ch = np.insert(minibatch_indexes,0,len(self.replay_memory)-1)


        self.minibatch_ind = np.concatenate([self.minibatch_ind, minibatch_indexes_ch])
        k = np.append(self.minibatch_ind,-1)
        self.minibatch_ind = k


        num = 0
        # create minibatch dataset
        for j in minibatch_indexes_ch:
            state_j, action_j, reward_j, state_j_1, terminal, act_j = self.replay_memory[j]
            action_j_index = self.enable_actions.index(action_j)

            y_j = self.Q_values(state_j)

            if terminal:
                y_j[action_j_index] = reward_j
            else:
                # reward_j + DiscountFactor * max_action' Q(state', action')
                y_j[action_j_index] = reward_j + self.discount_factor * max(np.max(self.Q_values(state_j_1)), 4.0)  # NOQA
                # y_j[action_j_index] = reward_j + self.discount_factor * np.min(self.Q_values(state_j_1))  # NOQA
                # y_j[action_j_index] = reward_j + self.discount_factor * self.Q_values(state_j_1)[act_j-1]  # NOQA

            state_minibatch.append(state_j)
            y_minibatch.append(y_j)

            self.log_aim.append([action_j_index, y_j[action_j_index], reward_j, np.max(self.Q_values(state_j_1))])
            #self.log_aim.append([action_j_index, y_j[action_j_index], reward_j, np.min(self.Q_values(state_j_1))])
            #self.log_aim.append([action_j_index, y_j[action_j_index], reward_j, self.Q_values(state_j_1)[act_j-1]])
            #num += 1
            self.loss_y[0] = y_j
            self.loss_x[0] = state_j
            loss = self.sess.run(self.loss, feed_dict={self.x: self.loss_x, self.y_: self.loss_y})
            self.log_loss.append([j, loss])
            #if self.ind_loss > 5.0:
            #    print(y_j[action_j_index],end="")
            #    print()
            #    print(self.Q_values(state_j)[action_j_index],end="")
            #    print()
            #    print("num:" + str(j) + ":  " + "{0:.3f}".format(self.ind_loss))

        # training
        self.sess.run(self.training, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})

        # for logging
        current_loss = self.sess.run(self.loss, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})
        self.log_loss.append([-1, current_loss])
        #self.minibatch_ind.append(self.current_loss)
        #print("loss:" + str(self.current_loss))
        #self.loss_plt.append(self.current_loss)
        #self.x_ax.append(len(self.loss_plt))


    def create_checkpoint(self):
        self.saver.save(self.sess, os.path.join(self.model_dir, self.checkpoint_name + datetime.now().strftime('%H%M%S')))


    def load_model(self, model_path):
        # load from model_path
        self.saver.restore(self.sess,os.path.join(self.model_dir,  model_path))


    def save_model(self):
        self.saver.save(self.sess, os.path.join(self.model_dir, self.model_name))

    def debug_nn(self):
        with open('debug/debug.csv', 'a') as f:
            np.savetxt(f, self.sess.run(self.W_fc1))
            np.savetxt(f, self.sess.run(self.b_fc1))
            np.savetxt(f, self.sess.run(self.W_fc2))
            np.savetxt(f, self.sess.run(self.b_fc2))
            np.savetxt(f, self.sess.run(self.W_out))
            #np.savetxt(f, self.sess.run(self.b_out))
        np.savetxt('debug/debug_W_fc1.csv', self.sess.run(self.W_fc1), delimiter=',')
        np.savetxt('debug/debug_b_fc1.csv', self.sess.run(self.b_fc1), delimiter=',')
        np.savetxt('debug/debug_W_fc2.csv', self.sess.run(self.W_fc2), delimiter=',')
        np.savetxt('debug/debug_b_fc2.csv', self.sess.run(self.b_fc2), delimiter=',')
        np.savetxt('debug/debug_W_out.csv', self.sess.run(self.W_out), delimiter=',')
        #np.savetxt('debug_b_out.csv', self.sess.run(self.b_out), delimiter=',')
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
        with open('debug/debug_memory' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.replay_memory)

    def debug_minibatch(self):
        #print(self.minibatch_ind)
        np.savetxt('debug/debug_minibatch.csv', self.minibatch_ind, delimiter=',', fmt='%s')

    def debug_q(self):
        with open('debug/debug_q' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_q)
        with open('debug/debug_act' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_act)

    def debug_loss(self):
        with open('debug/debug_loss' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_loss)

    def debug_aim(self):
        with open('debug/debug_aim' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_aim)