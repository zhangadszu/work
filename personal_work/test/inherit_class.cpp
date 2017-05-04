#include <iostream>

using namespace std;

class BASE
{
public:
	BASE(){}
	virtual ~BASE(){cout<<"BASE::fini"<<endl;}

	void f(){g();e();}
	virtual void g(){cout<<"BASE::g"<<endl;}
	void e(){cout<<"BASE::e"<<endl;}

	void gg(){g();};
};

class child_class:public BASE
{
public:
	child_class(){}
	~child_class(){cout<<"CHILD::fini"<<endl;}

	virtual void g(){cout<<"CHILD::g"<<endl;}
        void e(){cout<<"CHILD::e"<<endl;}

};


int main()
{
	child_class c;
	c.gg();
	
	c.f();


	BASE *p = new child_class;
	delete p;

	return 0;
}

