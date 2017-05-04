#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	for(int i = 8 * 1024 * 1024 - 100000; ; i++)
	{
		char *pBuf = new char [i];
		char szBuf[i];
		cout<<i<<endl;
		memset(szBuf, sizeof(szBuf), 1);
		delete []pBuf;
	}
		

	return 0;	
}

