#include <iostream>
#include <vector>
using namespace std;

typedef struct _A
{
	string str;
	vector<string> vec;
}A;


struct BBB
{

	char a[100];
};

int main()
{
	BBB bbb;
	bbb.a[59] = 106;
	BBB bbbb;
	cout<<(int)bbbb.a[59]<<" "<<(int)bbbb.a[5]<<endl;
	bbbb = bbb;
	cout<<(int)bbbb.a[59]<<" "<<(int)bbbb.a[5]<<endl;





	A a;
	a.str = "aaaaaaaaaaa";

	A *p = &a;
	cout<<p->str<<endl;


	for(int i = 0; i < 100; i++)
		a.vec.push_back("bbbbbbbbbb");

	
	A b = a;
	b.str = "cccccccc";

	//b.str = a.str;	//test copy on write
	
	cout<<(void *)a.str.c_str()<<endl;
	cout<<(void *)b.str.c_str()<<endl;	
	
	cout<<sizeof(A)<<endl;	
	cout<<(void *)(&(a.str))<<endl;
	cout<<(void *)(&(b.str))<<endl;	
	

	a.vec.clear();
	cout<<a.vec.size()<<endl;
	cout<<b.vec.size()<<endl;
	
	
	return 0;
}

