#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for(unsigned u = 323420423U; u < 323420500; ++u)
	{
		long long ll = (long long)u * (long long)u;
		unsigned ru = ll;
 	        cout<<ll<<" "<<ru<<endl;
	}


	cout<<(0x1ULL<<63)<<endl;	

	unsigned long long ul = (0x1ULL<<63);
	cout<<ul<<endl;

	cout<<pow(2.0, 63.0)<<endl;

	cout<<pow(2.0, 31.0)<<endl;

	return 0;
}

