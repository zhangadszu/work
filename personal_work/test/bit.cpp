#include <cstdio>

using namespace std;

		struct helper
			{
				unsigned char    type : 4;
				unsigned char    tag : 4;
			}__attribute__((packed));

int main()
{
	char a = 101;

	a &= 0xFFFE;
	printf("a=%c, a=%d\n", a, a);

	helper h;
	h.type = 1;
    h.tag = 2;

    printf("%x\n", *(char *)&h);

	return 0;

}

