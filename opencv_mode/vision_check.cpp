#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;
int hmin=0, smin=0, vmin =0 ;
int hmax=19, smax=240, vmax =255;
void getColor(Mat frame);
Mat img,HSVframe,dst,drt;
//Point myPoint(0, 0);
//Point imgcer(0, 0);

//新点集容器
vector<vector<int>>newPoints;
//识别颜色数据
vector<vector<int>>myColor{ {88,108,66,222,255,255}, //黄//{0,51,35,147,161,255} }; //初音未来
	                        {77 ,106 ,3 ,252,162,255},//绿
							//{111,179,125,198,196,255},//红
							//{0  ,41 ,184,255,83 ,255},//蓝
	                      };
                       
//画笔颜色
vector<Scalar>myColorType       {  {0,255,0},  //绿
							       {0,0,255},  //红
							       {255,0,0},  //蓝
	                               {255,255,0} //黑
                                 };

	void cer(Mat srclmage,Mat buflmg)
	{
        int Y=0;
	    int X=0;
		int PixCount = 0;
		int ImgWidth = buflmg.cols;//目标结果图像的宽
		int ImgHeight = buflmg.rows;//目标结果图像的长
		int ImgChannels = buflmg.channels();//通道数
		for (int y = 0; y < ImgHeight; y++)
		{
			for (int x = 0; x < ImgWidth; x++)
			{
				if (buflmg.data[y * ImgWidth + x] == 255)
				{
					X += x;
					Y += y;
					PixCount++;
				}
			}
		}
		if (PixCount > 0)
		{
			X /= PixCount;
			Y /= PixCount;
			printf("质心坐标（%d,%d)\n", X, Y);
		}
		else
		{
			printf("未找到光点...\n");
		}
		
		Point line_begin = Point(X - 10, Y);
		Point line_end = Point(X + 10, Y);
		line(srclmage, line_begin, line_end, Scalar(255, 0, 0));
		line_begin.x = X; line_begin.y = Y - 10;
		line_end.x = X; line_end.y = Y + 10;
		line(srclmage, line_begin, line_end, Scalar(255, 0, 0));

	}
//创建点集Point
void getContours(Mat dilimg)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	
	//寻找轮廓
	findContours(dilimg, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_TC89_L1, Point(0, 0));
	
	vector<vector<Point>>approxCurve(contours.size());//
	vector<Rect>boundRect(contours.size());
	vector<Rect>boundRects(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		float area = contourArea(contours[i]);

		cout << area << endl;
		//排除误差
		if (area > 990.52&&area<10000)
		{
			float pir = arcLength(contours[i], true);
			approxPolyDP(contours[i], approxCurve[i], 0.02 * pir, true);//计算轮廓周长
			
			//cout << contours[i].size() << endl;
			boundRect[i] = boundingRect(approxCurve[i]);
			boundRects[i] = boundingRect(contours[i]);
			////创建起点坐标
			//myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			//myPoint.y = boundRect[i].y;
			
			//图形边框
			//drawContours(img, approxCurve, i, Scalar(0, 255, 0), 5);
			
			//用矩形框起目标图形
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 5);
		
			//putText(img, to_string(/*imgcer.x*/2), imgcer, FONT_HERSHEY_COMPLEX, 3, Scalar(0, 0, 255), 2, 8);
		}
	  
		
	}
	//return myPoint;
}
void getColor(Mat frame)
{
	
	cvtColor(frame, HSVframe, COLOR_RGB2HSV);
	    
	for (int i = 0; i < myColor.size(); i++)
	{
		Scalar min(myColor[i][0], myColor[i][2], myColor[i][4]);
		Scalar max(myColor[i][1], myColor[i][3], myColor[i][5]);
		inRange(HSVframe, min, max, dst);
		getContours(dst);
		//定义newPoints数组
		/*Point myPoint=getContours(dst);
		if (myPoint.x != 0)
		{
           newPoints.push_back({myPoint.x,myPoint.y,i});
		}*/
	}
}

////画笔的形态
//void drawonColor(vector<vector<int>>myColor, vector<Scalar>myColorType)
//{
//	for (int i = 0; i < newPoints.size(); i++)
//	{
//		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorType[newPoints[i][2]], FILLED);
//	}
//}

//调节开关
void Track()
{
   //调节开关
	namedWindow("ds", (640, 250));
	createTrackbar("H min", "ds", &hmin, 179);
	createTrackbar("H max", "ds", &hmax, 179);		
	createTrackbar("S min", "ds", &smin, 255);
	createTrackbar("S max", "ds", &smax, 255);
	createTrackbar("V min", "ds", &vmin, 255);
	createTrackbar("V max", "ds", &vmax, 255);
	
}
//寻找颜色
 void checkColor(Mat frame)
{
    
	
	cvtColor(frame, HSVframe, COLOR_RGB2HSV);
	//颜色阈值
	Scalar min(hmin,smin,vmin);//没有等于；错误写法：Scalar min=（233，34，35）；
	Scalar max(hmax, smax, vmax);
	inRange(HSVframe, min, max, dst);
	namedWindow("lv tu", WINDOW_NORMAL);
	imshow("lv tu", dst);
    cout << hmin <<"  " << hmax <<"   " << smin <<"  " << smax <<"  " << vmin <<"  " << vmax << endl;
}
int main()
{
	VideoCapture cup(0);
	if (!cup.isOpened())
	{
		printf("not load video");
	}
	Track();
	while (true)
	{
		cup.read(img);
		
		//drawonColor(myColor,myColorType);
		checkColor(img);
		//getColor(img);
		cer(img,dst);
		namedWindow("img", WINDOW_NORMAL);
		imshow("img", img);
		
		waitKey(1);
	}
	waitKey(0);
	system("pause");
	return 0;
}