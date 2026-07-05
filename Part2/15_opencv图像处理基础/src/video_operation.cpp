#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
cv::VideoCapture cap("../resource/input.mp4");
double fps = cap.get(CAP_PROP_FPS);
int delay = 1000 / fps;
// 固定背景图
cv::Mat bg = cv::imread("../resource/background.jpg");

Mat frame;
cap >> frame;

cv::VideoWriter out(
    "../output/result.mp4",
    cv::VideoWriter::fourcc('m','p','4','v'),
    fps,
    frame.size()
);

cv::Mat hsv, mask, fg, dst, fg_edge, result, bg_part;

while (true) {
    cap >> frame;
    if (frame.empty()) break;

    // 1. resize背景到视频大小（非常重要）
    cv::Mat bg_resized;
    cv::resize(bg, bg_resized, frame.size());

    // 2. BGR -> HSV
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // 3. 绿幕范围
    cv::Scalar lower(45, 80, 80);
    cv::Scalar upper(75, 255, 255);

    cv::inRange(hsv, lower, upper, mask);
    //得到的是一张 二值图（单通道图）

    // 4. 反转mask（得到人物）
    cv::bitwise_not(mask, mask);

    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3,3));

    morphologyEx(mask, mask, MORPH_OPEN, kernel);   // 去除小白点
    morphologyEx(mask, mask, MORPH_CLOSE, kernel);  // 填补小黑洞

    // 5. 抠前景
    fg = Mat::zeros(frame.size(), frame.type());
    frame.copyTo(fg, mask);

    erode(mask,dst,kernel);
    subtract(mask, dst, fg_edge);

    GaussianBlur(mask, mask, Size(5,5), 0); 
for(int y = 0; y < fg.rows; y++)
{
    for(int x = 0; x < fg.cols; x++)
    {
        if(fg_edge.at<uchar>(y,x) == 0)
            continue;

        Vec3b &pixel = fg.at<Vec3b>(y,x);

        uchar B = pixel[0];
        uchar G = pixel[1];
        uchar R = pixel[2];

        if(G > R + 20 && G > B + 20)
{
    pixel[1] = (G + max(R,B))/2;
}
    }
}

    // 6. 背景去掉人物区域
    cv::Mat bg_mask;
    cv::bitwise_not(mask, bg_mask);

    bg_part = Mat::zeros(frame.size(),frame.type());
    bg_resized.copyTo(bg_part, bg_mask);

    // 7. 合成
    result = bg_part + fg;

    // 8. 写入
    out.write(result);
    imshow("result",result);
    char c = waitKey(delay);
        if (c == 27) { // 27是ESC键的ASCII码
            break;
        }
}   

cap.release();
destroyAllWindows();

    return 0;
}