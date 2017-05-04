#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i = 0;
	vector<int> vectInt;
	vectInt.reserve(5);
	

	try
	{	
		while(true)
		{
			vectInt[i] = 0;
			cout<<i<<endl;
			i++;	
		}
	}
	catch(...)
	{
		cout<<i<<endl;
	}	

	cout<<"Done!"<<endl;

	return 0;
}

