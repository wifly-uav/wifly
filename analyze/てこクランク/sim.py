'''
https://sgrsn1711.hatenablog.com/entry/2020/04/26/152331
'''

import cv2
import numpy as np
from math import *

SIMULATOR_WINDOW_NAME = 'link simulator'
FRAME_WIDTH = 10
NODE_RADIUS = 15
NODE_WIDTH = 5
FRAME_COLOR = (0, 0, 0)
POSE_TO_PXL = 0.3

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
    
    def drawFrame(self, img):

        if len(img.shape) == 3:
            self.Height, self.Width, self.channels = img.shape[:3]
        else:
            self.Height, self.Width = img.shape[:2]

        px0 = int(self.x0 * POSE_TO_PXL)
        py0 = self.Height - int(self.y0 * POSE_TO_PXL)
        px1 = int(self.x1 * POSE_TO_PXL)
        py1 = self.Height - int(self.y1 * POSE_TO_PXL)
        cv2.line(img, (px0,py0), (px1,py1), FRAME_COLOR, self.frame_width)
        cv2.circle(img, (px0,py0), NODE_RADIUS, FRAME_COLOR, NODE_WIDTH) 

if __name__ == '__main__':

    controlBox = np.zeros((300,512,3), np.uint8)
    cv2.namedWindow('panel')
    cv2.createTrackbar('deg', 'panel', 0, 1080, lambda x: None)

    l1 = 300
    l2 = 1000
    l3 = 500
    l4 = 1500
    l5 = 1100

    f1 = Frame(l1)
    f2 = Frame(l2)
    f3 = Frame(l3)
    f4 = Frame(l4)
    f5 = Frame(l5)

    img = np.zeros((600,1000,3), np.uint8)
    img[:,:,:] = 255
    while True:

        img = np.zeros((600,1000,3), np.uint8)
        img[:,:,:] = 255

        # 順運動学
        deg = cv2.getTrackbarPos('deg', 'panel')    # θ1はトラックバーから操作
        (x0, y0) = (400, 1500)
        x3, y3 = x0+l5, y0
        f1.set_position(x0, y0, deg*pi/180)
        (x1, y1) = f1.get_EndPosition()
        L = sqrt( (x3-x1)**2 + (y3-y1)**2 )
        theta2 = acos( (l2**2 + L**2 - l3**2) / (2*l2*L) ) + atan2(y3-y1, x3-x1)
        f2.set_position(x1, y1, theta2)
        (x2, y2) = f2.get_EndPosition()
        theta3 = atan2(y3-y2, x3-x2)
        f3.set_position(x2, y2, theta3)
        f4.set_position(x3, y3, theta3)
        x4, y4 = f4.get_EndPosition()
        f5.set_position(x0, y0, atan2(y3-y0, x3-x0) )

        f1.drawFrame(img)
        f2.drawFrame(img)
        f3.drawFrame(img)
        f4.drawFrame(img)
        f5.drawFrame(img)

        cv2.imshow(SIMULATOR_WINDOW_NAME, img)

        if cv2.waitKey(1) > 0:
            break

    cv2.destroyAllWindows()