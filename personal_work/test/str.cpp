#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
	char buf[4];
	
	snprintf(buf, sizeof(buf), "123456789");
	printf("%s\n", buf);

	
	strncpy(buf, "123456", sizeof(buf));
	printf("%s\n", buf);

	if(string("9") > string("8")
		 && string("8") > string("7")
		 && string("7") > string("6")
		 && string("6") > string("5")
		 && string("5") > string("4")
		 && string("4") > string("3")
		 && string("3") > string("2")
		 && string("2") > string("1")
		 && string("1") > string("0") )
		printf("good done!\n");

	return 0;
}

