#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{

    VideoCapture cap("../videos/视频素材.mp4");
    
    if (!cap.isOpened()) {
        cout << "视频无法打开" << endl;
        return -1;
    }

    int frameWidth = cap.get(CAP_PROP_FRAME_WIDTH);    
    int frameHeight = cap.get(CAP_PROP_FRAME_HEIGHT);  
    double fps = cap.get(CAP_PROP_FPS);                
    
    int delay = 1000 / fps;
    Mat frame;

    int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');
    VideoWriter out("../video_outputs/video_30frames.mp4", fourcc, fps, Size(frameWidth, frameHeight));
    
    if (!out.isOpened()) {
        cout << "无法创建输出视频文件" << endl;
        return -1;
    }
    int i = 0;
    while (true) {
        cap.read(frame);
        
        if (frame.empty()) {
            break;
        }
        
        imshow("视频播放", frame);

        char c = waitKey(delay);
        if (c == 113) { 
            break;
        }

        if (c==32){
            while(1){
                char c1 = waitKey(0);
                if (c1 == 32){
                    break;
                }
            }
        }
    
        if( i < 30){
            out.write(frame);
            i++;
        }
    }

    cap.release();
    out.release();
    destroyAllWindows();
    
    return 0;

} 