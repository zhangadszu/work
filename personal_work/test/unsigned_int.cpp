#include <iostream>

using namespace std;

int main()
{
	unsigned int a = 2500000000U;
	if(a > 10000)
	{
		cout<<"OK"<<endl;	
	}

	unsigned int i = ~(0U);

	cout<<i<<endl;

	i++;
	cout<<i<<endl;
	
	i = ~(0U);
	cout<<i<<endl;
	unsigned int j = i + 4294967000U;
	cout<<j<<endl;



	i = ~(0U);
	cout<<"aaa"<<i<<((i>100)?"yes":"no")<<endl;
	i += 1;
	cout<<i<<endl;
	
	i = 100;
	int b = i - 101;
	cout<<a<<endl;


	

	return 0;	
}

