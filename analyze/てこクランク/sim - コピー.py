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
import os

SIMULATOR_WINDOW_NAME = 'link simulator'
FRAME_WIDTH = 1
NODE_RADIUS = 15
NODE_WIDTH = 5
FRAME_COLOR = (0, 0, 0)
POSE_TO_PXL = 500
    
def drawFrame(self, img, color=FRAME_COLOR):

    if len(img.shape) == 3:
        self.Height, self.Width, self.channels = img.shape[:3]
    else:
        self.Height, self.Width = img.shape[:2]


    cv2.line(img, (px0,py0), (px1,py1), color, FRAME_WIDTH)

if __name__ == '__main__':
    path = os.path.dirname(__file__)
    mode = 0

    outst = np.loadtxt(path+'/outst.csv', delimiter=',', encoding="utf-8-sig")
    inst = np.loadtxt(path+'/inst.csv', delimiter=',', encoding="utf-8-sig")
    print(outst.shape)

    while True:

        img = np.zeros((800,1200,3), np.uint8)
        img[:,:,:] = 255

        if len(img.shape) == 3:
            Height, Width, channels = img.shape[:3]
        else:
            Height, Width = img.shape[:2]

        (x0, y0) = (400, 500)

        if mode:
            for i in range(len(outst)):
                if i%100==0:
                    x1 = x0+(outst[i][1]/180*pi)*0.5*POSE_TO_PXL
                    y1 = y0
                    x2 = x1+sin(outst[i][0]/180*pi)*0.2*POSE_TO_PXL
                    y2 = y1-cos(outst[i][0]/180*pi)*0.2*POSE_TO_PXL
                    print(outst[i][0])
                    #print(str(x1)+','+str(y1))
                    #print(str(x2)+','+str(y2))
                    px0 = int(x1)
                    py0 = Height - int(y1)
                    px1 = int(x2)
                    py1 = Height - int(y2)
                    #print(str(px0)+','+str(py0))
                    #print(str(px1)+','+str(py1))
                    cv2.line(img, (px0,py0), (px1,py1), FRAME_COLOR, FRAME_WIDTH)
        else:
            for i in range(len(inst)):
                if i%100==0:
                    x1 = x0+(inst[i][1]/180*pi)*0.5*POSE_TO_PXL
                    y1 = y0
                    x2 = x1+sin(inst[i][0]/180*pi)*0.2*POSE_TO_PXL
                    y2 = y1-cos(inst[i][0]/180*pi)*0.2*POSE_TO_PXL
                    #print(str(x1)+','+str(y1))
                    #print(str(x2)+','+str(y2))
                    px0 = int(x1)
                    py0 = Height - int(y1)
                    px1 = int(x2)
                    py1 = Height - int(y2)
                    #print(str(px0)+','+str(py0))
                    #print(str(px1)+','+str(py1))
                    cv2.line(img, (px0,py0), (px1,py1), FRAME_COLOR, FRAME_WIDTH)

        #f1.drawFrame(img)

        cv2.imshow(SIMULATOR_WINDOW_NAME, img)

        if cv2.waitKey(0) > 0:
            break

    cv2.destroyAllWindows()