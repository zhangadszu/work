#include <sys/time.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const unsigned int LEN = 1024 * 1024;

	struct timeval tv1, tv2;
        gettimeofday(&tv1, NULL);
	for(int i = 0; i < 1000; ++i)
	{
		char *p = new char[LEN];
		//delete []p;
	
	}
	gettimeofday(&tv2, NULL);
	cout<<"new cost time: "<<(tv2.tv_sec - tv1.tv_sec)*1000000+tv2.tv_usec-tv1.tv_usec<<endl;

	char buf[LEN];
        gettimeofday(&tv1, NULL);
        for(int i = 0; i < 1000; ++i)
        {
		memset(buf,i, sizeof(buf));
        }
        gettimeofday(&tv2, NULL);
	cout<<"memset cost time: "<<(tv2.tv_sec - tv1.tv_sec)*1000000+tv2.tv_usec-tv1.tv_usec<<endl;

	return 0;
}


