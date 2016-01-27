#include<iostream>
#include"cv.h"
#include"highgui.h"
#include"cxcore.h"
using namespace std;
/*
做一个类似于截图的程序
*/
int main()
{
 // 隐藏 console 窗口
 //#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
 //首先载入一幅图像
 IplImage* img = cvLoadImage("wo.jpg");
 //提取出img原图中的ROI区域作为“截图”区域
 cvSetImageROI(img, cvRect(10, 10, 200, 200));
 //创建一张空的新图像来承载ROI区域图像
 IplImage* dst = cvCreateImage(cvSize(200,200),8,3);
 cvResize(img, dst);
 //cvCopy(img, dst);
 //取消ROI区域设置，恢复img
 cvResetImageROI(img);
 //显示图像
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
