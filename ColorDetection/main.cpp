#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#define H_MIN 0
#define S_MIN 110
#define V_MIN 153

#define H_MAX 19
#define S_MAX 240
#define V_MAX 255

using std::string;
using cv::Mat;
using cv::Scalar;

int main() {
	Mat img = cv::imread("Resources/lambo.png");
	Mat imgHSV, mask;

	cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	Scalar lower(H_MIN, S_MIN, V_MIN);
	Scalar upper(H_MAX, S_MAX, V_MAX);

	cv::inRange(imgHSV, lower, upper, mask);

	cv::imshow("Image", img);
	cv::imshow("Image HSV", imgHSV);
	cv::imshow("Image Mask", mask);
	cv::waitKey(0);

	return 0;
}