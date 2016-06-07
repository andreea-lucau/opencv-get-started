#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const char *WINDOW_NAME = "Create Image";


int main(int argc, char** argv )
{
    Mat image(500, 1000, CV_8UC3, Scalar(0, 0, 255));
    if (image.empty()) {
        printf("No image data \n");
        return -1;
    }

    namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
    imshow(WINDOW_NAME, image);

    waitKey(0);

    destroyWindow(WINDOW_NAME);

    return 0;
}
