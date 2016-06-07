#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

const char *WINDOW_NAME = "Capture Webcam";
const char *BINARY_NAME = "CaptureWebcam";


int main(int argc, char** argv )
{
    if (argc != 2) {
        std::cout << "Usage:\n./" << BINARY_NAME << " <Video Path>\n";
        return -1;
    }

    VideoCapture video(0);
    if (!video.isOpened()) {
        std::cout << "No video data \n";
        return -1;
    }

    double width = video.get(CV_CAP_PROP_FRAME_WIDTH);
    double height = video.get(CV_CAP_PROP_FRAME_HEIGHT);

    namedWindow(WINDOW_NAME, CV_WINDOW_NORMAL);
    Size frameSize(static_cast<int>(width), static_cast<int>(height));
    VideoWriter videoWriter(argv[1], CV_FOURCC('D', 'I', 'V', 'X'), 20, frameSize, true);
    if (!videoWriter.isOpened()) {
        std::cout << "ERROR: Failed to write the video\n";
        return -1;
    }

    std::cout << "Saving video to " << argv[1] << "\n";

    while (true) {
        Mat frame;
        bool success = video.read(frame);
        if (!success) {
            std::cout << "Failed to read frame\n";
            continue;
        }

        videoWriter.write(frame);
        imshow(WINDOW_NAME, frame);

        // Escape to exit
        if (waitKey(30) == 27)
            break;
    }

    return 0;
}
