#include <iostream>

using namespace std;

int main()
{
	char *p = new char [10];

	cout<<(void *)p<<endl;
	cout<<(void *)(&p)<<endl;

	return 0;
}


