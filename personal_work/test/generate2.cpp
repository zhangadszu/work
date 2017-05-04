#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("ref.txt");
	ofstream out("out.txt");
	string str;
	
	int i = 1;
	while(in>>str)
	{
		out<<"\""<<str<<"\",\t\t// "<<i<<endl;
		i++;
	}


	return 0;	
}

