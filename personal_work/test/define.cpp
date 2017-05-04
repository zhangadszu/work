#include <iostream>
using namespace std;

#define A "AAAAAAAA"
#define B A       "BBBBBBBB"

#define C "123456"
#define C "abcdefg"
#define C "ABCDEFG"


int main()
{
	cout<<B<<endl;
	cout<<C<<endl;
	
#define C "XZY"
	cout<<C<<endl;
	
	return 0;
}

