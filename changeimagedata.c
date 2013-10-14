#include  <opencv2/highgui/highgui.hpp>
#include  <opencv2/core/core.hpp>
using namespace cv;

int main(int argc, char const *argv[])
{
	IplImage* img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
	IplImage* redImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* greenImage = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* blueImage = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	cvSplit(img, blueImage, greenImage, redImg, 0);
	/**
	access values in all three channels
	**/
	for(int y = 0; y < img->height; y++) {
		uchar* ptr = (uchar*) (img->imageData + y * img->widthStep);
		for(int x = 0; x < img->width; x++) {
			//Add B channel
			ptr[3 * x] = saturate_cast<uchar>(ptr[3 * x] - 50);
			//Add G channel
			ptr[3 * x + 1] = saturate_cast<uchar>(ptr[3 * x + 1] - 50);
			//Add R channel
			ptr[3 * x + 2] = saturate_cast<uchar>(ptr[3 * x + 2] - 50);
		}
	}
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", img);
	cvWaitKey(0);
	return 0;
}