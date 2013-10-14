#include <opencv2/opencv.hpp>
#include <stdio.h>

uchar findMedium(uchar area[], int length) {
	for (int i = 0; i < length; ++i) {
		// printf("%d ", area[i]);
		for (int j = 0; j < length; ++j) {
			if(area[i] > area[i + 1]) {
				uchar temp = area[i];
				area[i] = area[i + 1];
				area[i] = temp;
			}
		}
	}

	return area[(length - 1) / 2];
}

IplImage *mediumFilter(IplImage *src, int nWindowSize) {
	IplImage* image = cvCreateImage(cvGetSize(src), src->depth, 1);
	int nRadius = (nWindowSize - 1) / 2;
	uchar *area = new uchar[nWindowSize * nWindowSize];
	printf("%d\n", nRadius);
	memset(area, 0, nWindowSize * nWindowSize * sizeof(char));
	for(int i = nRadius; i < src->height - nRadius; ++i) {
		for(int j = nRadius; j < src->widthStep - nRadius; ++j) {
			uchar *temp = area;
			for(int k = -nRadius; k <= nRadius; ++k) {
				for(int l = -nRadius; l <=nRadius; ++l) {
					*temp= (uchar)(src->imageData[src->widthStep*(i + k) + j + l]);
					temp++;
				}
			}
			printf("%d\n", findMedium(area, nWindowSize * nWindowSize));
			image->imageData[image->widthStep * i + j] = findMedium(area, nWindowSize * nWindowSize);
		}
	}
	return image;
}

int main(int argc, char const *argv[])
{
	IplImage *srcImg = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", srcImg);
	cvWaitKey(0);
	IplImage *destImg = mediumFilter(srcImg, 3);
	cvNamedWindow("Medium", CV_WINDOW_AUTOSIZE);
	cvShowImage("Medium", destImg);
	cvWaitKey(0);

	return 0;
}