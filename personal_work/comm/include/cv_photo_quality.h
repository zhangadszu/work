#ifndef __CV_PHOTO_QUALITY
#define __CV_PHOTO_QUALITY

#include <opencv2/core/core.hpp>
//#include "photo_quality_export.h"
#define PHOTO_QUALITY_EXPORT

//检测图片的噪声，返回值范围为[0, 1]， 建议阈值为0.5附近
// input RGB
PHOTO_QUALITY_EXPORT float cv_noise_detect(const cv::Mat& input);

//检测图片的模糊程度，返回值范围为[0, 1]，建议阈值为0.6~0.7
// input RGB
PHOTO_QUALITY_EXPORT float cv_blur_detect(const cv::Mat& input);

//检测图片的曝光度，返回范围为[-1, 1]，-1为全黑，1为全白
// input RGB
PHOTO_QUALITY_EXPORT float cv_exposure_detect(const cv::Mat& input);

#endif
