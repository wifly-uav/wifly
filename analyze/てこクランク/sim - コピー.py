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
FRAME_WIDTH = 10
NODE_RADIUS = 15
NODE_WIDTH = 5
FRAME_COLOR = (0, 0, 0)
POSE_TO_PXL = 0.5
    
def drawFrame(self, img, color=FRAME_COLOR):

    if len(img.shape) == 3:
        self.Height, self.Width, self.channels = img.shape[:3]
    else:
        self.Height, self.Width = img.shape[:2]

    px0 = int(self.x0 * POSE_TO_PXL)
    py0 = self.Height - int(self.y0 * POSE_TO_PXL)
    px1 = int(self.x1 * POSE_TO_PXL)
    py1 = self.Height - int(self.y1 * POSE_TO_PXL)
    cv2.line(img, (px0,py0), (px1,py1), color, FRAME_WIDTH)

if __name__ == '__main__':
    path = os.path.dirname(__file__)

    outst = np.loadtxt(path+'/outst.csv', delimiter=',')
    inst = np.loadtxt(path+'/inst.csv', delimiter=',')

    bias = 8
    measure_time = 3
    mem = 10000
    while True:

        img = np.zeros((800,1200,3), np.uint8)
        img[:,:,:] = 255


        (x0, y0) = (200, 600)

        f1.drawFrame(img)
        f2.drawFrame(img)
        f3.drawFrame(img)
        f4.drawFrame(img,(255,0,0))
        f5.drawFrame(img)
        f2_.drawFrame(img)
        f3_.drawFrame(img)
        f4_.drawFrame(img,(0,255,0))

        cv2.imshow(SIMULATOR_WINDOW_NAME, img)

        if cv2.waitKey(1) > 0:
            break

    cv2.destroyAllWindows()