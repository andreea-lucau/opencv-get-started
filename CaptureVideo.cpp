#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char *WINDOW_NAME = "Capture Video";


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./CaptureVideo <Video Path>\n";
        return -1;
    }

    VideoCapture video(argv[1]);
    //VideoCapture video(0);
    if (!video.isOpened()) {
        std::cout << "No video data \n";
        return -1;
    }

    namedWindow(WINDOW_NAME, CV_WINDOW_NORMAL);

    while (true) {
        Mat frame;
        bool success = video.read(frame);
        if (!success) {
            std::cout << "Failed to read frame\n";
            continue;
        }

        imshow(WINDOW_NAME, frame);

        // Escape to exit
        if (waitKey(30) == 27)
            break;
    }

    return 0;
}
