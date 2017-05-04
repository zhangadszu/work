#include <stdio.h>
#include <string.h>

int main()
{
	char szA[1024] = "123456";
	char szB[1024] = "789";
	
	strncpy(szA, "abc", strlen("abc") + 1);

	printf("\n\n\t|%s|\n\n", szA);
	



	
	return 0;
}

