#include <iostream>
using namespace std;
int a(char *&p)
{
	if(!p)
	{
		p=new char;
	}
	return 0;
}


int main()
{
   char *aa = NULL;
   a(aa);
   cout<<(void *)aa<<endl;


   return 0;
}

