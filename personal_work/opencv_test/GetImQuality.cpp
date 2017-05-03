#include <stdio.h>
#include <string.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "cv_photo_quality.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat source;
	if(argc != 2 )
	{
		printf("bin imgfile");
		return -1;
	}
	source = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	printf("%s ", argv[1]);
	float noise =cv_noise_detect(source);
	printf("noise %f ",noise);
	float blur =cv_blur_detect(source);
	printf("blur %f ",blur);
	float exposure =cv_exposure_detect(source);
	printf("exposure %f ", abs(exposure));

	float score=1-0.8*blur-0.1*noise-0.1*abs(exposure);
	printf("score %f\n", score);

	return 0;
	
}
