#include<ctime>
#include<iostream>

using namespace std;

int main()
{
	cout<<sizeof("abcdefg")<<endl;
	
	cout<<sizeof(long)<<endl;
	cout<<sizeof(long long)<<endl;
	
	char as[4] = "abk";
	char as2[4]= "129";
	cout<<as<<" "<<as2<<endl;


	int iSize = time(NULL) % 1000;
	char carr[iSize];
	cout<<iSize<<" "<<sizeof(carr)<<endl;

	int a;
	char b[1000];
	char *c = new char [100];

	cout<<"sizeof(a)"<<sizeof(a)<<endl;
	cout<<"sizeof(b)"<<sizeof(b)<<endl;
	cout<<"sizeof(c)"<<sizeof(c)<<endl;

	cout<<"sizeof(long)"<<sizeof(long)<<endl;
	cout<<"sizeof(long long)"<<sizeof(long long)<<endl;


	const char *ccc[] = {"aaaa", "bbbbbbbbb", "ccccccccc"};
	cout<<"sizeof(ccc):"<<sizeof(ccc)<<endl;
	
	return 0;
}

