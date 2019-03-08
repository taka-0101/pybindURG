#robot libliry import
import pybindURG
from pybindURG import urgCommunication
import math
import cv2
import numpy as np

def calc (data):
    # Create a black image
    img = np.zeros((1000,1000,3), np.uint8)
    if len(data) != 0:
        for i in range(len(data)):
            if i+1 < len(data) :
                cv2.line(img,data[i],data[i+1],(255,0,0),1)
        
        cv2.line(img,(500,500),data[len(data)-1],(255,255,0),1)
        cv2.line(img,(500,500),data[0],(255,255,255),1)

    return img

urg = urgCommunication("COM5")
while True:
    data = urg.run() #data:radian1,length1,radian2,length2....
    
    point = []
    for i in range(int(len(data)/2)):
        x = int(data[2*i+1] * math.cos(data[2*i]) / 10)
        y = int(data[2*i+1] * math.sin(data[2*i]) / 10)
        if abs(x) > 10 and abs(y) > 10:
            point.append((int(x+500),int(y+500)))
    cv2.imshow("a",calc(point))
    cv2.waitKey(1)





