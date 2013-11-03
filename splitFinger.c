#include <opencv2/opencv.hpp>

int getT(IplImage *img, int n) {
	uchar* data = (uchar *)img->imageData;  
	int step = img->widthStep / sizeof(uchar);  
	int nSumLow = 0, countLow = 0;
	int nSumHigh = 0, countHigh = 0;
	for(int i = 0; i < img->height; i++) {
		for(int j = 0;j < img->width; j++) {
        	if(data[i * step + j] < n) {
        		nSumLow += data[i * step + j];
        		countLow++;
        	} else {
        		nSumHigh += data[i * step + j];
        		countHigh++;
        	} 
    	}
	}
	if(countLow == 0) {
		countLow = 1;
	}
	if(countHigh == 0) {
		countHigh = 1;
	}
	int avg = ((nSumLow / countLow) + (nSumHigh / countHigh)) / 2;
	if(avg == n) {
		return avg;
	}
	return getT(img, avg);
}

int main(int argc, char const *argv[])
{
	IplImage *img = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	int t = getT(img, 255);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	cvShowImage("Origin", img);
	cvWaitKey(0);
	uchar* data = (uchar *)img->imageData;  
	int step = img->widthStep / sizeof(uchar);  
	for(int i = 0; i < img->height; i++) {
		for(int j = 0;j < img->width; j++) {
        	if(data[i * step + j] < t) {
        		data[i * step + j] = 0;
        	} else {
        		data[i * step + j] = 255;
        	}
    	}
	}
	cvNamedWindow("Result", CV_WINDOW_AUTOSIZE);
	cvShowImage("Result", img);
	cvWaitKey(0);
	return 0;
}