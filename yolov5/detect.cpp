# include"yolov5.h"
# include<string>

using namespace cv;
using namespace std;

// openvino、yolov5、cpu、onnx；

int main(int argc, char const *argv[]) {
    try{
        Config config = {0.4,0.4,0.4,640,640,"../model/yolov5n.onnx"};  
        YOLOV5 yolomodel(config);
        clock_t start, end;
        // cv::Mat img=cv::imread(input_image_path);
        VideoCapture cap(0);
        Mat img;
        while(true){
            cap >> img;
            
            // Resize the image to 0.5
            // cv::resize(img, img, cv::Size(), 0.5, 0.5);
    
            yolomodel.detect(img);
          
            imshow("result", img);
            waitKey(1);
        }
    }catch (const std::exception& ex){
        std::cerr << ex.what()<<std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


