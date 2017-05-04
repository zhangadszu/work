#include <string.h>
#include <stdio.h>

int main()
{
	char a[10] = {1,2,0,4};
	char b[10] = {1,2,0,5};

	printf("%d\n", strncmp(a, b, 9));
	return 0;


}

