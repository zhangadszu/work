#include <iostream>

using namespace std;

string GetCampusNick(const string &strNick)
{
    int iPos1 = strNick.find("|");  
    int iPos2 = strNick.rfind("|"); 
    return strNick.substr(iPos1+1, iPos2 - iPos1 - 1);
}

int main()
{
	char buf[] = "|«Z­||";
	
	for(unsigned i = 0; i < sizeof(buf); i++)
	{
		cout<<(int)buf[i]<<endl;
	}

	cout<<GetCampusNick(buf)<<endl;


	string str = "aaaa";
	cout<<"\""<<str.substr(4, -1)<<"\""<<endl;
	
	return 0;

}
