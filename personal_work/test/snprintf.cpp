#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char buf[5];

	snprintf(buf, sizeof(buf), "abcdefg");
	cout<<buf<<endl;

	return 0;
}
