#include <iostream>

using namespace std;

int fc();
int fd();

const int g_c = fc();
const int g_d = fd();

int fc()
{
	cout<<g_d<<endl;
	cout<<g_c<<endl;
	
	return 6;	
}

int fd()
{
	cout<<g_d<<endl;
	cout<<g_c<<endl;

	return 7;
}



int g_a = printf("abc\n");
static int gs_a = printf("abcd\n");

int a()
{
	static int s = printf("%s\n", "test");
	static int ss;
	cout<<s<<" "<<ss<<" "<<g_a<<" "<<gs_a<<endl;
	s++;	

	return 0;
}

class CCCC
{
public:
	CCCC(){cout<<"aaaaaaaaaaaaaaaa"<<endl;};
	

	
};

int fff()
{
	static CCCC oCCCC;
	
}


int main ()
{
	cout<<g_c<<endl
		<<g_d<<endl;
	
	cout<<"begin"<<endl;
	
	for(int i = 0; i < 10; i++)
		a();

	fff();
	fff();
	
	return 0;
}


