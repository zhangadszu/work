#include <iostream>

using namespace std;

class A
{
public:
	A(){cout<<"aaaaa"<<endl;}
	~A(){};
};

int main()
{
	A *a = new A;

	delete a;

	a = new A();
	delete a;

	return 0;
}

