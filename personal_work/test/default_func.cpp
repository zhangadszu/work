#include <iostream>

using namespace std;


void f(int t = time(NULL))
{
	cout<<t<<endl;

}

int main()
{
	f();
	f(345);

	return 0;
}


