#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(const int &a, const int&b)
{
	return a>b;
}

struct ST
{
	int a;
	int b;
	
};

class COMP_ST
{
public:
	bool operator () (const ST &l, const ST &r)
	{
		return l.a < r.a;
	}
};


int main()
{

	vector<int> v;


	v.push_back(1);
	v.push_back(2);


	sort(v.begin(), v.end(), comp);

	cout<<v[0]<<" "<<v[1]<<endl;


	cout<<"#########"<<endl;
	ST s_a, s_b, s_c;
	s_a.a = 1; 
	s_a.b = 2;
	s_b.a = 2;
	s_b.b = 3;
	s_c.a = 1;
	s_c.b = 1;

	vector<ST> ss;
	ss.push_back(s_a);
	ss.push_back(s_b);
	ss.push_back(s_c);
	sort(ss.begin(), ss.end(), COMP_ST());
	for(vector<ST>::iterator it = ss.begin();
		ss.end() != it;
		++it)
	{
		cout<<it->a<<" "<<it->b<<endl;
	}	


	map<ST, int, COMP_ST> map_s;
	map_s[s_a] = 7;
	map_s[s_b] = 8;
	map_s[s_c] = 9;
	for(map<ST, int, COMP_ST>::iterator it_m = map_s.begin();
		map_s.end() != it_m;
		++it_m)
	{
		cout<<it_m->first.a<<" "<<it_m->first.b<<" "<<it_m->second<<endl;	
	}
	map<ST, int, COMP_ST>::iterator it_m = map_s.find(s_a);
	if(map_s.end() != it_m)
	{
		cout<<"find "<<it_m->first.a<<" "<<it_m->first.b<<" "<<it_m->second<<endl;
	}
	it_m = map_s.find(s_c);
    if(map_s.end() != it_m)
    {
        cout<<"find "<<it_m->first.a<<" "<<it_m->first.b<<" "<<it_m->second<<endl;
    }
	
	
	return 0;
}

