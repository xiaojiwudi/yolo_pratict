/*#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
void getContours(Mat dilimg, Mat img)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(dilimg, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_TC89_L1, Point(0, 0));
	vector<vector<Point>>approxCurve(contours.size());//?
	vector<Rect>boundRect(contours.size());
	string objectType;
	for (int i = 0; i < contours.size(); i++)
	{
		float area = contourArea(contours[i]);

		cout << area << endl;
		if (area > 10000)
		{
			float pir = arcLength(contours[i], true);//?
			approxPolyDP(contours[i], approxCurve[i], 0.02 * pir, true);//?
			drawContours(img, approxCurve, i, Scalar(21, 21, 0), 5);//?
			cout << contours[i].size() << endl;
			boundRect[i] = boundingRect(approxCurve[i]);


			int objCor = (int)approxCurve[i].size();
			     if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4) { objectType = "Rect"; }
			else if (objCor == 5) { objectType = "Pentagon"; }
			else if (objCor == 6) { objectType = "hexagon"; }
			else if (objCor > 6)  { objectType = "Circle"; }
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);//?
			putText(img, objectType, {boundRect[i].x,boundRect[i].y}, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0), 1, 8);

		}
	}
}
int main(void*)
{
	Mat img,dst,grayimg,cannyimg,blurimg,dilimg;
	string space = "C:\\Users\\sb\\Desktop\\无标题.png"; 
	img = imread(space);
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//灰值图像
	GaussianBlur(grayimg, blurimg, Size(3, 3), 3, 0);//高斯模糊
	Canny(blurimg, cannyimg, 25, 75);//Kanny边缘检测
	Mat Kernal = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	dilate(cannyimg, dilimg, Kernal);//膨胀
	getContours(dilimg,img);
	namedWindow("img", WINDOW_NORMAL);  
	//namedWindow("grayimg", WINDOW_NORMAL);
	//namedWindow("blurimg", WINDOW_NORMAL);
	//namedWindow("cannyimg", WINDOW_NORMAL);
	//namedWindow("dilimg", WINDOW_NORMAL);
	imshow("img", img);
	//imshow("grayimg", grayimg);
	//imshow("blurimg", blurimg);
	//imshow("cannyimg", cannyimg);
	//imshow("dilimg", dilimg);
	waitKey(0);
	system("pause");
	return 0;
}*/