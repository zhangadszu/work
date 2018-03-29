#include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		m_a = a;
		cout<<"A CONSTRUCT! "<<m_a<<endl;
	}

	~A()
	{
		cout<<"A DIS CONSTRUCT! "<<m_a<<endl;
	}

	int m_a;
};


int main()
{	
	A *p = (A*) operator new (sizeof(A) * 2);

	new(&p[0]) A(0);
	new(&p[1]) A(1);

	p[0].~A();
	p[1].~A();

	operator delete(p);

	return 0;
}

