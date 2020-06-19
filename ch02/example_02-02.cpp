#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    Mat img = imread(argv[1], -1);
    if (img.empty()) {
        printf("image read error!\n");
        return -1;
    }
    namedWindow("Example 2", WINDOW_AUTOSIZE);
    imshow("Example 2", img);
    waitKey(0);
    destroyWindow("Example 2");

    return 0;
}