#include "Detection.h"
#include <iostream>

using namespace std;
using namespace cv;
using namespace dnn;

void TestDetection()
{
	string image_path = "/home/ytq/project/yolo_opencv-master/data/test3.jpeg";
	string save_path = "/home/ytq/project/yolo_opencv-master/data/save3.jpeg";
	Mat img = imread(image_path);
	cout << "width: " << img.cols << endl;
	cout << "height: " << img.rows << endl;
	// Detection detection = Detection();
	// detection.Initialize(img.cols, img.rows);
	// detection.Detecting(img);
	// imwrite(save_path, detection.GetFrame());
	Detection detection;
	detection.Initialize(img.cols, img.rows);
	detection.Detecting(img);
	if (!detection.GetFrame().size().empty())
	{
		cout << "success detection" << endl;
		imwrite(save_path, detection.GetFrame());
		return;
	};
	cout << "failed detection " << endl;
	return;
}

int main()
{
	TestDetection();
	return 0;
}