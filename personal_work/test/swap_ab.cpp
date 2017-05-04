#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin>>a>>b;


	if(a < 0 && b < 0)
	{
		a = a - b;
		b = a + b;
		a = b - a;  
	}
	else if(a < 0)
	{
		a = a + b;
		b = a - b;		
		a = a - b;
	}
	else if(a >0 && b > 0)
	{
		a = a - b;
                b = a + b;
                a = b - a;
	}
	else
	{
		a = a + b;
                b = a - b;
                a = a - b;
	}
	
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
		
	return 0;
}

