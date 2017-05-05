#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

/**
* @function main
*/
int main(int argc, char *argv[])
{
    if(argc != 2)
	{
		cout<<"Usage "<<argv[0]<<" image_file"<<endl;
		return 0;		
	}

    //![variables]
    Mat src, src_gray;
    Mat grad;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    //![variables]

    //![load]
    src = imread(argv[1], IMREAD_COLOR); // Load an image

    if (src.empty())
    {
        return -1;
    }
    //![load]

    //![reduce_noise]
    //GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    //![reduce_noise]

    //![convert_to_gray]
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    //![convert_to_gray]

    //![sobel]
    /// Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    /// Gradient X
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);

    /// Gradient Y
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
    //![sobel]

    //![convert]
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    //![convert]

    //![blend]
    /// Total Gradient (approximate)
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    //![blend]

    string file_name = argv[1];
    if(file_name.rfind(".") != string::npos)
    {
        file_name = file_name.substr(0, file_name.rfind("."));
        file_name += "_sobel.jpg";
    }
    imwrite(file_name, grad);

    return 0;
}