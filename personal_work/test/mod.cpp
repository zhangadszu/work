#include <iostream>
#include <map>

using namespace std;



int main()
{

	int b = -1;
	int c = b / 10;
	cout<<c<<endl;
	return 0; 

	
	map<unsigned, map<unsigned, unsigned> > mapCount;



	const unsigned iMax = ~(0U);

	for(unsigned int i = 0; i < iMax; i++)
	{
		
		mapCount[i % 6][i / 100 % 10]++;
	
		if(i % 10000000 == 0)
			cout<<i<<endl;		
	}

	for(unsigned int j = 0; j < mapCount.size(); j++)
	{
		for(unsigned int k = 0; k < mapCount[j].size(); k++)
		{
			cout<<j<<" "<<k<<": "<<mapCount[j][k]<<endl;		
		}
	}
	

	return 0;
}


