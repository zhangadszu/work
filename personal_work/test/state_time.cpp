#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void state_range(int *pRange, int iBlog)
{
	int iIndex = iBlog / 10;
	if(iIndex < 0)
		iIndex = 0;
	if(iIndex >= 100)
		iIndex = 99;

	pRange[iIndex]++;
}

int main(int argc, char *argv[])
{	
	if(argc != 2)
	{
		cerr<<endl<<"Usage: "<<argv[0]<<" input_file"<<endl<<endl;	
		return 1;
	}	
	
	int *pRange = new int [100];
	for(int i = 0; i < 100; i++)
		pRange[i] = 0;

	
	ifstream in(argv[1]);
	

	
	int iCount = 0;
	int iTotalSum = 0;
	int iMoreThen430ms = 0;
	char buf[1024];
	while(!in.eof())
	{
		in.getline(buf, sizeof(buf) - 1);
		
		string strContent = buf;
		if(strContent.size() < 10)
			continue;

		string strDst1 = "$Total:";
		unsigned int iFind1 = strContent.find(strDst1);
		int iTotal = atoi(strContent.substr(iFind1 + strDst1.size()).c_str());

		string strDst2 = "2:";
		unsigned int iFind2 = strContent.find(strDst2, iFind1);
		int iBlog = atoi(strContent.substr(iFind2 + strDst2.size()).c_str());
		
		//cout<<iTotal<<"\t"<<iBlog<<"\t"<<iTotal - iBlog<<endl;
	
		iCount ++;
		iTotalSum += iBlog;
		if(iTotal >= 430)
			iMoreThen430ms++;
			
		state_range(pRange, iBlog);
	}

	cout<<"avg: \t"<<iTotalSum * 1.0 / iCount<<endl;
	cout<<"exceed time(%): \t"<<iMoreThen430ms * 100.0 / iCount<<endl;	
	cout<<"******************"<<endl;
	int iSum = 0;
	for(int i = 0; i < 100; i++)
		iSum += pRange[i];
	for(int i = 0; i < 100; i++)
	{
		cout<<i * 10 + 10<<"\t"<<pRange[i] * 1.0 / iSum<<endl;	
	}

	return 0;
}

