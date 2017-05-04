#include <iostream>

using namespace std;

class A
{
public:

	A();

private:
	static const int a = 102;
	
};

A::A()
{
	cout<<a<<endl;	
	
}

//A obj;


int main()
{
	cout<<0xFF<<endl;
	
	unsigned int a = 4000000000U;

	int b = a;
	cout<<a<<endl;
	cout<<b<<endl;
	a = b;
	cout<<a<<endl;
	
	a++;
	b = a;
	cout<<a<<endl;
	cout<<b<<endl;
	b--;
	a = b;
	cout<<a<<endl;

	
	return 0;	
}

