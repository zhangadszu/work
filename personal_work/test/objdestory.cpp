#include <stdio.h>
#include <string.h>
class A {
public:
	A(char * szstr){ 
		printf("%s\n", szstr); 
		strncpy(buf, szstr, sizeof(buf));
	}
	~A(){ printf("%s destory\n", buf);}
private:
	char buf[128];
};


int main()
{
	A a("a");
	A b("b");

	printf("###################");
	printf("###################");
	printf("###################");
	printf("###################");
	printf("###################");

	return 0;
}
