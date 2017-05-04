#include<iostream>

using namespace std;

int main()
{
	for(int i = 2000000; ; i += 10240)
	{
		char a[i];
		a[i-1] = 0;
		
		cout<<i<<endl;	
	}


	return 0;	
}

