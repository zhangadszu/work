#include <iostream>

using namespace std;

struct Node
{
	char a;
	short b;
};

struct list
{
	Node *pa;
	char *pb;
};

static list l;

int main()
{
	cout<<(void *)l.pa<<endl;
	
	return 0;
}

