#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	A() {};
	int a;
	int b;
	int c;

};

int main()
{
	A a;
	a.a = 1;
	A b;
	b.a = 2;
	vector<A> v;
	v.push_back(a);
	v.push_back(b);

	A *pp = &(v[1]);
	A *p = &v[1];

	cout<<(void *)pp<<" "<<pp->a<<endl;
	cout<<(void *)p<<" "<<p->a<<endl;

	cout<<&v[0]<<endl;
	cout<<&(v[0])<<endl;
	
	return 0;
}

