/*#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int element_size = 1;
int max_size = 5;
Mat str,dst;
void Gedilate(int ,void*);
void Geerode(int, void*);
int main()
{
	//图像混合
	/*Mat str1, str2, dst;
	str1 = imread("C:\\Users\\sb\\Desktop\\miku.jpg.webp"); 
	str2 = imread("C:\\Users\\sb\\Desktop\\miku1.jpg.webp");
	if ( str1.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	if (str2.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	double alphe = 0.5;
	if (str1.rows == str2.rows && str1.cols == str2.cols && str1.type() == str2.type())
	{
		addWeighted(str1, alphe, str2, (1 - alphe),0.0, dst);
		namedWindow("output", WINDOW_AUTOSIZE);
		imshow("output", dst);

	}
	else
	{
		cout << "不能输出" << endl;
	}

    //提高图像的亮度与对比度//contrast and brightned
	/*Mat str, dst;
	str = imread("C:\\Users\\sb\\Desktop\\miku1.jpg.webp");
	if (str.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", str);
	int height = str.rows;
	int width = str.cols;
	float alpha = 100000;//提升对比度
	float bet = -34;//改变亮度
	str.convertTo(str, CV_32F);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (str.channels() == 3)
			{
				float b = str.at<Vec3f>(row, col)[0];
				float g = str.at<Vec3f>(row, col)[1];
				float r = str.at<Vec3f>(row, col)[2];

				str.at<Vec3f>(row, col)[0] = alpha * b + bet;
				str.at<Vec3f>(row, col)[1] = alpha * g + bet;
				str.at<Vec3f>(row, col)[2] = alpha * r + bet;
			}
			else if (str.channels() == 1)
			{
				int gray = str.at<uchar>(row, col);
				str.at<Vec3f>(row, col) = alpha * gray + bet;
			}
		}
	}
	const char* name = "contrast and beightned change";
	namedWindow(name, WINDOW_AUTOSIZE);
	imshow(name, str);

	

	str = imread("C:\\Users\\sb\\Desktop\\无标题.png");
	if (str.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	//腐蚀与膨胀
	/*Gedilate(0,0);
	createTrackbar("Track", "output", &element_size, max_size, Gedilate);//调节开关
	Geerode(0, 0);
	createTrackbar("Track", "erode output", &element_size, max_size, Geerode);

	//开，闭操作
	Mat srt,ptr,ttu;
	cvtColor(str, dst, COLOR_BGR2GRAY);
	adaptiveThreshold(dst, srt, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, -2);
	Mat t= getStructuringElement(MORPH_RECT, Size(7, 7), Point(-1, -1));
	
  	dilate(dst, ttu, t, Point(-1, -1));
	erode(ttu, ptr, t, Point(-1, -1));
	//morphologyEx(srt,ptr,MORPH_OPEN,t );
	imshow("sdfghjkl", ptr);
	
	
	waitKey(0);
	system("pause");
	return 0;
}*/
/*void Myline()//画线
{
	Point p1=Point(56,76);
	Point p2 = Point(23, 34);
	Scalar color=Scalar(255, 0, 0);
	line(str, p1, p2, color, 1, 8, 0);
}
void MyfillPoly()//填充颜色
{
	Point ptr[1][5];//由五个点组成
	ptr[0][0] = Point(100, 100);
	ptr[0][1] = Point(200, 100);
	ptr[0][2] = Point(200, 200);
	ptr[0][3] = Point(100, 200);
	ptr[0][4] = Point(100, 100);

	const Point* pps[] = { ptr[0] };//多边形数组指针//每个轮廓由五个点组成
	int npt[] = { 5 };//每个多边形顶点个数
	Scalar color = Scalar(255, 34, 245);
	fillPoly(str, pps,npt, 1,color,8);
}
void Myrondom()//随机数
{
	RNG rng(12345);
	Point ptr1;
	Point ptr2;
	Mat bg = Mat::zeros(str.size(), str.type());
	
	for (int i = 0; i < 10000; i++)
	{
      
	   ptr1.x = rng.uniform(0, str.rows);
	   ptr2.x = rng.uniform(0, str.rows);
	   ptr1.y = rng.uniform(0, str.cols);
	   ptr2.y = rng.uniform(0, str.cols);
       Scalar color=Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	   waitKey(50);//预留时间格出
	   line(bg, ptr1, ptr2, color, 1, 8, 0);
	   imshow("qwertyuiop[", bg);
	}
}*/
/*void Gedilate(int, void*)
{
	int s = element_size * 2 + 1;
	Mat t = getStructuringElement(MORPH_CROSS, Size(s, s), Point(-1, -1));
	dilate(str, dst, t);
	namedWindow("output", WINDOW_NORMAL);
	imshow("output", dst);

}
void Geerode(int, void*)
{
	int s = element_size * 2 + 1;
	Mat t = getStructuringElement(MORPH_CROSS, Size(s, s), Point(-1, -1));
	erode(str, dst, t);
	namedWindow("erode output", WINDOW_NORMAL);
	imshow("erode output", dst);
}*/