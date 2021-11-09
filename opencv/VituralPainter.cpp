#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
vector<vector<int>> myColors{
    {126, 30, 73, 179, 179, 179} //Blue
};

void getContours(Mat imgDil)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);
        cout << area << endl;

        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        string objectType;
        if (area > 1000)
        {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            cout << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]);

            drawContours(img, conPoly, i, Scalar(0, 47, 147), 2);
        }
    }
}

void findColor(Mat img)
{
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    for (int i = 0; i < myColors.size(); i++)
    {
        Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
        Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
        Mat mask;
        inRange(imgHSV, lower, upper, mask);
        imshow(to_string(i), mask);
    }
}

int main()
{
    VideoCapture cap(0);
    Mat img;

    while (true)
    {
        cap.read(img);
        findColor(img);
        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}