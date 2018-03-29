#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(-1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(18);
	v.push_back(0);

	sort(v.begin(), v.end());
	auto itresult = unique(v.begin(), v.end());
	v.erase(itresult, v.end());
	for(auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout<<*iter<<endl;
	}	


	return 0;
}
