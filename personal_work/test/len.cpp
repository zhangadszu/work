#include <string>
#include <iostream>

using namespace std;

int main()
{
	string a = "abc123456789";
	string b = "123456789";
	string c = b + a;


	cout<<a.rfind(b)<<" "<<a.size()<<" "<<b.size()<<endl;
	cout<<c.rfind(a)<<" "<<c.size()<<" "<<a.size()<<endl;
	

	return 0;

}


