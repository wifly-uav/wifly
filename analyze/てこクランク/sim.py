'''
https://sgrsn1711.hatenablog.com/entry/2020/04/26/152331
'''

import cv2
import numpy as np
from math import *
import time
from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg

SIMULATOR_WINDOW_NAME = 'link simulator'
FRAME_WIDTH = 10
NODE_RADIUS = 15
NODE_WIDTH = 5
FRAME_COLOR = (0, 0, 0)
POSE_TO_PXL = 0.5

#　PyQtのウィンドウ表示
app = QtGui.QApplication([])
win = pg.GraphicsWindow()
win.resize(500, 500)
win.setWindowTitle('pyqtgraph example: 1D-Plot')
pg.setConfigOptions(antialias=True)


p = win.addPlot(title="real-time line plot")
p.setRange(yRange = (-100, 100), padding = 0)
curve = p.plot(pen='c')
curve_ = p.plot(pen='g')

def update():
    global curve, curve_, ti, angle, angle_
    curve.setData(ti, angle)
    curve_.setData(ti, angle_)

class Frame:
    def __init__(self, frame_length, frame_width=FRAME_WIDTH, x0=0, y0=0, rad=0, window_name=SIMULATOR_WINDOW_NAME):
        self.length = frame_length
        self.x0 = x0
        self.y0 = y0
        self.rad = rad
        self.x1 = self.x0 + self.length * cos(self.rad)
        self.y1 = self.y0 + self.length * sin(self.rad)
        self.window_name = window_name
        self.frame_width = frame_width
 
    def set_position(self, x0, y0, rad):
        self.x0 = x0
        self.y0 = y0
        self.rad = rad
        self.x1 = self.x0 + self.length * cos(self.rad)
        self.y1 = self.y0 + self.length * sin(self.rad)
    
    def get_EndPosition(self):
        return self.x1, self.y1
    
    def drawFrame(self, img, color=FRAME_COLOR):

        if len(img.shape) == 3:
            self.Height, self.Width, self.channels = img.shape[:3]
        else:
            self.Height, self.Width = img.shape[:2]

        px0 = int(self.x0 * POSE_TO_PXL)
        py0 = self.Height - int(self.y0 * POSE_TO_PXL)
        px1 = int(self.x1 * POSE_TO_PXL)
        py1 = self.Height - int(self.y1 * POSE_TO_PXL)
        cv2.line(img, (px0,py0), (px1,py1), color, self.frame_width)
        cv2.circle(img, (px0,py0), NODE_RADIUS, FRAME_COLOR, NODE_WIDTH) 

if __name__ == '__main__':

    controlBox = np.zeros((300,512,3), np.uint8)
    cv2.namedWindow('panel')
    cv2.createTrackbar('deg', 'panel', 0, 1080, lambda x: None)
    cv2.createTrackbar('hz', 'panel', 0, 15, lambda x: None)

    a = 35.5
    b = 7
    c = 32.5
    d = 15
    e = 220

    bias = 8
    measure_time = 3
    mem = 10000

    ti = []
    angle = []
    angle_ = []

    l1 = b*bias
    l2 = c*bias
    l3 = d*bias
    l4 = e*bias
    l5 = a*bias

    f1 = Frame(l1)
    f2 = Frame(l2)
    f3 = Frame(l3)
    f4 = Frame(l4)
    f5 = Frame(l5)

    f2_ = Frame(l2)
    f3_ = Frame(l3)
    f4_ = Frame(-1*l4)

    start_time = time.time()
    degree = 0
    while True:

        img = np.zeros((800,1200,3), np.uint8)
        img[:,:,:] = 255

        speed = cv2.getTrackbarPos('hz', 'panel')
        degree = speed*360*(time.time()-start_time)
        degree = int(degree%1080)
        deg = cv2.getTrackbarPos('deg', 'panel')+degree

        (x0, y0) = (200, 600)
        x3, y3 = x0, y0+l5
        f1.set_position(x0, y0, deg*pi/180)
        (x1, y1) = f1.get_EndPosition()
        L = sqrt( (x3-x1)**2 + (y3-y1)**2 )
        theta2 = acos( (l2**2 + L**2 - l3**2) / (2*l2*L) ) + atan2(y3-y1, x3-x1)
        theta2_ = -1*acos( (l2**2 + L**2 - l3**2) / (2*l2*L) ) + atan2(y3-y1, x3-x1)
        f2.set_position(x1, y1, theta2)
        f2_.set_position(x1, y1, theta2_)
        (x2, y2) = f2.get_EndPosition()
        (x2_, y2_) = f2_.get_EndPosition()
        theta3 = atan2(y3-y2, x3-x2)
        theta3_ = atan2(y3-y2_, x3-x2_)
        f3.set_position(x2, y2, theta3)
        f4.set_position(x3, y3, theta3)
        f3_.set_position(x2_, y2_, theta3_)
        f4_.set_position(x3, y3, theta3_)
        x4, y4 = f4.get_EndPosition()
        x4_, y4_ = f4_.get_EndPosition()
        f5.set_position(x0, y0, atan2(y3-y0, x3-x0) )

        f1.drawFrame(img)
        f2.drawFrame(img)
        f3.drawFrame(img)
        f4.drawFrame(img,(255,0,0))
        f5.drawFrame(img)
        f2_.drawFrame(img)
        f3_.drawFrame(img)
        f4_.drawFrame(img,(0,255,0))

        cv2.imshow(SIMULATOR_WINDOW_NAME, img)

        ti.append(time.time()-start_time)
        angle.append(theta3*180/pi)
        theta3_ = theta3_*180/pi
        if theta3_<0:
            theta3_+=360
        angle_.append(theta3_-180)

        if len(ti)>mem:
            ti.pop(0)
            angle.pop(0)
            angle_.pop(0)

        if ti[-1]-ti[0]>measure_time:
            ti.pop(0)
            angle.pop(0)
            angle_.pop(0)
        
        update()

        if cv2.waitKey(1) > 0:
            break

    cv2.destroyAllWindows()
    QtGui.QApplication.instance().exec_()