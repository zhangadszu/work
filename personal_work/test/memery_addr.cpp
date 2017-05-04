#include <stdio.h>

int g_a = 0;
char g_c[16];
char g_d[16];
int g_b = 0;

int main()
{
        int a = 0;
        int b = 0;

        int *pa = new int;
        int *pb = new int;


        printf("%p %p\n", &g_a, &g_b);
        printf("%p %p\n", &g_c, &g_d);
        printf("%p %p\n", &a, &b);
        printf("%p %p\n", pa, pb);

        int *pp = new int[100];

        printf("abc");
        return 0;
}

