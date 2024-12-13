#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using std::string;
using cv::Mat;

int main() {
	Mat img = cv::imread("Resources/lambo.png");

	cv::imshow("Image", img);
	cv::waitKey(0);

	return 0;
}