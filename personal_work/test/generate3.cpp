#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	for(unsigned int i = 100000000U; i < 4000000000U; i += 50000000U)
	{
		cout<<"./get_upp_uin "<<i<<" "<<i + 50000000U<<endl;
	}
	

	return 0;	
}

