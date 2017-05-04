#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		i = 100;
		iP = 55;	
	};
	
	void func(){A a; a.iP = 33; cout<<a.iP<<endl; };
	void aaa();
		
	int i;
	static A a;	
	static const int constInt = 10;
private:
	int iP;
};

A A::a;

class B
{
public:
	B()
	{
		
	};

	

	static A a;

};

A B::a;

class a201012
{
public:
	a201012()
	{
		cout<<"a201012"<<endl;	
	}	
	
};

class b201012: public a201012
{
public:
	b201012()
	{
		cout<<"b201012"<<endl;
	}
	
};

class CCC
{
public:
	int m_a;
	CCC(int a){m_a = a;}
	~CCC(){}
};

int main()
{
	b201012 bb;
	
	A b;
	cout<<b.a.a.a.a.a.a.i<<endl;

	cout<<sizeof(A)<<endl;

	cout<<B::a.a.a.a.a.i<<endl;
	cout<<B::a.constInt<<endl;
	
	A a;
	a.func();	

	CCC *pC = new CCC(100);
	
	return 0;	
}

