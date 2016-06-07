#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const char *WINDOW_NAME = "Filter Image";
const char *BINARY_NAME = "FilterImage";


void displayImage(IplImage *image, const char *suffix)
{
    std::string window_name = std::string(WINDOW_NAME) + std::string(" - ") + std::string(suffix);
    cvNamedWindow(window_name.c_str());
    cvShowImage(window_name.c_str(), image);

    waitKey(0);

    cvDestroyWindow(window_name.c_str());
}


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./" << BINARY_NAME << " <Image Path>\n";
        return -1;
    }

    IplImage* image = cvLoadImage(argv[1]);
    if (!image) {
        printf("No image data \n");
        return -1;
    }
    IplImage* output_image = cvCloneImage(image);

    displayImage(image, "Normal");
    cvErode(image, output_image, 0, 2);
    displayImage(output_image, "Erode");
    cvDilate(image, output_image, 0, 2);
    displayImage(output_image, "Dilate");
    cvNot(image, output_image);
    displayImage(output_image, "Invert");

    cvReleaseImage(&image);
    cvReleaseImage(&output_image);

    return 0;
}
