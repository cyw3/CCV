#include<iostream>
#include"cv.h"
#include"highgui.h"
#include"cxcore.h"
using namespace std;

//反映到高斯模板上就是中心元素值远远大于其他元素值，于是自然而然就相当于中间值得点运算
int main()
{
 //载入一张待处理的图片
 IplImage* img = cvLoadImage("wo.jpg");
 //创建一张自定义大小的图像，从而调整载入图像的大小
 IplImage* myimg = cvCreateImage(cvSize(400,400),8,3);
 //彩色图像转变灰度图像
 IplImage* lastimg = cvCreateImage(cvSize(400, 400), 8, 1);
 //*********************************************
    //创建输出图像
 IplImage* dst = cvCreateImage(cvSize(myimg->width,myimg->height),8,1);
 //重新调整图像大小
 cvResize(img, myimg);
 //RGB图像转换成灰度图像
 cvCvtColor(myimg, lastimg,CV_BGR2GRAY);
 cvNamedWindow("scr");
 cvNamedWindow("Guase Filter");
 //用3*3的高斯模板，sigma=2进行高斯滤波
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
