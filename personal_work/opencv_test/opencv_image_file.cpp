#include <iostream>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

//方差
template<typename T = unsigned char>
double CalVariance(const Mat &mat)
{
    double sum = std::accumulate(mat.begin<T>(), mat.end<T>(), 0.0);
    double mean = sum / mat.total(); //均值  
         
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

//均值
template<typename T = unsigned char>
double CalMean(const Mat &mat)
{
    double sum = std::accumulate(mat.begin<T>(), mat.end<T>(), 0.0);
    return sum / mat.total(); //均值
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

//布局指数
double CalLayout(const Mat &mat)
{
    double score = 0;
    //计算内容主体布局
    const int rowBlock = 5;
    const int colBlock = 5;
    /*
    int weight[rowBlock][colBlock] = {
        {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
        {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
        {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
        {-2, 0, 0, 3, 3, 3, 3, 0, 0, -2},
        {-2, 0, 0, 3, 4, 4, 3, 0, 0, -2},
        {-2, 0, 0, 3, 4, 4, 3, 0, 0, -2},
        {-2, 0, 0, 3, 3, 3, 3, 0, 0, -2},
        {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
        {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
        {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2}};
    */
     int weight[rowBlock][colBlock] = {
        {-2, -1, 0, -1, -2},
        {-1, 0, 2, 0, -1},
        {0, 2, 5, 2, 0},
        {-1, 0, 2, 0, -1},
        {-2, -1, 0, -1, -2}};
    double totalV = CalStandardDeviation(mat);
    if(totalV == 0.0)
    {
        totalV = 1.0;
    }
    //cout<<endl;
    if(mat.rows >= rowBlock && mat.cols >= colBlock)
    {
        int rowStep = mat.rows / rowBlock;
        int colStep = mat.cols / colBlock;
        for(int i = 0; i < rowBlock; ++i)
        {
            for(int j = 0; j < colBlock; ++j)
            {
                double s = CalStandardDeviation(Mat(mat, Range(i * rowStep, (i + 1) * rowStep), Range(j * colStep, (j + 1) * colStep)));
                score += (s * weight[i][j]);
                //cout<<s / totalV<<" ";
            }
            //cout<<endl;
        }

        score /= totalV;
    }

    return score;
}

template<typename T = unsigned char>
double CalHFR(const Mat &mat)
{
    if(mat.empty())
    {
        return 0.0;
    }

    T max = *(max_element(mat.begin<T>(), mat.end<T>()));
    int count = std::count_if(mat.begin<T>(), mat.end<T>(), bind2nd(greater_equal<T>(), max * 0.5));
    cout<<"max "<<max<<" count "<<count<<endl;
    return count * 1.0 / mat.total(); //均值
}

int dftTest(const Mat &I)
{
    //cout<<I<<endl;
    //cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;

    Mat padded;                            //expand input image to optimal size
    int m = getOptimalDFTSize( I.rows );
    int n = getOptimalDFTSize( I.cols ); // on the border add zero values
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

    

    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

/*
    Mat part[2];
    split(complexI, part);
    imwrite( "orig_dft_image.jpg", part[0]);
*/
    dft(complexI, complexI);            // this way the result may fit in the source matrix

    //cout<<complexI<<endl;
    //cout<<"***********************"<<endl;

    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))

    //cout<<planes[0]<<endl;
    //cout<<"#################"<<endl;
    //cout<<planes[1]<<endl;
    //cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;

    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude  
    Mat magI = planes[0];
/*
    cout<<"O mean: "<<CalMean<float>(magI)
        <<" stdde: "<<CalStandardDeviation<float>(magI)
        <<" HFR: "<<CalHFR<float>(magI)<<endl;
*/
    //cout<<magI<<endl;
    //cout<<"@@@@@@@@@@@@@"<<endl;
    
    magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);
    cout<<"Log mean: "<<CalMean<float>(magI)
        <<" stdde: "<<CalStandardDeviation<float>(magI)
        <<" HFR: "<<CalHFR<float>(magI)<<endl;
    //cout<<magI<<endl;
   // cout<<"1111111111111111111111111111111"<<endl;

    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center        
    int cx = magI.cols/2;
    int cy = magI.rows/2;

    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant 
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);


    normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a 
                                            // viewable image form (float between values 0 and 1).


    //cout<<magI<<endl;
    //cout<<"2222222222222222222222222"<<endl;

                                            
    Mat dftImag;
    magI.convertTo(dftImag, CV_8U, 255.0);

    //cout<<dftImag<<endl;
    //cout<<"33333333333333333"<<endl;

    imwrite( "dft_image.jpg", dftImag );
    
    return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"Usage "<<argv[0]<<" image_file"<<endl;
		return 0;		
	}

    cout<<argv[1];
	Mat org_image = imread(argv[1], CV_LOAD_IMAGE_COLOR); // 这里为矩阵开辟内存

//    cout<<org_image.elemSize()<<" "<<org_image.total()<<endl;
/*
    Mat org_rgb[3];
    split(org_image, org_rgb);
    imwrite( "org_b.jpg", org_rgb[0]);
    imwrite( "org_g.jpg", org_rgb[1]);
    imwrite( "org_r.jpg", org_rgb[2]);
    return 0;
*/

    //转灰度图
    Mat gray_image;
    cvtColor( org_image, gray_image, CV_BGR2GRAY );
    imwrite( "gray_image.jpg", gray_image );

    cout<<" CalEntropy "<<CalEntropy(gray_image);


    //RGB -> HLS
    Mat hls_image;
    cvtColor(org_image, hls_image, CV_BGR2HLS);
    //imwrite( "hsv_image.jpg", hls_image);
    //统计HLS 亮度标准差
    Mat hls[3];
    split(hls_image, hls);

    //cout<<hls[1].elemSize()<<" "<<hls[1].total()<<endl;
    cout<<" StandardDeviation "<<CalStandardDeviation(hls[1]);
    /*
    imwrite( "hls_h.jpg", hls[0]);
    imwrite( "hls_l.jpg", hls[1]);
    imwrite( "hls_s.jpg", hls[2]);
    */
    cout<<" L_Mean "<<CalMean(hls[1]);


    //滤波
    Mat kern = (Mat_<char>(5,5) << -1, -1, -1, -1, -1,
                             -1, -1, -1, -1, -1,
                             -1, -1, 24, -1, -1,
                             -1, -1, -1, -1, -1,
                             -1, -1, -1, -1, -1);
    Mat after_filter_image;          
    filter2D(gray_image, after_filter_image, gray_image.depth(), kern);
    imwrite( "after_filter_image.jpg", after_filter_image );
    //cout<<after_filter_image.elemSize()<<" "<<after_filter_image.total()<<endl;
    //cout<<after_filter_image;
    cout<<" layout "<<CalLayout(after_filter_image);


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
    //cout<<" "<<hsv[1].elemSize()<<" "<<hsv[1].total()<<endl;
    cout<<" S_Mean "<<CalMean(hsv[1]);

    cout<<endl;

    //dft test
    Mat I = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    dftTest(I);

/*
    cout<<" entropy org_image:"<<CalEntropy(org_image)
        <<" gray_image:"<<CalEntropy(gray_image)
        <<" after_filter_image:"<<CalEntropy(after_filter_image)
        <<" hls[1]:"<<CalEntropy(hls[1])
        <<" hsv[1]:"<<CalEntropy(hsv[1])
        <<endl;
*/
/*
    cout<<org_image.channels()<<" "<<org_image.type()<<" "<<org_image.depth()<<endl
        <<" "<<gray_image.channels()<<" "<<gray_image.type()<<" "<<gray_image.depth()<<endl
        <<" "<<after_filter_image.channels()<<" "<<after_filter_image.type()<<" "<<after_filter_image.depth()<<endl
        <<" "<<hsv_image.channels()<<" "<<hsv_image.type()<<" "<<hsv_image.depth()<<endl;
*/
	return 0;
}
