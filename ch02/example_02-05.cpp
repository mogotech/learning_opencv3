#include <opencv2/opencv.hpp>


int main(int argc, char* argv[]) {
    cv::Mat image = cv::imread(argv[1], -1);
    if (image.empty()) {
        return -1;
    }

    cv::namedWindow("Example 5-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example 5-out", cv::WINDOW_AUTOSIZE);

    cv::imshow("Example 5-in", image);

    cv::Mat out;
    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);
    cv::imshow("Example 5-out", out);

    cv::waitKey(0);

    return 0;
}