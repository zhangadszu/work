#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	string str;
	
	int i = 0;
	while(in>>str)
	{
		out<<"IP_"<<i<<"="<<str<<endl;	
		out<<"PORT_"<<i<<"=12350"<<endl;
		i++;
	}


	return 0;	
}

