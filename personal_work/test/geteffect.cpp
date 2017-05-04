#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("record.log");
	
	
	while(!in.eof() && in.good())
	{
		char buf[1024];
		in.getline(buf, 1023);
		
		char *p = strstr(buf, "effect");
		if(p == NULL)
			continue;		

		p += strlen("effect");
		
		int effect = atoi(p);
		
		if(effect & (1<<24))
		{
			cout<<buf<<endl;
		}

	}
}

