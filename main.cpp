#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

void foo(char *buff, int height, int width)
{
	IplImage *yimg = cvCreateImageHeader(cvSize(width, height), IPL_DEPTH_8U, 1);
	IplImage *uvimg = cvCreateImageHeader(cvSize(width / 2, height / 2),
										  IPL_DEPTH_8U, 2);

	cvSetData(yimg, buff, width);
	cvSetData(uvimg, buff + width * height, width);

	IplImage *fulluvimg = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 2);
	cvResize(uvimg, fulluvimg, CV_INTER_LINEAR);
	cvReleaseImageHeader(&uvimg);

	IplImage *uimg = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	IplImage *vimg = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	cvSplit(fulluvimg, uimg, vimg, NULL, NULL);
	cvReleaseImage(&fulluvimg);

	IplImage *ycrcbimage = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U,
										 3);
	cvMerge(yimg, uimg, vimg, NULL, ycrcbimage);
	cvReleaseImageHeader(&yimg);
	cvReleaseImage(&uimg);
	cvReleaseImage(&vimg);

	IplImage *rgbimg = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	cvCvtColor(ycrcbimage, rgbimg, CV_YCrCb2BGR);
	cvReleaseImage(&ycrcbimage);

	cv::Mat imgx(cv::Size(width, height), 0);
	imgx.data = (uchar *) rgbimg->imageData;
	std::ofstream os("/Users/chan/Downloads/out.bmp", std::ios::binary);
	std::streamsize size = 115200;
	os.write(rgbimg->imageData, size);
	os.flush();
	os.close();
	cv::imshow("rgb", imgx);
	cv::waitKey(0);
}

void read()
{
	std::cout << "Hello, World!" << std::endl;
	std::ifstream is("/Users/chan/Downloads/x.yuv", std::ios::binary);
	std::ofstream os("/Users/chan/Downloads/out.bmp", std::ios::binary);
	std::streamsize size = 115200;
	char buffer[size];
	is.read(buffer, size);
	foo(buffer, 240, 320);
}

int main(int argc, char *argv[])
{
	read();
	return 0;
}