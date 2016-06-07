#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const char *WINDOW_NAME = "Create and Save Image";
const char *BINARY_NAME = "CreateAndSaveImage";


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./" << BINARY_NAME << " <Photo Path>\n";
        return -1;
    }

    Mat image(500, 1000, CV_8UC3, Scalar(0, 0, 255));
    if (image.empty()) {
        std::cout << "No image data \n";
        return -1;
    }

    //vector that stores the compression parameters of the image
    std::vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_params.push_back(98);

    bool success = imwrite(argv[1], image, compression_params);
    if (!success) {
        std::cout << "ERROR : Failed to save the image\n";
        return -1;
    }

    std::cout << "Image saved to " << argv[1] << "\n";

    namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
    imshow(WINDOW_NAME, image);

    waitKey(0);

    destroyWindow(WINDOW_NAME);

    return 0;
}
