#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char *p = strtok(NULL, "ABC");

	cout<<"Not Core!"<<endl;
	cout<<"Point p = "<<(void *)p<<endl;

	return 0;
}


