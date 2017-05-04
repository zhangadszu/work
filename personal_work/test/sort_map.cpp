#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

void API_StringToLower(string &str)
{
	for(string::iterator it = str.begin(); it != str.end(); it++)
	{
		*it = tolower(*it);
	}

}

int main()
{	
	ifstream in1("d2c.txt");
	ifstream in2("d2m.txt"); 
	
	map<string,string> map_d2m;
	string s1,s2;
	while(in2>>s1>>s2)
	{
		map_d2m[s2] = s1;
		//cout<<s1<<" "<<s2<<endl;
	}

	map<string, unsigned int> map_m2c;
	while(in1>>s1>>s2)
        {
		cout<<s1<<" "<<s2<<endl;
		API_StringToLower(s1);
		if(map_d2m.find(s1) != map_d2m.end())
		{
			string tmp = map_d2m[s1];
			map_m2c[tmp] += atoi(s2.c_str());
			cout<<s1<<" "<<map_d2m[s1]<<" "<<map_m2c[tmp]<<endl;
		}
		else
		{

			map_m2c["UNKNOW"] += atoi(s2.c_str());
		}

	}
       

	for(map<string, unsigned int>::iterator it = map_m2c.begin();
		it != map_m2c.end();
		++it)
	{

		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;
}

