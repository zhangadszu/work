#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	const string strSplit(1, 0x01);

	std::ostringstream oss;

	oss<<strSplit<<strSplit<<endl;


	cout<<oss.str().size()<<endl;
	cout<<oss.str()<<endl;
	cout<<(int)oss.str()[0]<<endl;



	return 0;	
}

