#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	time_t tt = atoll("4005671296");
	cout<<tt<<" "<<atoi("4005671296")<<endl;

	
	cout<<atoi("455;")<<endl;

	ifstream in(argv[1]);

	map<unsigned int, unsigned int> mapUin;
	string str;
	while(in>>str)
	{
		unsigned int i = str.find("uin[");
		unsigned int j = str.find("]", i);
	
		if(i == string::npos
			|| j == string::npos)
		{
			continue;	
		}
		
		unsigned int iUin = atoi(str.substr(i + 4, j - i - 4).c_str());
		
		mapUin[iUin]++;
	}

	for(map<unsigned int, unsigned int>::iterator it = mapUin.begin(); it != mapUin.end(); it++)
	{
		if(it->second > 10)
		{
			cout<<it->first<<endl;	
		}
	
	}


	return 0;
};
