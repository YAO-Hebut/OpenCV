#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat imgHSV, mask, imgColor;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

VideoCapture cap(0);
Mat img;
int main()
{
    namedWindow("Trackbars", (640, 200)); //create window
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 179);
    createTrackbar("Sat Max", "Trackbars", &smax, 179);
    createTrackbar("Val Min", "Trackbars", &vmin, 179);
    createTrackbar("Val Max", "Trackbars", &vmax, 179);

    while (true)
    {
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        inRange(imgHSV, lower, upper, mask);
        cout << hmin << "," << smin << "," << vmin << "," << smax << "," << hmax << "," << vmax << endl;
        imshow("Image", img);
        imshow("Mask", mask);

        waitKey(1);
    }
    return 0;
}