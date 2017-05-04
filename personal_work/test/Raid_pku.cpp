#include <iostream>

using namespace std;

typedef struct 
{
	int x, y;
}Point;

int main()
{
	Point sta[100001];
	Point ag[100001];
	int n;
	
	while(cin>>n)
	{
		int i = 0;
		for(i = 0; i < n; i++)
			cin>>sta[i].x>>sta[i].y;
		for(i = 0; i < n; i++)
			cin>>ag[i].x>>ag[i].y;

	

	}

	return 0;
}

