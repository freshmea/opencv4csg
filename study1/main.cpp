#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img;
	img = imread("study1/lena.jpg", IMREAD_REDUCED_GRAYSCALE_2);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

    imwrite("study1/lena_tmp.bmp", img);

	namedWindow("image");
	imshow("image", img);

	waitKey();
	return 0;
}
