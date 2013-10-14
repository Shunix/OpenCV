#include  <opencv2/highgui/highgui.hpp>
#include  <opencv/cv.h>

int main(int argc, char const *argv[])
{
	IplImage* img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
	IplImage* hsvImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
	IplImage* hImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* sImage = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* vImage = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	cvSplit(img, hImg, sImage, vImage, 0);
	cvCvtColor(img, hsvImg, CV_BGR2HSV);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", img);
	cvWaitKey(0);
	cvNamedWindow("H", CV_WINDOW_AUTOSIZE);
	cvShowImage("H", hImg);
	cvWaitKey(0);
	cvNamedWindow("S", CV_WINDOW_AUTOSIZE);
	cvShowImage("S", sImage);
	cvWaitKey(0);
	cvNamedWindow("V", CV_WINDOW_AUTOSIZE);
	cvShowImage("V", vImage);
	cvWaitKey(0);
	return 0;
}