import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import csv
import collections

state = []
state_val = []

with open('debug/debug_memory.csv') as f:
    reader = csv.reader(f)
    for row in reader:
        state.append(row[0])
for i in range(len(state)):
    a = state[i].replace("[","")
    b = a.replace("]","")
    st = b.split(",")
    state_val.append(list(map(float,st)))
#state_val[何番目のmemoryか][length, angle]

n = []
min = []
minibatch = []
m = np.loadtxt('debug/debug_minibatch.csv', delimiter=',')
#print(list(min))
for i in list(m):
    if i != -1.0:
        n.append(i)
        minibatch.append(i)
    else:
        min.append(n)
        n = []
#minibatch[何回目の学習][replay_memoryの何番目を参照したか]

loss_all = []
loss_detail = []
loss_ = []
loss = np.loadtxt('debug/debug_loss.csv', delimiter=',')
number = 0
for i in list(loss):
    if i[0] == -1:
        loss_all.append(i[1]/number)
        loss_detail.append(loss_)
        loss_ = []
        number = 0
    else:
        loss_.append(i)
        number += 1
print(len(loss_all))
print(loss_detail[1200])


'''
fig = plt.figure()
ax = fig.add_subplot(111)

x = []
y = []

for i in range(len(state_val)):
    x.append(state_val[i][0])
    y.append(state_val[i][1])

H = ax.hist2d(x,y, bins=50, cmap=cm.jet)
ax.set_title('state graph')
ax.set_xlabel('x')
ax.set_ylabel('θ')
fig.colorbar(H[3],ax=ax)
plt.show()
'''


'''

fig_2 = plt.figure()
ax_2 = fig_2.add_subplot(111)

w = []
z = []

for i in range(len(min)):
    for j in range(len(min[i])):
        w.append(min[i][j])
        z.append(1)


H_2 = ax_2.hist2d(w,z, bins=50, cmap=cm.jet)
ax_2.set_title('minibatch graph')
ax_2.set_xlabel('number')
ax_2.set_ylabel('times')
fig_2.colorbar(H_2[3],ax=ax_2)
plt.show()
'''


'''
cont = collections.Counter(minibatch)
max_min = max(minibatch)
X = np.array([i for i in range(int(max(minibatch)))])
Y = []
for i in range(int(max(minibatch))):
    Y.append(cont[i])
plt.bar(X, Y, width=1.0)
plt.show()
'''



frame = []
number = []

for i in range(len(min)):
    for j in range(len(min[i])):
        frame.append(i)
        number.append(min[i][j])

fig_3 = plt.figure()

ax_3 = fig_3.add_subplot(1,1,1)

ax_3.scatter(frame,number,s=10)

ax_3.set_title('first scatter plot')
ax_3.set_xlabel('x')
ax_3.set_ylabel('y')

#plt.xlim([0,50])
#plt.ylim([0,50])
plt.xlim([len(min)-50,len(min)+10])


plt.show()
