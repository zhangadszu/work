#include <iostream>
#include <vector>
using namespace std;


int main()
{
	cout<<strtoul("", NULL, 10)<<endl;


	vector<unsigned int> vA;
	vector<uint32_t> vB;

	vA.push_back(123456U);
	vB = vA;
	vA = vB;

	cout<<vB.front()<<endl;
	
	return 0;	
}

