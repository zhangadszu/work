#include <iostream>
#include "cv_photo_quality.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

static int GetMaxGradient(uchar* gray, int width, int height, int direction)
{
    int size = width * height;
    int maxGradient = 0;
    int temp = 0;
    if((gray == NULL) || (size <= 0))
    {
        return 0;
    }

    if(direction == 0)
    {
        for(int y = 0;  y < height;  ++y)
        {
            int yTemp = y * width;
            for(int x = 0;  x < width-1;  ++x)
            {
                temp = std::abs(gray[x + yTemp] - gray[x+1 + yTemp]);
                if(temp > maxGradient)
                {
                    maxGradient = temp;
                }
            }
        }
    }
    else
    {
        for(int x = 0;  x < width;  ++x)
        {
            for(int y = 0;  y < height-1;  ++y)
            {
                temp = std::abs(gray[x + y*width] - gray[x + (y+1)*width]);
                if(temp > maxGradient)
                {
                    maxGradient = temp;
                }
            }
        }

    }
    return maxGradient;
}

static int GetMaxGradientEx(uchar* gray, int width, int height, int direction)
{
    int size = width * height;
    int maxGradient = 0;
    int temp = 0;
    if((gray == NULL) || (size <= 0))
    {
        return 0;
    }

    int count = 0;
    int hist[256] = {0};
    if(direction == 0)
    {
        for(int y = 0; y < height; ++y)
        {
            int yTemp = y * width;
            for(int x = 0; x < width-1; ++x)
            {
                temp = std::abs(gray[x + yTemp] - gray[x+1 + yTemp]);
                ++hist[temp];
                ++count;
            }
        }
    }
    else
    {
        for(int x = 0; x < width; ++x)
        {
            for(int y = 0; y < height-1; ++y)
            {
                temp = std::abs(gray[x + y*width] - gray[x + (y+1)*width]);
                ++hist[temp];
                ++count;
            }
        }

    }

    //cout<<endl<<"#######"<<endl;
    int sum1 = 0;
    int sum2 = 0;
    const float thresh = 0.001;
    const int maxValueCount = 20;
    for(int k = 255; k >= 0; --k)
    {
        sum1 += hist[k] * k;
        sum2 += hist[k];
        //cout<<k<<","<<hist[k]<<","<<count<<endl;
        if(maxValueCount <= sum2
            || ((float)sum2 / count) > thresh)
        {
            break;
        }
    }
    //cout<<endl<<"#######"<<endl;
    if(sum2 > 0)
    {
        maxGradient = (int)((float)sum1 / sum2);
    }

    return maxGradient;
}

static int GetImageGrayRange(uchar* gray, int imSize)
{
    int hist[256];
    memset(hist, 0, 256*sizeof(int));
    for(int k = 0;  k < imSize;  ++k)
    {
        hist[gray[k]] += 1;
    }

    //求和
    //int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int k = 0;

    float thresh = 0.05;

    for(k = 0;  k < 256;  ++k)
    {
        sum1 += hist[k] * k;
        sum2 += hist[k];
        if(((float)sum2 / imSize) > thresh)
        {
            break;
        }
    }
    int darkestVlaue = 0;
    if(sum2 > 0)
    {
        darkestVlaue = (int)((float)sum1 / sum2);
    }

    sum1 = 0;
    sum2 = 0;

    for(k = 255;  k >= 0;  --k)
    {
        sum1 += hist[k] * k;
        sum2 += hist[k];
        if(((float)sum2 / imSize) > thresh)
        {
            break;
        }
    }

    int whitestVlaue = 255;
    if(sum2 > 0)
    {
        whitestVlaue = (int)((float)sum1 / sum2);
    }

    int range = std::max(whitestVlaue - darkestVlaue, 0);

    return range;
}


float cv_blur_detect(const cv::Mat& input)
{
    cv::Mat img;
    cv::cvtColor(input, img, CV_RGB2GRAY);

    int maxHoriGradient = 0;
    int maxVertGraident = 0;
    if(0)
    {
        maxHoriGradient = GetMaxGradient(img.data, img.cols, img.rows, 0);
        maxVertGraident = GetMaxGradient(img.data, img.cols, img.rows, 1);
    }
    else
    {
        maxHoriGradient = GetMaxGradientEx(img.data, img.cols, img.rows, 0);
        maxVertGraident = GetMaxGradientEx(img.data, img.cols, img.rows, 1);
    }

    double gradient = std::min(maxHoriGradient, maxVertGraident);

    double range = GetImageGrayRange(img.data, img.cols * img.rows);

    //计算清晰度

    float res = std::max(0.0, std::min(gradient / range, 1.0));

    return 1.0 - res;
}
