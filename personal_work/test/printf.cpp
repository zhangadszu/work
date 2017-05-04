#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	for(unsigned int i = 0; i < 3000000000U; i += 10000000U)
	{
//		printf("./reader_clean 2 %u %u\n", i, i + 10000000 - 1);	
	}

	printf("true=%d, false=%d", true, false);
	
	bool t_f = true;
	bool f_f = false;
	bool t_t = true;
	bool f_t = false;


	t_f &= false;
	f_f &= false;
	t_t &= true;
	f_t &= true;
	printf("t_f=%d, f_f=%d, t_t=%d, f_t=%d",
			t_f, f_f, t_t, f_t);
	
	
	unsigned long long aaaa=~(0ULL);
	printf("aaaa=%llu, %lld\n", aaaa, aaaa);

	printf("%s\n", NULL);
	
	float ff = 0.0255f;
	printf("%f, %f\n", ff, 0.2);	

	printf("%s\n","ltl&#39;&quot; &quot;&#92;/&#92;");


	char bufTemp[100];
	snprintf(bufTemp, sizeof(bufTemp), "%d%%s\n", 11);
	printf("%s\n", bufTemp);

	printf(bufTemp, "");	

	printf("%%%02x\n", "&");

	char buf[100] = "this is an integer %d and a double %lf\n";
	printf(buf, 10, 10.0);
	

	unsigned int a = 100;
	long b = -101;
	unsigned long c = 102;

	printf("unsigned int[%u]\nlong[%ld]\nunsigned long[%lu]\n", a, b, c);

	printf("EAGAIN errno[%d] = %s\n", EAGAIN, strerror(EAGAIN));
	printf("EINTR errno[%d] = %s\n", EINTR, strerror(EINTR));
	printf("errno[%d] = %s\n", 11, strerror(11));
	printf("errno[%d] = %s\n", 115, strerror(115));
	printf("errno[%d] = %s\n", 22, strerror(22));
	printf("errno[%d] = %s\n", 110, strerror(110));
	printf("errno[%d] = %s\n", 111, strerror(111));

	return 0;
}
