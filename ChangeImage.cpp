#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const char *WINDOW_NAME = "Change Image";
const char *BINARY_NAME = "ChangeImage";

Mat IMAGE;

void brightness_changed(int brightness_value, void *user_data) {
    int contrast_value = *( static_cast<int*>(user_data));

    Mat output_image;
    int brightness  = brightness_value - 50;
    double contrast = contrast_value / 50.0;

    IMAGE.convertTo(output_image, -1, contrast, brightness);
    imshow(WINDOW_NAME, output_image);
}


void contrast_changed(int contrast_value, void *user_data) {
    int brightness_value = *( static_cast<int*>(user_data));

    Mat output_image;
    int brightness  = brightness_value - 50;
    double contrast = contrast_value / 50.0;

    IMAGE.convertTo(output_image, -1, contrast, brightness);
    imshow(WINDOW_NAME, output_image);
}


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./" << BINARY_NAME << " <Image Path>\n";
        return -1;
    }

    IMAGE = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
    if (IMAGE.empty()) {
        printf("No image data \n");
        return -1;
    }

    namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);

    //Create trackbar to change brightness
    int brightness_value = 50;
    //Create trackbar to change contrast
    int contrast_value = 50;

    createTrackbar(
            "Brightness", WINDOW_NAME, &brightness_value, 100,
            brightness_changed, &contrast_value);

    createTrackbar(
            "Contrast", WINDOW_NAME, &contrast_value, 100,
            contrast_changed, &brightness_value);

    imshow(WINDOW_NAME, IMAGE);

    waitKey(0);
    destroyWindow(WINDOW_NAME);

    return 0;
}
