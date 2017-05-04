#include <iostream>
#include <typeinfo>

using namespace std;

class BASE
{
public:
	BASE(){};
	virtual ~BASE(){};

public:
	int aa;
};

template<typename A = float>
class CA : public BASE
{
public:
	CA(A a){cout<<"constructor"<<endl; m_a = a;}
	~CA(){cout<<"disconstructor"<<endl;};

	static void func()
	{
		cout<<"here i am "<<endl;
	}

	void fa()
	{
		cout<<"I am "<<m_a<<endl;
	}
private:

	A m_a;

};

void fff()
{
	cout<<"test"<<endl;
}

int main()
{
	CA<int>  a(1);
	CA<int>  b(1555);
	CA<double> d(5545.66);
	CA<> off(0.22);

	off.fa();

	a.func();
	b.func();

	cout<<typeid(a).name()<<endl;
	cout<<typeid(b).name()<<endl;
	cout<<typeid(off).name()<<endl;
	cout<<typeid(CA<double>).name()<<endl;
	cout<<typeid(BASE).name()<<endl;
	cout<<typeid(char *).name()<<endl;
	cout<<typeid(CA<double> *).name()<<endl;


	cout<<(void *)&(a.func)<<endl;
	cout<<(void *)&(b.func)<<endl;

	cout<<(void *)&(d.func)<<endl;
	cout<<(void *)&(CA<double>::func)<<endl;


	cout<<(void *)&fff<<endl;

	return 0;
}


