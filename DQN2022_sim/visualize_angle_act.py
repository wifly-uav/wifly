import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import os
import statistics
from PIL import Image, ImageDraw, ImageFont
import math

class visual_act:
    def __init__(self, folder='log', action=6):
        self.folder = folder
        
        self.im = Image.new("RGB", (10240,5400), (128,128,128))
        self.draw = ImageDraw.Draw(self.im)

        self.max_size = 5000
        self.minimum_size = 1000
        self.min_x = 40
        self.min_y = 100
        self.center_x = self.max_size/2+self.min_x
        self.center_y = self.max_size/2+self.min_y
        self.action_num = action

        self.min_x2 = 5200
        self.min_y2 = 100
        self.center_x2 = self.max_size/2+self.min_x2
        self.center_y2 = self.max_size/2+self.min_y2

        self.point_size = 30
   
        self.size = (self.max_size-self.minimum_size)/(2*(self.action_num-1))
        self.size2 = (self.max_size-self.minimum_size)/(2*2)

    def draw_base(self):
        for i in range(self.action_num):
            self.draw.arc((self.min_x+self.size*i, self.min_y+self.size*i, self.min_x+self.max_size-self.size*i, self.min_y+self.max_size-self.size*i), start=0, end=360, fill=(255, 255, 0),width=10)
        self.draw.ellipse((self.center_x-self.point_size, self.center_y-self.point_size, self.center_x+self.point_size, self.center_y+self.point_size), fill=(255, 0, 0), outline=(0, 0, 0))
        self.draw.line((self.center_x, self.min_y, self.center_x, self.min_y+self.max_size), fill=(255, 255, 0), width=10)
        self.draw.line((self.min_x, self.center_y, self.min_x+self.max_size, self.center_y), fill=(255, 255, 0), width=10)
        #self.im.show()

    def draw_base2(self):
        for i in range(3):
            self.draw.arc((self.min_x2+self.size2*i, self.min_y2+self.size2*i, self.min_x2+self.max_size-self.size2*i, self.min_y2+self.max_size-self.size2*i), start=0, end=360, fill=(255, 255, 0),width=10)
        self.draw.ellipse((self.center_x2-self.point_size, self.center_y2-self.point_size, self.center_x2+self.point_size, self.center_y2+self.point_size), fill=(255, 0, 0), outline=(0, 0, 0))
        self.draw.line((self.center_x2, self.min_y2, self.center_x2, self.min_y2+self.max_size), fill=(255, 255, 0), width=10)
        self.draw.line((self.min_x2, self.center_y2, self.min_x2+self.max_size, self.center_y2), fill=(255, 255, 0), width=10)
        #self.im.show()
    
    def angleact2pos(self, angle, act):
        pos_x = self.center_x + (self.size*act+self.minimum_size/2)*math.cos(math.radians(angle-90))
        pos_y = self.center_y + (self.size*act+self.minimum_size/2)*math.sin(math.radians(angle-90))
        return 2*self.center_x-pos_x, pos_y
    
    def angleact2pos2(self, angle, diff):
        diff_ = diff/210
        if angle>0:
            pos_x = self.center_x2 + (self.size2*(diff_+1)+self.minimum_size/2)*math.cos(math.radians(angle-90))
            pos_y = self.center_y2 + (self.size2*(diff_+1)+self.minimum_size/2)*math.sin(math.radians(angle-90))
        else:
            pos_x = self.center_x2 + (self.size2*(-diff_+1)+self.minimum_size/2)*math.cos(math.radians(angle-90))
            pos_y = self.center_y2 + (self.size2*(-diff_+1)+self.minimum_size/2)*math.sin(math.radians(angle-90))
        return 2*self.center_x2-pos_x, pos_y

    def load(self):
        self.q = np.loadtxt(self.folder + '/debug_q.csv', delimiter=',')
        self.act = np.loadtxt(self.folder + '/debug_act.csv', delimiter=',')
        self.state = np.loadtxt(self.folder + '/log2.csv', delimiter=',')
        self.pow = np.loadtxt(self.folder + '/log.csv', delimiter=',' ,usecols=[-5,-4])

    def recog(self):
        self.q_max = []
        self.time = []
        self.action = []
        
        for i in self.q:
            self.q_max.append(np.argmax(i)+1)

        self.angle = self.state[:, 0]
        self.time_delta = self.state[:, 2]
        self.action = self.act[:, 0]
        b = np.ones(1)/1
        self.action_conv = np.convolve(self.action, b, mode='same')
        self.pow_left = self.pow[:, 0]
        self.pow_rigiht = self.pow[:, 1]
        self.pow_diff = self.pow_left-self.pow_rigiht

        sum = 0
        for i in self.time_delta:
            sum += i
            self.time.append(sum/1000)

    def visualize(self):
        num = len(self.angle)
        for i in range(num):
            x,y = self.angleact2pos(self.angle[i],self.action_conv[i])
            #print(str(255-int(255/num*i))+","+str(int(255/num*i)))
            self.draw.ellipse((x-self.point_size, y-self.point_size, x+self.point_size, y+self.point_size), fill=(255-int(255/num*i), 0, int(255/num*i)), outline=(0, 0, 0))
        for i in range(num):
            x,y = self.angleact2pos2(self.angle[i],self.pow_diff[i])
            #print(str(x)+","+str(y))
            self.draw.ellipse((x-self.point_size, y-self.point_size, x+self.point_size, y+self.point_size), fill=(255-int(255/num*i), 0, int(255/num*i)), outline=(0, 0, 0))
        self.im.show()

    def save(self):   
        self.im.save(self.folder + '/angle_act.jpg', quality=10)


if __name__ == "__main__":
    path = os.path.dirname(__file__)
    #print("Which data?")
    #data_name  = input()

    ac = visual_act(folder=path + '/result/22_conbeta_test_0_3')
    #ac = visual_act(folder=path + '/result/syuron/1215_dif_1')
    ac.load()
    ac.recog()
    ac.draw_base()
    ac.draw_base2()
    ac.visualize()
    ac.save()