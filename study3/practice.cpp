//
// Created by aa on 22. 9. 21.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << " Hello CV" << endl;
    Point pt1;
    pt1.x = 5;
    pt1.y = 10;
    Point pt2(100, 100);
    cout << pt1.dot(pt2) << endl;

    Size sz1;
    sz1.width = 100;
    sz1.height = 200;
    cout << sz1.area() << endl;

    Rect rc1(pt1,sz1);
    cout << rc1.x << ", "<< rc1.y << ", "<< rc1.width << ", "<< rc1.height << endl;

    RotatedRect rr1(pt1, sz1, 30);
    Point2f pts[4];
    rr1.points(pts);
    for(auto i : pts)
        cout << i << endl;

    Mat img;
    img = imread("images/cat.bmp");
    namedWindow("choisugil");
    imshow("choisugil", img);
    waitKey();
    return 0;
}