#include <string>
#include <iostream>

using namespace std;

int main()
{
	string a = "abcdefghijklmn";
	for(int i = 0; i < 10000; i++)
		a += "abcdefghijklmn";

	string b = a;

	cout<<"&(a[0])"<<(void *)(&(a[0]))<<endl;
	cout<<"&(b[0])"<<(void *)(&(b[0]))<<endl;
	
	a[3] = 'z';

	//cout<<"a: "<<a<<endl;
	//cout<<"b: "<<b<<endl;
	cout<<"&(a[0])"<<(void *)(&(a[0]))<<endl;
        cout<<"&(b[0])"<<(void *)(&(b[0]))<<endl;

	return 0;
}


