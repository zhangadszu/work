#include <iostream>

using namespace std;

class B
{
public:
	B(){cout<<"this is B"<<endl;};

int b;
};

class C
{
public:
	C(B &b){c = b.b; p = &(b.b); cout<<"this is C"<<endl;}
int *p;
int c;
};

class D
{
public:
	D(int v):oc(ob){ob.b=v;}

B ob;
C oc;

};


class E
{
public:
        E(int v):oc(ob){ob.b=v;}
C oc;
B ob;

};

class A
{
public:
	A(int r):b(&a){a = r;};
	~A(){};	
int *b;
int a;
};

int main()
{
	A c(46);
	cout<<c.a<<" "<<*(c.b)<<endl;

	A b(75);
	cout<<b.a<<" "<<*(b.b)<<endl;

	D d(4564);
	cout<<d.ob.b<<" "<<d.oc.c<<" "<<*(d.oc.p)<<endl;


        E e(4564);
        cout<<e.ob.b<<" "<<e.oc.c<<" "<<*(e.oc.p)<<endl;

	return 0;
}

