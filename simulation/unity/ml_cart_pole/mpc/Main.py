import numpy as np
from Environment import Environment
import matplotlib.pyplot as plt
import time
from cvxpy import *

n_state = 4   # 状態の数
m_state = 1   # 制御入力の数
T = 100  # 何ステップ先まで予測するかを決める

#simulation parameter
delta_t = 0.01

M = 1.0  # [kg]
m = 0.05  # [kg]
g = 9.8  # [m/s^2]
l = 3  # [m]

# Model Parameter
A_f = np.array([
    [0.0, 1.0, 0.0, 0.0],
    [0.0, 0.0, m * g / M, 0.0],
    [0.0, 0.0, 0.0, 1.0],
    [0.0, 0.0, g * (M + m) / (l * M), 0.0]
    ])
#A = np.eye(n_state) + delta_t * A_f

B_f = np.array([
    [0.0],
    [1.0 / M],
    [0.0],
    [1.0 / (l * M)]
    ])
#B = delta_t * B_f

# 倒立振子の初期状態
# 今回はすべてが0に収束するよう目指す
x_0 = np.array([
    [-0.02],
    [0.0],
    [0.02],
    [0.0]
    ])
#[x,dx,θ,dθ]

x = Variable(n_state, str(T+1))
u = Variable(m_state, str(T))

cost_arr = np.array([
    [1.0, 0.0, 0.0, 0.0],
    [0.0, 1.0, 0.0, 0.0],
    [0.0, 0.0, 0.1, 0.0],
    [0.0, 0.0, 0.0, 0.1]
    ])


print('start? y/n')
ans_yn = input()
if (ans_yn == 'y'):
    print('start mpc')
env = Environment()


while True:
    states = []
    env.observe_update_state()
    state = env.observe_state()
    x_0[0] = state[0]
    x_0[1] = state[0]/state[2]
    x_0[2] = -state[1]
    x_0[3] = -state[1]/state[2]
    A = np.eye(n_state) + state[2] * A_f
    B = state[2] * B_f
    
    for t in range(T):
        # コスト関数の値が小さくなるような配列uを求める
        cost = sum_squares(cost_arr*x[:,t+1]) + sum_squares(0.1*u[:,t])
        # 制約式（線形方程式と制御入力の限界値）を与える
        constr = [x[:,t+1] == A*x[:,t] + B*u[:,t],
                    norm(u[:,t], 'inf') <= 20.0]
        states.append( Problem(Minimize(cost), constr) )
    # sums problem objectives and concatenates constraints.
    prob = sum(states)
    # 制約をさらに2つ追加する
    # 最後の状態(Tステップ後の状態)はすべてが0、すなわち理想の状態とすること
    # そして、現在の状態x0は事実としてあるので、制約となる
    prob.constraints += [x[:,T] == 0, x[:,0] == x_0]

    start = time.time()
    result=prob.solve(verbose=False)

    # 発散した場合は制御不能として終了
    if result == float("inf"):
        print("Cannot optimize")
        import sys
        sys.exit()

    # 最適とされる制御入力の配列を取得
    good_u_arr = np.array(u[0,:].value[0,:])[0]

    env.excute_action(good_u_arr)

    # 制御入力を入れて、次の状態を得る
    # 今回はノイズを考えない

env.stop_sim()
