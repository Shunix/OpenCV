#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void Equalize(Mat* img) {
	int min, max;
	int sum = img->cols * img->rows;
	int count[256];
	int all[256];
	for(int i = 0; i < 256; ++i) {
		count[i] = 0;
	}
	// for(int i = 0; i < 256; ++i) {
	// 	percent[i] = 0;
	// }
	for(int i = 0; i < 256; ++i) {
		all[i] = 0;
	}
	for(int i = 0; i < img->rows; ++i) {
		for(int j = 0; j < img->cols; ++j) {
		 	Vec3i bgr = img->at<Vec3b>(i, j);
		 	count[bgr.val[0]]++;
		}
	}
	// for(int i = 0; i < 256; ++i) {
	// 	percent[i] = (count[i] / ((img->rows) * (img->cols)));
	// }
	// for(int i = 0; i < 256; ++i) {
	// 	cout << i << ":";
	// 	cout << percent[i] <<endl;
	// }
	for(int i = 0; i < 256; ++i) {
		for(int j = 0; j < i; ++j) {
			all[i] += count[j];
		}
	}
	min = max = img->at<Vec3b>(0, 0).val[0];
	for(int i = 0; i < img->rows; ++i) {
		for(int j = 0; j < img->cols; ++j) {
			if(max < img->at<Vec3b>(i, j).val[0]) {
				max = img->at<Vec3b>(i, j).val[0];
			}
			if(min > img->at<Vec3b>(i, j).val[0]) {
				min = img->at<Vec3b>(i, j).val[0];
			}
		}
	}
	for(int i = 0; i < img->rows; i++) {
		for(int j = 0; j < img->cols; j++) {
			for(int x = 0; x < 3; ++x) {
				double percent = ((all[img->at<Vec3b>(i, j).val[x]] * 1.0) / sum);
				//img->at<Vec3b>(i, j).val[x] = (int)(percent * (max - min) + min);
				img->at<Vec3b>(i, j).val[x] = (int)(percent * (img->at<Vec3b>(i, j).val[x]));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	Mat srcImg = imread(argv[1]);
	Mat hsvImg;
	cvtColor(srcImg, hsvImg, CV_BGR2HSV);
	vector<Mat> splitImg;
	split(hsvImg, splitImg);
	Equalize(&splitImg[2]);
	merge(splitImg, hsvImg);
	cvtColor(hsvImg, hsvImg, CV_HSV2BGR);
	cvNamedWindow("Origin", CV_WINDOW_AUTOSIZE);
	imshow("Origin", srcImg);
	cvWaitKey(0);
	cvNamedWindow("Equalized", CV_WINDOW_AUTOSIZE);
	imshow("Equalized", hsvImg);
	cvWaitKey(0);

	return 0;
}