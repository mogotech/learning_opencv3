#include "opencv2/opencv.hpp"

int main(int argc, char *argv[]) {
    cv::namedWindow("Example 3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    if (!cap.open(std::string(argv[1]))) {
        printf("open file %s failed.", argv[1]);
    }

    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::imshow("Example 3", frame);
        char key = cv::waitKey(33) & 0xFF;
        if (key >= 0) {
            printf("key %d pressed, break!\n", key);
            break;
        }
    }

    return 0;
}