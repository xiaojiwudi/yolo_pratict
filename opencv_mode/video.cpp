/*#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	//VideoCapture out("C:\\Users\\sb\\Desktop\\练习小视频.mp4");
	VideoCapture out(0);
	if (!out.isOpened())
	{
		printf("Could not load video");
		return -1;
	}
	double ftp = out.get(CAP_PROP_FPS);
	Size size (out.get(CAP_PROP_FRAME_WIDTH), out.get(CAP_PROP_FRAME_HEIGHT));
	VideoWriter write("C:\\Users\\sb\\Desktop\\dem1.mp4", -1,ftp, size, true);
	Mat frame;
	namedWindow("video", WINDOW_NORMAL);
	while (out.read(frame))
	{
		imshow("video", frame);
		write.write(frame);
		char c = waitKey(100);
		if (c == 27)
		{
			break;
		}
	}
	waitKey(0);
	
	
	
	system("pause");
	return 0;
}*/