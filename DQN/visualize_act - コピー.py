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
        
        
        plt.plot(time,angle)
        plt.ylim(-90,90)
        plt.plot([0, time[-1]],[10, 10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[-10, -10], "red", linestyle='dashed')
        plt.plot([0, time[-1]],[0, 0], "black")
        plt.title("ANGLE",fontsize=25)
        plt.savefig(self.folder + '/angle.png')
        plt.show()    
        #_ = ax1.plot([0, time[-1]],[10, 10], "orange", linestyle='dashed')
        #_ = ax1.plot([0, time[-1]],[-10, -10], "orange", linestyle='dashed')
        #ln3 = ax2.plot(time, act, color="blue", linestyle='dashdot', linewidth = 0.3, label='Action')


if __name__ == "__main__":
    path = os.path.dirname(__file__)

    ac = visual_act(flag=1,folder=path + '/result/12_16_betaI0_', save=True)
    ac.visualize()
