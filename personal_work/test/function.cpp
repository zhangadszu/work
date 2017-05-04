#include <string>
#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	A(){ i = 0;};
	~A(){};

	int get()const
	{
		cout<<"*********"<<endl;
		return 1;
	}
	
	string get()
	{
		i++;
		string str;
		str = "aaa";
		cout<<"##########"<<endl;		
		return str;
	}
	
private:
	int i;
	
};


int func(const int &a, int &b)
{
	printf("a: %d, b: %d\n", a, b);
	
	b *= 2;
	
	printf("a: %d, b: %d\n", a, b);

	return 0;
}

int func1(int a, int &b)
{
	b += 9;
        printf("a: %d, b: %d\n", a, b);

        b *= 2;

        printf("a: %d, b: %d\n", a, b);

        return 0;
}

int func2(const string &a, string &b)
{
	cout<<"func2 "<<a.size()<<" "<<b.size()<<endl;
	b.clear();
	cout<<"func2 "<<a.size()<<" "<<b.size()<<endl;
}

int main()
{
	int aaa = 9;
	func(aaa, aaa);
	func1(aaa, aaa);

	A obj;

	obj.get();	

	string str = obj.get();
	cout<<str<<endl;

	const A const_obj;
	const_obj.get();
	int i = const_obj.get();
	cout<<i<<endl;

	string sss = "123";
	func2(sss, sss);

	return 0;
}

