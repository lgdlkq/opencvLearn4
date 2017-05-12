#include<opencv2/highgui/highgui.hpp>//OpenCV highgui模块头文件
#include<opencv2/imgproc/imgproc.hpp>//OpenCV 图像处理头文件

using namespace cv;

int main() {
	Mat srcImage = imread("1.jpg");
	imshow("原图", srcImage);
	
	//图像腐蚀
	//进行腐蚀操作,腐蚀就是用图像中的暗色部分腐蚀掉图像中亮色部分
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));//指定腐蚀的形状和大小
	Mat dstImage;
	erode(srcImage, dstImage, element);//腐蚀

	imshow("腐蚀效果图", dstImage);
	waitKey(0);

	//图像模糊
	Mat dstImage1;
	blur(srcImage, dstImage1, Size(7, 7));//均值滤波操作
	imshow("滤波效果图", dstImage1);
	waitKey(0);
	
	//Canny边缘检测
	Mat edge, grayImage;
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);//将源图像转换位灰度图像
	blur(grayImage, edge, Size(3, 3));//先用3x3的内核进行降噪
	Canny(edge, edge, 3, 9, 3);//运行Canny算子
	imshow("边缘检测", edge);
	waitKey(0);

	return 0;
}