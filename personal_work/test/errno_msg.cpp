#include <errno.h>
#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	cout<<endl;
	for(unsigned int i = 0; i < 200; i++)
		cout<<i<<": "<<strerror(i)<<endl;
	cout<<endl;
	
	return 0;
}

