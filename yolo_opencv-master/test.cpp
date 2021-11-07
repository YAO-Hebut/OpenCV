#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;

int main()
{
    namedWindow("Example5", WINDOW_AUTOSIZE);

    VideoCapture cap;
    cap.open(0);
    //VideoCapture cap(0);这句话可以替代上面两个语句，效果是一致的。
    if (!cap.isOpened())
    {
        std::cerr << "Couldn't open capture." << std::endl;
        return -1;
    }

    Mat frame;
    while (1)
    {
        cap >> frame;
        if (frame.empty())
            break;
        imshow("Example5", frame);
        if (waitKey(33) >= 0)
            break;
    }

    getchar();
    return 0;
}
