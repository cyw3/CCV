#include<iostream>
#include"cv.h"
#include"highgui.h"
#include"cxcore.h"
using namespace std;
/*
��һ�������ڽ�ͼ�ĳ���
*/
int main()
{
 // ���� console ����
 //#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
 //��������һ��ͼ��
 IplImage* img = cvLoadImage("wo.jpg");
 //��ȡ��imgԭͼ�е�ROI������Ϊ����ͼ������
 cvSetImageROI(img, cvRect(10, 10, 200, 200));
 //����һ�ſյ���ͼ��������ROI����ͼ��
 IplImage* dst = cvCreateImage(cvSize(200,200),8,3);
 cvResize(img, dst);
 //cvCopy(img, dst);
 //ȡ��ROI�������ã��ָ�img
 cvResetImageROI(img);
 //��ʾͼ��
 cvNamedWindow("scr", CV_WINDOW_AUTOSIZE);
 cvNamedWindow("dst", CV_WINDOW_AUTOSIZE);
 cvShowImage("scr", img);
 cvShowImage("dst", dst);
 cvWaitKey(5000);
 system("pause");
 cvDestroyWindow("scr");
 cvDestroyWindow("dst");
 cvReleaseImage(&img);
 cvReleaseImage(&dst);
 return 0;
}
