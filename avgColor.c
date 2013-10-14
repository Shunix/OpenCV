#include <opencv2/opencv.hpp>

IplImage* AvgFilter(IplImage* src, int nWindowSize) {
	IplImage* image = cvCreateImage(cvGetSize(src), src->depth, 1);
	int nRadius = (nWindowSize - 1) / 2;
	int nSum = 0;
	for(int i = nRadius; i < src->height - nRadius; ++i) {
		for(int j = nRadius; j < src->widthStep - nRadius; ++j) {
			nSum = 0;
			for(int k = -nRadius; k <= nRadius; ++k) {
				for(int l = -nRadius; l <=nRadius; ++l) {
					nSum += (uchar)(src->imageData[src->widthStep * (i + k) + j + l]);
				}
			}
			image->imageData[image->widthStep * i + j] = (uchar)(nSum / (nWindowSize * nWindowSize));
		}
	}
	return image;
}

int main(int argc, char const *argv[])
{
	IplImage *srcImg = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	IplImage *destImg = cvCreateImage(cvGetSize(srcImg), srcImg->depth, 3);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", srcImg);
	cvWaitKey(0);
	IplImage *rChannel = cvCreateImage(cvGetSize(srcImg), srcImg->depth, 1);
	IplImage *gChannel = cvCreateImage(cvGetSize(srcImg), srcImg->depth, 1);
	IplImage *bChannel = cvCreateImage(cvGetSize(srcImg), srcImg->depth, 1);
	cvSplit(srcImg, rChannel, gChannel, bChannel, NULL);
	rChannel = AvgFilter(rChannel, 3);
	gChannel = AvgFilter(gChannel, 3);
	bChannel = AvgFilter(bChannel, 3);
	cvMerge(rChannel, gChannel, bChannel, NULL, destImg);
	cvNamedWindow("AVG", CV_WINDOW_AUTOSIZE);
	cvShowImage("AVG", destImg);
	cvWaitKey(0);
	return 0;
}