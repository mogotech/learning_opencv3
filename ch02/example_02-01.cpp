#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
    cv::Mat img = cv::imread(argv[1], -1);
    if (img.empty()) {
        printf("image read error!\n");
        return -1;
    }
    cv::namedWindow("Example 1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example 1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example 1");

    return 0;
}