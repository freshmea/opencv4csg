# -*- coding: utf-8 -*-

import cv2
import time

def videoDetector(cam,cascade):
    while True:
        start_t = time.time()
        ret,img = cam.read()
        img = cv2.resize(img,dsize=None,fx=1.0,fy=1.0)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 
        results = cascade.detectMultiScale(gray,            # 입력 이미지
                                           scaleFactor= 1.1,# 이미지 피라미드 스케일 factor
                                           minNeighbors=5,  # 인접 객체 최소 거리 픽셀
                                           minSize=(20,20)  # 탐지 객체 최소 크기
                                           )
        for box in results:
            x, y, w, h = box
            cv2.rectangle(img, (x,y), (x+w, y+h), (255,255,255), thickness=2)

        terminate_t = time.time()
        FPS = 'fps' + str(int(1./(terminate_t - start_t )))
        cv2.putText(img,FPS,(30,30),cv2.FONT_HERSHEY_SIMPLEX,1,(255,255,255),1)
        
        cv2.imshow('facenet',img)
        if cv2.waitKey(1) > 0: 
            break

cascade_filename = 'python/haarcascade_frontalface_alt.xml'
cascade = cv2.CascadeClassifier(cascade_filename)
cam = cv2.VideoCapture('python/sample.mp4')

videoDetector(cam,cascade)