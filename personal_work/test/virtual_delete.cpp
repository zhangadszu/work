#include <iostream>

using namespace std;

class A
{
public:
A(){cout<<"A C"<<endl;};
virtual ~A(){cout<<"A D"<<endl;}

};

class B : public A
{
public:
B(){cout<<"B C"<<endl;};
~B(){cout<<"B D"<<endl;}

};


int main()
{
	A *pa = new B;
	delete pa;

	return 0;
}

