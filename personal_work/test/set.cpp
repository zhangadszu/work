#include <set>
#include <iostream>

using namespace std;

typedef struct _st
{
	int a;
	int b;	
}ST;

class CMP
{
public:
	bool operator()(const ST &l, const ST &r) const
	{
		return l.a < r.a;	
	}
};


int main()
{
	ST stA;
	stA.a = 1;
	stA.b = 2;
	ST stB;
	stB.a = 2;
	stB.b = 2;
	ST stC;
	stC.a = 1;
	stC.b = 1;

	set<ST, CMP> o;
	o.insert(stA);
	o.insert(stB);
	o.insert(stC);

	cout<<o.size()<<endl;
	for(set<ST, CMP>::iterator it = o.begin(); it != o.end(); it++)
	{
		cout<<it->a<<" "<<it->b<<endl;	
	}
	
	o.erase(stC);
	cout<<o.size()<<endl;
	
	return 0;	
}

