#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;


void p(int i)
{
	cout<<i<<endl;
}

int main()
{
	vector<int> aaa;
	vector<int> bbb;
	bbb.push_back(1);
	bbb.push_back(2);

	bbb.insert(bbb.end(), aaa.begin(), aaa.end());

	for_each(bbb.begin(), bbb.end(), p);	
	

	return 0;
}

