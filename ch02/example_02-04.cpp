#include "opencv2/opencv.hpp"

#include <iostream>
#include <fstream>


int g_slide_position = 0;
int g_run = 1;
int g_dontset = 0;
cv::VideoCapture g_cap;


void onTrackbarSlide(int pos, void *) {
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) {
        g_run = 1;
    }
    g_dontset = 0;
}

int main(int argc, char* argv[]) {
    cv::namedWindow("Example 4", cv::WINDOW_AUTOSIZE);
    g_cap.open(argv[1]);
    int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int width = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "Video has " << frames << " frames of dimensions(" << width << "," << height << ")." << std::endl;

    cv::createTrackbar("position", "Example 4", &g_slide_position, frames, onTrackbarSlide);

    cv::Mat frame;
    for (;;) {
        if (g_run) {
            g_cap >> frame;
            if (frame.empty())
                break;
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("position", "Example 4", current_pos);
            cv::imshow("Example 4", frame);

            g_run -= 1;
        }

        char c = (char)cv::waitKey(10);
        if (c == 's') {  // single step
            g_run = 1;
            std::cout << "single step, run = " << g_run << std::endl;
        } else if (c == 'r') { // run mode
            g_run = -1;
            std::cout << "run mode, run = " << g_run << std::endl;
        } else if (c == 27) {
            break;
        }
    }

    return 0;
}