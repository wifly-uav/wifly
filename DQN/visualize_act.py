import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import os
import statistics

class visual_act:
    def __init__(self, flag=False, folder='log', save=True):
        self.flag = flag
        self.save = save
        self.folder = folder

    def visualize(self):

        q = np.loadtxt(self.folder + '/debug_q.csv', delimiter=',')
        act = np.loadtxt(self.folder + '/debug_act.csv', delimiter=',')
        state = np.loadtxt(self.folder + '/log2.csv', delimiter=',')

        q_max = []
        time = []

        for i in q:
            q_max.append(np.argmax(i)+1)

        angle = state[:, 0]
        time_delta = state[:, 2]

        med = statistics.median(time_delta)
        sum = 0

        for i in time_delta:
            if i < 0:
                i = med
            if i > 200:
                i = med
            sum += i
            time.append(sum/1000)
        
        fig = plt.figure()
        ax1 = fig.add_subplot(111)
        ln1 = ax1.plot(time, angle, color="red", label='angle')

        ax2 = ax1.twinx()
        ln2 = ax2.plot(time, q_max, color="green", linestyle='dashed',linewidth = 0, marker='.', label='Q_max')
        #ln3 = ax2.plot(time, act, color="blue", linestyle='dashdot', linewidth = 0.3, label='Action')
        
        h1, l1 = ax1.get_legend_handles_labels()
        h2, l2 = ax2.get_legend_handles_labels()
        ax1.legend(h1+h2, l1+l2, loc='lower right')

        ax1.set_ylim([-180, 180])
        ax1.set_xlim([50, 52.5])
        ax2.set_ylim([0,6])

        if self.save:
            plt.savefig(self.folder + '/act.png')
        if self.flag:
            plt.show()


if __name__ == "__main__":
    path = os.path.dirname(__file__)

    ac = visual_act(flag=1,folder=path + '/result/12_16_betaI0', save=False)
    ac.visualize()
