#include <cctype>
#include <iostream>

using namespace std;

int main()
{
	for(int i = 0; i < 64; i++)
	{
		cout<<i<<": "<<iscntrl(i)<<" "<<(char)i<<endl;	
	}


	cout<<"|"<<char(10)<<endl;
	cout<<"|"<<char(9)<<endl;
	cout<<"|"<<char(13)<<endl;
	
}

