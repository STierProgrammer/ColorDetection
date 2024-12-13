#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using std::string;
using cv::Mat;
using cv::Scalar;

int main() {
	int H_MIN = 0, S_MIN = 110, V_MIN = 153;
	int H_MAX = 19, S_MAX = 240, V_MAX = 255;

	Mat img = cv::imread("Resources/lambo.png");
	Mat imgHSV, mask;

	cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	cv::namedWindow("Trackbars", (640, 200));
	cv::createTrackbar("Hue Min", "Trackbars", &H_MIN, 179);
	cv::createTrackbar("Hue Max", "Trackbars", &H_MAX, 179);
	cv::createTrackbar("Sat Min", "Trackbars", &S_MIN, 255);
	cv::createTrackbar("Sat Max", "Trackbars", &S_MAX, 255);
	cv::createTrackbar("Val Min", "Trackbars", &V_MIN, 255);
	cv::createTrackbar("Val Max", "Trackbars", &V_MAX, 255);

	while (true) {
		Scalar lower(H_MIN, S_MIN, V_MIN);
		Scalar upper(H_MAX, S_MAX, V_MAX);

		cv::inRange(imgHSV, lower, upper, mask);

		cv::imshow("Image", img);
		cv::imshow("Image HSV", imgHSV);
		cv::imshow("Image Mask", mask);
		cv::waitKey(1);
	}

	return 0;
}