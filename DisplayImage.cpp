#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const char *WINDOW_NAME = "Display Image";
const char *BINARY_NAME = "DisplayImage";


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./" << BINARY_NAME << " <Image Path>\n";
        return -1;
    }

    Mat image = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
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
