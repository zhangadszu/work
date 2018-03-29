#include <iostream>
#include <sys/time.h>

using namespace std;

long long Now_Microsecond()
{
      struct timespec tp;
      clock_gettime(CLOCK_REALTIME, &tp);
      return ((long long)tp.tv_sec)*1000000 + tp.tv_nsec/1000;
}
int main()
{
	for(int i = 0; i < 100; ++i)
	{
		cout<<Now_Microsecond()<<endl;
	}

	return 0;
}

