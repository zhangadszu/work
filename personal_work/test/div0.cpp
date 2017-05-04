#include <stdio.h>
#include <exception>

int main()
{
	unsigned int uI = -1;
	printf("%u\n", uI);
	
	try
	{	
		int a = 2, b = 0;

		int c = a / b;
	}
	catch(std::exception &e)
	{
		printf(e.what());
	}
	catch(...)
	{
		printf("exception!\n");
		
	}
	

	printf("end\n");

	return 0;
}

