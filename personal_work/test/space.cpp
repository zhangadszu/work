#include <iostream>
using namespace std;

int main()
{
	char *p = "¡¡";

	while(*p != '\0')
	{
		int value = *((unsigned char *)p);
		cout<<value<<endl;		
		p++;
	}	

	
	return 0;
}

