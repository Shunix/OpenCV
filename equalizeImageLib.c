#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

int main(int argc, char const *argv[])
{
	IplImage* srcImg = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", srcImg);
	cvWaitKey(0);
	IplImage* srcChannel[4]={0, 0, 0, 0};
	for(int i = 0; i < srcImg->nChannels; ++i) {
		srcChannel[i] = cvCreateImage(cvGetSize(srcImg), srcImg->depth, 1);
	}
	cvSplit(srcImg, srcChannel[0], srcChannel[1], srcChannel[2], srcChannel[3]);
	for(int i = 0; i < srcImg->nChannels; ++i) {
		cvEqualizeHist(srcChannel[i], srcChannel[i]);
	}
	cvMerge(srcChannel[0], srcChannel[1], srcChannel[2], srcChannel[3], srcImg);
	cvNamedWindow("Equlaized", CV_WINDOW_AUTOSIZE);
	cvShowImage("Equalized", srcImg);
	cvWaitKey(0);
	return 0;
}