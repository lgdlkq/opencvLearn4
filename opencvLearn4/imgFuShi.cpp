#include<opencv2/highgui/highgui.hpp>//OpenCV highguiģ��ͷ�ļ�
#include<opencv2/imgproc/imgproc.hpp>//OpenCV ͼ����ͷ�ļ�

using namespace cv;

int main() {
	Mat srcImage = imread("1.jpg");
	imshow("ԭͼ", srcImage);
	//���и�ʴ����,��ʴ������ͼ���еİ�ɫ���ָ�ʴ��ͼ������ɫ����
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));//ָ����ʴ����״�ʹ�С
	Mat dstImage;
	erode(srcImage, dstImage, element);//��ʴ

	imshow("��ʴЧ��ͼ", dstImage);
	waitKey(0);

	//ͼ��ģ��
	Mat dstImage1;
	blur(srcImage, dstImage1, Size(7, 7));//��ֵ�˲�����
	imshow("�˲�Ч��ͼ", dstImage1);
	waitKey(0);

	return 0;
}