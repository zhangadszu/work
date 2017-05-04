#include <iostream>
#include <netinet/in.h>

using namespace std;

inline float jce_ntohf(float x)
{
	union {
		float f;
		int32_t i32;
	} helper;

	helper.f = x;
	helper.i32 = htonl( helper.i32 );

	return helper.f;
}

int main()
{
	float f = 8.324f;
	float ff = jce_ntohf(f);
	float fff = jce_ntohf(ff);

	cout<<f<<"  "<<ff<<" "<<fff<<endl;
	
	return 0;
};




