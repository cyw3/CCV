#include<iostream>
#include"cv.h"
#include"highgui.h"
#include"cxcore.h"
using namespace std;

//��ӳ����˹ģ���Ͼ�������Ԫ��ֵԶԶ��������Ԫ��ֵ��������Ȼ��Ȼ���൱���м�ֵ�õ�����
int main()
{
 //����һ�Ŵ������ͼƬ
 IplImage* img = cvLoadImage("wo.jpg");
 //����һ���Զ����С��ͼ�񣬴Ӷ���������ͼ��Ĵ�С
 IplImage* myimg = cvCreateImage(cvSize(400,400),8,3);
 //��ɫͼ��ת��Ҷ�ͼ��
 IplImage* lastimg = cvCreateImage(cvSize(400, 400), 8, 1);
 //*********************************************
    //�������ͼ��
 IplImage* dst = cvCreateImage(cvSize(myimg->width,myimg->height),8,1);
 //���µ���ͼ���С
 cvResize(img, myimg);
 //RGBͼ��ת���ɻҶ�ͼ��
 cvCvtColor(myimg, lastimg,CV_BGR2GRAY);
 cvNamedWindow("scr");
 cvNamedWindow("Guase Filter");
 //��3*3�ĸ�˹ģ�壬sigma=2���и�˹�˲�
 cvSmooth(lastimg,dst, CV_GAUSSIAN,3,3,0.8);
 cvShowImage("scr", lastimg);
 cvShowImage("Guase Filter", dst);
 cvWaitKey(50000);
    system("pause");
 cvReleaseImage(&img);
 cvReleaseImage(&dst);
 cvReleaseImage(&myimg);
 cvReleaseImage(&lastimg);
 cvDestroyAllWindows();
 return 0;
}
