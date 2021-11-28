import numpy as np
from collections import deque
import tensorflow as tf

__raw_data = "1.0,2.0,3.0,4.0,5.0"
persed_data = [float(i) for i in __raw_data.split(",")[0:5]]
state = deque()

for i in range(4):
    state.append(persed_data)
print("state:" + str(state))

minibach = []
for i in range(2):
  minibach.append(state)
print("minibach:" + str(minibach))

# input layer (4 x 5)
x = tf.placeholder(tf.float32, shape=[None,4,5], name="x")
# flatten (20)
with tf.name_scope('reshape'):
  x_flat = tf.reshape(x, [-1, 20])

with tf.Session() as sess:
  result = sess.run(x, feed_dict={x:minibach})
  print("x:" + str(result))
  result_ = sess.run(x_flat, feed_dict={x:minibach})
  print("x_flat:" + str(result_))