import cv2
import numpy as np
from matplotlib import pyplot as plt

trainData = np.random.randint(0,100,(25,2)).astype(np.float32)

response = np.random.randint(0,2,(25,1)).astype(np.float32)

red = trainData[response.ravel() == 0] #red는 0 class로 분류
plt.scatter(red[:,0],red[:,1], 80,'r','^')

blue = trainData[response.ravel() == 1] #blue는 1 Class분류
plt.scatter(blue[:,0], blue[:,1], 80, 'b', 's')

newcomer = np.random.randint(0,100,(1,2)).astype(np.float32)
plt.scatter(newcomer[:,0], newcomer[:,1],80,'g', 'o')

knn = cv2.ml_KNearest
knn.train(trainData, cv2.ml.ROW_SAMPLE, response)
ret, results, neighbours, dist = knn.findNearest(newcomer, 3) #k 값을 3으로 설정

print ("result : ", results)
print ("neighbours :", neighbours)
print ("distance: ", dist)

plt.show()