#include <iostream>

using namespace std;

int main()
{
	char *p = NULL;

	try
	{	
		for (int i = 0; i < 1000; i++)
		{
			p = new char[1000000000];
	
		}
	}
	catch(...)
	{
		cout<<"exception"<<endl;
	}	

	cout<<(void *)p<<" ok"<<endl;

	return 0;
}

