#include <stdio.h>

int main()
{
	unsigned int a, b, d;
	printf("%d\n",
		sscanf("feedtype=111&uploadbatchid=555&aaaa=6366", 
			"feedtype=%u&uploadbatchid=%u&aaaa=%u", &a, &b, &d)); 
	printf("%u %u %u\n", a, b, d);


	
	char *pA = "FF";
	unsigned char cB = 0xFF;	
	unsigned char c = 0x00;
	unsigned char cA = 0x00;
	printf("%p:%u 	%p:%u	 %p:%u\n", &cB, cB, &c, c, &cA, cA);
	sscanf(pA, "%x", &c);
	printf("%p:%u 	%p:%u	 %p:%u\n", &cB, cB, &c, c, &cA, cA);

	return 0;
	
	char *p = "abcedegfhi10aaaa00abc";
	char buf[100];

	sscanf(p, "abcedegf%sabc", buf);

	printf("%s\n", buf);

	return 0;
}

