#include "cv_photo_quality.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <cstdio>

float cv_noise_detect(const cv::Mat& input)
{
    cv::Mat src_img;
    input.convertTo(src_img, CV_8UC3);

    cv::Mat dst_img;
    cv::medianBlur(src_img, dst_img, 3);

    const int rows = dst_img.rows;
    const int cols = dst_img.cols;
    double mse = 0.0;
    for(int y = 0;  y < rows;  ++y)
    {
        for(int x = 0;  x < cols;  ++x)
        {
            float diff_val1 = src_img.data[y*cols + 3*x+0] - dst_img.data[y*cols + 3*x+0];
            float diff_val2 = src_img.data[y*cols + 3*x+1] - dst_img.data[y*cols + 3*x+1];
            float diff_val3 = src_img.data[y*cols + 3*x+2] - dst_img.data[y*cols + 3*x+2];
            mse += diff_val1 * diff_val1 + diff_val2 * diff_val2 + diff_val3 * diff_val3;
        }
    }
    mse /= cols * rows * 3;
    double psnr = 10 * log10((255*255) / mse);
    //printf("mse = %.3f, psnr = %.3f\n", mse, psnr);

    float ret = 0.0;
    if(psnr < 30)
    {
        ret = 30 - psnr;
    }
    else if(psnr > 40)
    {
        ret = psnr - 40;
    }
    if(ret > 30)
    {
        ret = 30;
    }
    ret /= 30.0f;
    ret = std::sqrt(ret);
    ret = std::sqrt(ret);
    return ret;
}
