#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <unistd.h> 

using namespace std;

typedef struct 
{
	int a;
	char b;
}STAAA;

int test()
{
	int t = 0;
	t++;
	
	printf("test() address = %p\n", &test);

	return 0;
}

void pt()
{
	const time_t tt = time(NULL);
	printf("time=%ld\n", tt);
	sleep(1);
}

int main ()
{
	cout<<RAND_MAX<<endl;

	pt();
	pt();
	pt();
	pt();
	pt();
	
	
	//unsigned ch = 0;

	
	STAAA staaa[10];
	cout<<sizeof(staaa)<<" "<<sizeof(staaa[0])<<endl;

	string strTTT = "aaaa";
	strTTT.append("", 0);
	cout<<strTTT<<endl;
	
	int a = 2012341234;
	int b = 2043214321;
	int c = 1040123456;

	cout<<(unsigned int)(a + b)<<" "<<(unsigned int)(a + c)<<" "<<(unsigned int)(b + c)<<endl;
	cout<<(a + b)<<" "<<(a + c)<<" "<<(b + c)<<endl;	
	return 0;
	
	unsigned char bc = 0xFF;
	bool bb = true;
	memcpy(&bc, &bb, sizeof(char));
	cout<<(int)bc<<endl;
	return 0;

	string strTest = "11111111";
	string strTest2 = strTest.substr(1, 0);
	cout<<"|"<<strTest2<<"|"<<endl;
	
	cout<<strTest.find("")<<endl;;
	return 0;
	

	printf("sizeof(long long) = %ld\n", sizeof(long long));

	vector<int> vecInt;
	printf("%s\n", vecInt.begin() == vecInt.end()?"aaa":"bbb");

	char *p = NULL; 
	printf("%p\n", p);

        test();
        printf("test() address = %p\n", &test);


//	printf("%d\n", time(NULL));

	return 0;
}
