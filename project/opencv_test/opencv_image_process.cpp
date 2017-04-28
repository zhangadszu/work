#include <iostream>
#include <map>
#include <cmath>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

//均值
template<typename T = unsigned char>
double CalMean(const Mat &mat)
{
    double sum = std::accumulate(mat.begin<T>(), mat.end<T>(), 0.0);
    return sum / mat.total(); //均值
}

int Process(Mat &mat, int factor)
{ 
    unsigned char table[256];
    for(int i = 0; i < 256; ++i)
    {
        table[i] = (unsigned char)(pow(i * 1.0 / 255, (100 - factor) / 100.0) * 255);
        //cout<<(int)table[i]<<" ";
    }
    std::for_each (mat.begin<unsigned char>(), mat.end<unsigned char>(), [&](unsigned char &v) {  
            v = table[v];  
        });

    return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 3
	    || atoi(argv[2]) > 100
	    || atoi(argv[2]) < 0)
	{
		cout<<"Usage "<<argv[0]<<" image_file factor[0-100]"<<endl;
		return 0;		
	}

	Mat org_image = imread(argv[1], CV_LOAD_IMAGE_COLOR); // 这里为矩阵开辟内存
	if(org_image.empty())
    {
        return 1;
    }

    //RGB -> HSV
    Mat hsv_image;
    cvtColor(org_image, hsv_image, CV_BGR2HSV);
    //imwrite( "hsv_image.jpg", hsv_image);

    Mat hsv[3];
    split(hsv_image, hsv);
    /*
    imwrite( "hsv_h.jpg", hsv[0]);
    imwrite( "hsv_s.jpg", hsv[1]);
    imwrite( "hsv_v.jpg", hsv[2]);
    */
    cout<<argv[1];
    cout<<" Before S_Mean "<<CalMean(hsv[1]);
//*
    int factor = atoi(argv[2]);
    Process(hsv[1], factor);

    cout<<" After S_Mean "<<CalMean(hsv[1]);

    Mat after_process_hsv_image;
    merge(hsv, 3, after_process_hsv_image);

    Mat process_image;
    cvtColor(after_process_hsv_image, process_image, CV_HSV2BGR);

    string file_name = argv[1];
    if(file_name.rfind(".") != string::npos)
    {
        file_name = file_name.substr(0, file_name.rfind("."));
        file_name += "_hsv_ss.jpg";
    }
    imwrite(file_name, process_image);
//*/
    cout<<endl;

	return 0;
}
