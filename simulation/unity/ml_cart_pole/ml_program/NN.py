import os
import numpy as np
import tensorflow as tf
from collections import deque
from datetime import datetime
import collections
import copy
import csv

#--------------------------const, directory name, model name, etc...-------------------------
MINIBATCH_SIZE = 8
REPLAY_MEMORY_SIZE = 100000
LEARNING_RATE = 0.001
DISCOUNT_FACTOR = 0.95
EPSILON = 0.05
MODEL_DIRECTORY = os.path.join(os.path.dirname(os.path.abspath(__file__)), "models")
CHECKPOINT_NAME = "WiflyDual_DQN"
N_ACTIONS = 2 # number of actions
ENABLE_ACTIONS = [1,2]
FRAMES = 1
INPUTS = 5

MIDDLE_1 = 4
MIDDLE_2 = 4
#----------------------------------------------------------------------------------------------


class NN:
    def __init__(self):
        # Load parameters
        self.name = os.path.splitext(os.path.basename(__file__))[0]
        self.minibatch_size = MINIBATCH_SIZE
        self.replay_memory_size = REPLAY_MEMORY_SIZE
        self.learning_rate = LEARNING_RATE
        self.discount_factor = DISCOUNT_FACTOR
        self.epsilon = EPSILON
        self.model_dir = MODEL_DIRECTORY
        self.checkpoint_name = CHECKPOINT_NAME
        self.n_actions = N_ACTIONS
        self.enable_actions = ENABLE_ACTIONS


        self.loss_y = [1]
        self.loss_x = [1]
        self.log_loss = []
        self.log_loss_total = []

        # create TensorFlow graph (model)
        self.init_model()

    def init_model(self):
        # input layer (4 x 5)
        self.x = tf.placeholder(tf.float32, [None, FRAMES*INPUTS], name="x")

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
            self.b_out = tf.Variable(tf.zeros([self.n_actions]), name="b_out")
            #self.y = tf.matmul(self.h_fc2, self.W_out)
            self.y = tf.matmul(self.h_fc2, self.W_out) + self.b_out

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
        self.summary_writer = tf.summary.FileWriter("DQN_TensorBoard", graph=self.sess.graph)

    # train the network by replaying experience
    def experience_replay(self, replay_memory, minibatch):
        # sample random minibatch
        minibatch_size = minibatch
        state_minibatch = []
        y_minibatch_ = []
        minibatch_indexes = np.random.randint(0, len(replay_memory), minibatch_size)

        print(minibatch_indexes)
        # create minibatch dataset
        for j in minibatch_indexes:
            state_j, action_j, reward_j, state_j_1, act_j = replay_memory[j]
            #print(replay_memory[j])
            if action_j == 1.0:
                move = -50.0
            elif action_j == 2.0:
                move = -5.0
            elif action_j == 3.0:
                move = 5.0
            elif action_j == 4.0:
                move = 50.0
            state_j_ = copy.copy(state_j)
            #print(state_j_)
            state_j_.append(move)
            #print(state_j_)
            state_minibatch.append(state_j_)
            #print(state_minibatch)
            y_minibatch_.append([state_j_1[0], state_j_1[1]])
            #print(y_minibatch)
            #print("state: " + str(state_j))
            #print("next: " + str(state_j_1[0]) + " , " + str(state_j_1[1]))

            #self.loss_x[0] = state_j
            #a = self.sess.run(self.y, feed_dict={self.x: self.loss_x})
            #loss = self.sess.run(self.loss, feed_dict={self.x: self.loss_x, self.y_: [[state_j_1[0],state_j_1[1]]]})
            #self.log_loss.append([j, loss])

        #print(y_minibatch)
        #print(len(state_minibatch))
        # training
        x_minibatch = np.array(state_minibatch)
        y_minibatch = np.array(y_minibatch_)
        #print(x_minibatch)
        #print(y_minibatch)
        self.sess.run(self.training, feed_dict={self.x: x_minibatch, self.y_: y_minibatch})
        # for logging
        current_loss = self.sess.run(self.loss, feed_dict={self.x: state_minibatch, self.y_: y_minibatch})
        self.log_loss.append([current_loss])

    def test_nn(self, replay_memory):
        # sample random minibatch
        state_minibatch = []
        y_minibatch_ = []
        # create minibatch dataset
        for j in range(len(replay_memory)):
            state_j, action_j, reward_j, state_j_1, act_j = replay_memory[j]
            if action_j == 1.0:
                move = -50.0
            elif action_j == 2.0:
                move = -5.0
            elif action_j == 3.0:
                move = 5.0
            elif action_j == 4.0:
                move = 50.0
            
            state_j_ = copy.copy(state_j)
            #print(state_j_)
            state_j_.append(move)
            #print(state_j_)
            state_minibatch.append(state_j_)
            #print(state_minibatch)
            y_minibatch_.append([state_j_1[0], state_j_1[1]])
            #self.log_loss.append([j, loss])
        x_minibatch = np.array(state_minibatch)
        y_minibatch = np.array(y_minibatch_)
        current_loss = self.sess.run(self.loss, feed_dict={self.x: x_minibatch, self.y_: y_minibatch})
        self.log_loss_total.append([current_loss])

    def load_model(self, model_path):
        # load from model_path
        self.saver.restore(self.sess, 'nn/state_nn')


    def save_model(self):
        self.saver.save(self.sess, 'nn/state_nn')

    def debug_nn(self):
        np.savetxt('nn/debug_W_fc1.csv', self.sess.run(self.W_fc1), delimiter=',')
        np.savetxt('nn/debug_b_fc1.csv', self.sess.run(self.b_fc1), delimiter=',')
        np.savetxt('nn/debug_W_fc2.csv', self.sess.run(self.W_fc2), delimiter=',')
        np.savetxt('nn/debug_b_fc2.csv', self.sess.run(self.b_fc2), delimiter=',')
        np.savetxt('nn/debug_W_out.csv', self.sess.run(self.W_out), delimiter=',')
        np.savetxt('nn/debug_b_out.csv', self.sess.run(self.b_out), delimiter=',')


    def debug_loss(self):
        with open('nn/debug_loss' + ".csv", 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            #print(type(self.log_loss))
            writer.writerows(self.log_loss)

    def debug_loss_total(self):
        with open('nn/loss_total.csv', 'w') as f:
            writer = csv.writer(f, lineterminator='\n')
            writer.writerows(self.log_loss_total)