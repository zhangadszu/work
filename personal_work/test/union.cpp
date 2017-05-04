#include <iostream>
#include <string>

using namespace std;

#define DDD(x,y) x+y

/*
union Usi
{
	string str;
	int i;
};
*/

union Usi
{
	char ch[4];
	int i;
};

struct ST
{
	Usi u;
	int a;
	//char c;

};


int main()
{
	for(int i = 0; i < 10; i++)
	{
		Usi t;
		t.i = i;
		cout<<t.i<<" "<<(int)t.ch[0]<<" "<<(int)t.ch[1]<<" "<<(int)t.ch[2]<<" "<<(int)t.ch[3]<<endl;
	}

	int i = 3;
	i += i*DDD(i,i);
	cout<<i<<endl;

	cout<<sizeof(ST)<<endl;

	return 0;
}

