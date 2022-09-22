#include "opencv2/opencv.hpp"
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main()
{
    Mat img(400, 400, CV_8SC3, Scalar(255,255,255));
    TickMeter tm;
    double tmtmp;
    tmtmp=tm.getTimeMilli();
    namedWindow("img");
    for (int i = 0; i < 110; i+= 10) {
        if (tm.getTimeMilli()-tmtmp< 100)
            sleep(0.001);
        line(img, Point(50, 50 + i * 2), Point(100, 100 + i), Scalar(0, 0, 255), 3);
        imshow("img", img);
    }


    imshow("img", img);
    waitKey();
}