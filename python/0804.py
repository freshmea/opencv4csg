# 0804.py
import cv2
import numpy as np

#1
def findLocalMaxima(src):
    kernel= cv2.getStructuringElement(shape=cv2.MORPH_RECT, ksize=(11,11))
    dilate = cv2.dilate(src,kernel)
    localMax = (src == dilate)
    
    erode = cv2.erode(src,kernel)
    localMax2 = src > erode      
    localMax &= localMax2
    points = np.argwhere(localMax == True)
    points[:,[0, 1]] = points[:,[1, 0]] 
    return points
#2
src = cv2.imread('python/data/CornerTest.jpg')
gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
res = cv2.cornerHarris(gray, blockSize=5, ksize=3, k=0.01)
ret, res = cv2.threshold(np.abs(res),0.02, 0, cv2.THRESH_TOZERO)
res8 = cv2.normalize(res, None, 0, 255, cv2.NORM_MINMAX, dtype=cv2.CV_8U)
cv2.imshow('res8',  res8)

corners = findLocalMaxima(res)
print('corners=', corners)

#3
#corners = np.float32(corners).copy()
corners = corners.astype(np.float32, order='C')
term_crit = (cv2.TERM_CRITERIA_MAX_ITER+cv2.TERM_CRITERIA_EPS, 10, 0.01)
corners2 = cv2.cornerSubPix(gray, corners,(5,5),(-1,-1), term_crit)
print('corners2=', corners2)

dst = src.copy()
for x, y in np.int32(corners2):    
    cv2.circle(dst, (x, y), 3, (0,0,255), 2)
cv2.imshow('dst',  dst)
cv2.waitKey()
cv2.destroyAllWindows()
