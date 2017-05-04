#include <iostream>

using namespace std;

int main()
{
	int a, b;
	string str;

	double d = 0.0;
	double t = 0.0;
	while(cin>>a>>b>>str)
	{
		d += a / 10000 * b;
		t += b;
		
	}

	cout<<d/t<<endl;
	
	return 0;
}

