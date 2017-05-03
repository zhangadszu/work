#include "cv_photo_quality.h"
#include <opencv2/imgproc/imgproc.hpp>

float cv_exposure_detect(const cv::Mat& input)
{
    float ret = 0.0f;
    cv::Rect roi_rect = cv::Rect(0, 0, input.cols, input.rows);

    if (roi_rect.x < 0) roi_rect.x = 0;
    if (roi_rect.y < 0) roi_rect.y = 0;
    if (roi_rect.x + roi_rect.width > input.cols) roi_rect.width = input.cols - roi_rect.x;
    if (roi_rect.y + roi_rect.height > input.rows) roi_rect.height = input.rows - roi_rect.y;

    cv::Mat src_img;
    //input.convertTo(src_img, CV_8UC1);
    cv::cvtColor(input(roi_rect), src_img, CV_RGB2HSV);
    std::vector<cv::Mat> tmpV;
    cv::split(src_img, tmpV);
    src_img = tmpV[2];

    const int wBinIdx = 25;
    const int bBinIdx = 5;
    const int gBins = 30;
    const int histSize[] = {gBins};
    const float gRanges[] = {0, 256};
    const float* ranges[] = {gRanges};
    const int channels[] = {0};
    cv::Mat gHist;
    cv::calcHist(&src_img, 1, channels, cv::Mat(), // do not use mask
             gHist, 1, histSize, ranges,
             true, // the histogram is uniform
             false );
    //cv::normalize(gHist, gHist, 0, 1, cv::NORM_MINMAX);

    double bWeight = 0.0;
    double wWeight = 0.0;
    double gWeight = 0.0;
    for(int i = 0;  i < gBins;  ++i)
    {
        float val = gHist.at<float>(i);
        gWeight += val;
        if(i < bBinIdx)
        {
            bWeight += val;
        }
        if(i >= wBinIdx)
        {
            wWeight += val;
        }
    }
    //double base = std::max(bWeight, wWeight);
    ret = (wWeight - bWeight) / gWeight;
    if(ret < 0)
    {
        ret = -std::sqrt(-ret);
    }
    else
    {
        ret = std::sqrt(ret);
    }
    //ret = ret * ret * ret;
    //printf("bPer = %.5f wPer = %.5f\n", bWeight / (bWeight + wWeight), wWeight / (bWeight + wWeight));

//    cv::Mat dst_img;

    return ret;
}
