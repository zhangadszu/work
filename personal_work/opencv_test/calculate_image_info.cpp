#include <iostream>
#include <string.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "cv_photo_quality.h"

using namespace std;
using namespace cv;

//均值
template<typename T = unsigned char>
double CalMean(const Mat &mat)
{
    double sum = std::accumulate(mat.begin<T>(), mat.end<T>(), 0.0);
    return sum / mat.total();
}

//方差
template<typename T = unsigned char>
double CalVariance(const Mat &mat)
{
    double mean = CalMean<T>(mat); //均值  
         
    double accum = 0.0;  
    std::for_each (mat.begin<T>(), mat.end<T>(), [&](const T v) {  
        accum += (v - mean) * (v - mean);  
        });  
         
    return accum / mat.total(); //方差
}

//标准差
template<typename T = unsigned char>
double CalStandardDeviation(const Mat &mat)
{
    return sqrt(CalVariance<T>(mat));
}


//信息熵
template<typename T = unsigned char>
double CalEntropy(const Mat &mat)
{
    map<T, int> mapCount;
    int totalCount = 0;
    std::for_each (mat.begin<T>(), mat.end<T>(),
        [&](const T v) {  
            ++mapCount[v / 2];
            ++totalCount;
        });

    double entropy = 0;
    std::for_each (mapCount.begin(), mapCount.end(),
        [&](const pair<T, int> &item) {
            double p = item.second * 1.0 / totalCount;
            entropy += (-p * log(p));
        });
    return entropy / log(exp(1));
}

template<typename T = unsigned char>
double CalTopMean(const Mat &mat)
{
    int count = 0;
    long sum = 0;
    for(auto it = mat.begin<T>(); it != mat.end<T>(); ++it)
    {
        if(*it > 10)
        {
            sum += *it;
            ++count;
        }
    }
    double mean = 0.0;
    if(count)
    {
        mean = sum / count;
    }
    return mean;
}

template<typename T = unsigned char>
double CalClear(const Mat &mat)
{
#if 1
    //! applies Laplacian operator to the image
    Mat laplacianMat;
    Laplacian(mat, laplacianMat, CV_16S);
    imwrite("laplacian.jpg", laplacianMat);
    //cout<<" #Laplacian# "<<laplacianMat.depth()<<" "<<laplacianMat.type()<<endl;
    
    return CalVariance<short>(laplacianMat);
    //return CalTopMean<short>(laplacianMat);
#elif 0
    Mat cannyMat;
    Canny(mat, cannyMat, 50, 100);
    imwrite("canny.jpg", cannyMat);
    //cout<<" #Canny# "<<cannyMat.depth()<<" "<<cannyMat.type()<<endl;

    return CalVariance(cannyMat);
    return CalTopMean(cannyMat);
#else
    Mat sobelMatX;
    Sobel(mat, sobelMatX, CV_16S, 1, 0, 3);
    //imwrite("sobelX.jpg", sobelMatX);
    Mat sobelMatY;
    Sobel(mat, sobelMatY, CV_16S, 0, 1, 3);
    //imwrite("sobelY.jpg", sobelMatY);

    Mat sobelMatXX;
    Mat sobelMatYY;
    multiply(sobelMatX, sobelMatX, sobelMatXX);
    multiply(sobelMatY, sobelMatY, sobelMatYY);
    Mat sobelMatXXYY;
    add(sobelMatXX, sobelMatYY, sobelMatXXYY);
    Mat sobelMatFloat;
    sobelMatXXYY.convertTo(sobelMatFloat, CV_32F);
    Mat sobelMat;
    sqrt(sobelMatFloat, sobelMat);
    //imwrite("sobel.jpg", sobelMat);
    //cout<<sobelMat<<endl;

    //return CalVariance<float>(sobelMat);
    return CalTopMean<float>(sobelMat);
 #endif
}

int main(int argc, char* argv[])
{
	if(argc != 2 )
	{
		cout<<"Usage: "<<argv[0]<<" image_file"<<endl;
		return -1;
	}
    cout<<argv[0];

	Mat source = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if (source.empty())
    {
        return -1;
    }

    //转灰度图
    Mat gray_image;
    cvtColor(source, gray_image, CV_BGR2GRAY );
    cout<<" Gray_Mean "<<CalMean(gray_image);
    cout<<" Gray_StandardDev "<<CalStandardDeviation(gray_image);
    cout<<" CalEntropy "<<CalEntropy(gray_image);
    
    //RGB -> HSV
    Mat hsv_image;
    cvtColor(source, hsv_image, CV_BGR2HSV);
    Mat hsv[3];
    split(hsv_image, hsv);
    cout<<" S_Mean "<<CalMean(hsv[1]);

    //blur
    float blur =cv_blur_detect(source);
    cout<<" Blur "<<blur;

    cout<<" Clear "<<CalClear(gray_image);
    

/*
	float noise =cv_noise_detect(source);
	printf("noise %f ",noise);
	float blur =cv_blur_detect(source);
	printf("blur %f ",blur);
	float exposure =cv_exposure_detect(source);
	printf("exposure %f ", abs(exposure));

	float score=1-0.8*blur-0.1*noise-0.1*abs(exposure);
	printf("score %f\n", score);
*/

	cout<<endl;
	return 0;
	
}
