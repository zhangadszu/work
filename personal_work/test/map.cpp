#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map<string, string> mapStrI;
	printf("map::max_size=%u\n", mapStrI.max_size());
	map<unsigned, unsigned> mapUI;
	printf("map::max_size=%u\n", mapUI.max_size());
return 0;	
	mapStrI.insert(std::make_pair("a", "aaaa"));
	mapStrI.insert(std::make_pair("b", "bbbb"));
	mapStrI.insert(std::make_pair("a", "bbbb"));

	for(map<string, string>::iterator itMSI = mapStrI.begin(); itMSI != mapStrI.end(); itMSI++)
	{
		printf("%s -> %s\n", itMSI->first.c_str(), itMSI->second.c_str());
	}
	printf("############\n");

	typedef pair<string, string> PS;	
	vector<PS> vecPS;
	vecPS.push_back(std::make_pair("a", "bbbb"));
	vecPS.push_back(std::make_pair("c", "cccc"));
	vecPS.push_back(std::make_pair("c", "cccc"));

	mapStrI.insert(vecPS.begin(), vecPS.end());
	for(map<string, string>::iterator itMSI = mapStrI.begin(); itMSI != mapStrI.end(); itMSI++)
        {
                printf("%s -> %s\n", itMSI->first.c_str(), itMSI->second.c_str());
        }



	map<string, int> mapStr2Int;

	mapStr2Int["a"]++;
	mapStr2Int["a"]++;
	mapStr2Int["a"]++;
	mapStr2Int["b"]++;
	mapStr2Int["g"]++;

	map<string, int> mapTest;
	mapTest["a"] = 6;
	mapTest.insert(mapStr2Int.begin(), mapStr2Int.end());
	if(mapStr2Int == mapTest)
	{
		cout<<"after insert, equal..., size: "<<mapTest.size()<<endl;
	}
	
	map<string, int> mapTest2;
	mapTest2["c"]++;
	mapTest2["e"]++;
	mapTest.insert(mapTest2.begin(), mapTest2.end());
       	cout<<mapTest.size()<<endl;
	for(map<string, int>::iterator itTest = mapTest.begin(); itTest != mapTest.end(); itTest++)
	{
		cout<<itTest->first<<": "<<itTest->second<<endl;
	}	
	
	cout<<"***************"<<endl;

	cout<<mapStr2Int["c"]<<" "<<mapStr2Int["b"]<<" "<<mapStr2Int["a"]<<endl;
	return 0;

	map<int, string> mapNick;

	mapNick[100] = "aaaaaaaa";

	cout<<mapNick[100]<<endl;

	map<int, string>::iterator it = mapNick.begin();

	it->second = "bbbbbbbb";

	cout<<mapNick[100]<<endl;

	cout<<mapNick.size()<<endl;

	return 0;
}

int main_()
{
	map<string, string> mapStr2Str;

	char szA[2] = {'A', '\0'}; 
	int i;
	for(i = 0; i < 26; i++)
	{	
		mapStr2Str[szA] = szA;
		szA[0]++;
	}

	cout<<"before: "<<endl;
	i = 0;
	map<string, string>::iterator it = mapStr2Str.begin();
	while(it != mapStr2Str.end())
	{
		cout<<it->first<<": "<<it->second<<endl;
		
		i++;		
		if(i % 5 == 0)
		{
			mapStr2Str.erase(it++);
		}
		else
		{
			it++;
		}
	}

	cout<<"After: "<<endl;
        for(map<string, string>::iterator it = mapStr2Str.begin(); it != mapStr2Str.end(); it++)
        {
                cout<<it->first<<": "<<it->second<<endl;
                
        }

	return 0;

	return 0;
}


