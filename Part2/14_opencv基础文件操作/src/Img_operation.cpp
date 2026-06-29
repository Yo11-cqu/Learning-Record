#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    Mat colorImg = imread("../images/木野日鞠.jpg");

    if (colorImg.empty()) {
        cout << "无法读取图像文件" << endl;
        return -1;
    }

        // 创建窗口并显示图像
    namedWindow("图片展示", WINDOW_NORMAL); 
    imshow("图片展示", colorImg);
    
    waitKey(0);

    destroyAllWindows();

    
    bool pngSuccess = imwrite("../img_outputs/converted_image.png", colorImg, {IMWRITE_PNG_COMPRESSION, 3});
    
    if (pngSuccess) {
        cout << "图像保存成功" << endl;
    } else {
        cout << "图像保存失败" << endl;
    }

    return 0;
}