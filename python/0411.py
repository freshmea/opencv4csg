# 0411.py
import cv2
import numpy as np
src = cv2.imread('python/data/lena.jpg')
dst_b = np.zeros_like(src)
dst_g = np.zeros_like(src)
dst_r = np.zeros_like(src)
dst = cv2.split(src)
dst_b[:,:,0] = dst[0]
dst_g[:,:,1] = dst[1]
dst_r[:,:,2] = dst[2]
print(type(dst))
print(type(dst[0])) # type(dst[1]), type(dst[2])

cv2.imshow('blue',  dst_b)
cv2.imshow('green', dst_g)
cv2.imshow('red',   dst_r)
cv2.imshow('src', src)
cv2.waitKey()    
cv2.destroyAllWindows()
