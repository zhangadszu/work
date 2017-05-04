#include <iostream>

using namespace std;

class A
{
public:
	A(){ index = ++count; cout<<"constructor: "<<index<<endl;}
	~A(){cout<<"desconstructor: "<<index<<endl;}

private:
	int index;
	static int count;
};

class B
{
public:
        B(){ index = ++count; cout<<"constructor: "<<index<<endl;}
        virtual ~B(){cout<<"desconstructor: "<<index<<endl;}

private:
        int index;
        static int count;
};

class C
{
public:
        C(){ index = ++count; cout<<"constructor: "<<index<<endl;}
        virtual ~C(){cout<<"desconstructor: "<<index<<endl;}

	virtual int get(){return index;}
private:
        int index;
        static int count;
};

int C::count = 0;
int B::count = 0;
int A::count = 0;

int main()
{
	cout<<sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C)<<endl;

	A *a = new A[5];
	int *d = (int *)a - 1;
	cout<<(void *)d<<" "<<*d<<" "<<(void *)a<<endl;
//	delete a;
	delete []a;

	A *b = new A[13];
	int *c = (int *)b - 1;
	cout<<*c<<" "<<(void *)b<<endl;
	delete []b;

	return 0;
}

