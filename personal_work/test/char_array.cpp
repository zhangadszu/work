#include <iostream>

using namespace std;

int main()
{
	string str06="abc";
	char *p06 = (char *)str06.data();
	int pp06 = *p06;
	cout<<pp06<<endl;


	char p[10];
	void *pp = &p;
	cout<<(void *)p<<endl;
        cout<<(void *)pp<<endl;	
       // cout<<(void *)pppp<<endl;	
	
	//p++;

	char *pa = new char;
	char **ppa = &pa;
	char * (&pra) = pa;	
	
	cout<<(void*)pa<<endl;
	cout<<(void*)ppa<<endl;
	cout<<(void*)pra<<endl;


	auto i = (void *)pa;
//	(char *)((void *)i) = 'a';
//	cout<<(char)
	
	cout<<i<<endl;
	cout<<(void *)i<<endl;	

#if 0
	int b = time(NULL);
	char a[b/1000000];
	int c[b/1000000];

	cout<<sizeof(a)<<" "<<sizeof(c)<<endl;
#endif

	return 0;
}

