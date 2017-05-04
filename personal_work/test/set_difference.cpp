#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int ReadUinFromFile(const char *szFile, set<unsigned int> &setUin)
{
	ifstream in(szFile);
	if(!in.good())
	{
		cerr<<"Open input file error, please check!"<<endl;
		return 2;
	}

	unsigned int iUin;
	char buf[128] = {0};
	while(!in.eof())	
	{
		in.getline(buf, 127);
		if(sscanf(buf, "%u",  &iUin) != 1)
		{
			continue;
		}
		
		setUin.insert(iUin);
	}

	in.close();
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		cerr<<endl<<"\tUsage: "<<argv[0]<<" uin_a_file uin_b_file uin_result_file"<<endl<<endl;
		return 1;	
	}
	
	set<unsigned int> setA, setB;
	ReadUinFromFile(argv[1], setA);
	ReadUinFromFile(argv[2], setB);

	vector<unsigned int> vecResult;
	std:: set_difference(setA.begin(), setA.end(),
		setB.begin(), setB.end(),
		inserter(vecResult, vecResult.end()));
	
	ofstream out(argv[3]);
	for(vector<unsigned int>::iterator it = vecResult.begin(); it != vecResult.end(); it++)
	{
		out<<*it<<endl;	
	}

	return 0;
}

