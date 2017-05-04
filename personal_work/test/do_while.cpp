#include <iostream>
using namespace std;

int main()
{
	int iRunTimes = 10;
	do
	{
		if(iRunTimes % 2 == 0)
		{
			cout<<"aa "<<iRunTimes<<endl;	
			continue;
		}
		
		cout<<"bb "<<iRunTimes<<endl;	
	}while(--iRunTimes);


	int t = 0;
	do
	{
		cout<<"$$$$"<<endl;
	}while((t++) < 1);

	
	return 0;
}

