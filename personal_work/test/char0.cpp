#include <string.h>
#include <iostream>
using namespace std;

typedef struct{
	int a;
	char c[0];
	char b[100];
}st;

int main()
{
	cout<<"size: "<<sizeof(st)<<endl;
	
	char array[] = "abcdefghijklmn";

	
	st o;
	cout<<(void *)&o<<endl;
	cout<<(void *)o.c<<endl;

	memcpy(&o, array, sizeof(st));
	
	cout<<(void *)array<<endl;
	cout<<(void *)o.c<<endl;

	cout<<o.c<<endl;

	return 0;
}


