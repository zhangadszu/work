#include <iostream>
#include <ctime>
using namespace std;

char *g_a[] =
	{
		"abc",
		"123"
	};
char * g_b[] =
	{
		"abc",
		"123",
	};

void f(char *buf)
{

	cout<<(void *)buf<<endl;

}

    static unsigned int spuer_admin_array[] =
	        {4000000013UL};

int main()
{
	cout<<sizeof(spuer_admin_array)/sizeof(spuer_admin_array[0])<<endl;
	cout<<sizeof(g_a)/sizeof(g_a[0])<<endl;
	cout<<sizeof(g_b)/sizeof(g_b[0])<<endl;

	int a = time(NULL) % 100;
	char array[a];
	cout<<a<<endl;
	cout<<(void *)array<<" "<<&array<<" "<<(void *)&array[0]<<endl;
	cout<<sizeof(array)<<endl;

	f(array);
	
	return 0;
};

