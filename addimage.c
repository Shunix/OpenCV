#include  <opencv2/highgui/highgui.hpp>
#include  <opencv2/core/core.hpp>
using namespace cv;

int main(int argc, char const *argv[])
{
	//IplImage *result = cvCreateImage(cvGetSize(large), IPL_DEPTH_8U, 3);
	Mat smallMat = imread(argv[1]);
	Mat largeMat = imread(argv[2]);
	Mat result;
	// IplImage *resize = cvCreateImage(cvGetSize(large), IPL_DEPTH_8U, 3);
	// cvResize(small, resize, CV_INTER_LINEAR);
	// cvNamedWindow("Large", CV_WINDOW_AUTOSIZE);
	// cvShowImage("Large", resize);
	// cvWaitKey(0);
	addWeighted(smallMat, 0.5, largeMat, 0.5, 0.0, result);
	cvNamedWindow("Result", CV_WINDOW_AUTOSIZE);
	imshow("Result", result);
	cvWaitKey(0);
	return 0;
}