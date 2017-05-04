#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;


void p(int i)
{
	cout<<i<<" ";
}

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	
    cout<<"start: ";
    for_each(a.begin(), a.end(), &p);
    cout<<endl;
	
	while(next_permutation(a.begin(), a.end()))
	{
		cout<<"a: ";
		for_each(a.begin(), a.end(), &p);
		cout<<endl;
	
	}

    cout<<"finish: ";
    for_each(a.begin(), a.end(), &p);
    cout<<endl;
	
	return 0;
}

