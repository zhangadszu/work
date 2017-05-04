#include <iostream>
#include <map>
using namespace std;

typedef enum _E
{
	A = 1,
	B,
	C
}E;

enum SSSSS
{
	sa,
	sb,
	sc

};

int main()
{
	
	E ee = (E)2;
	
	if(ee == B)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	map<E,int> mapE;
	mapE[A] = 1;
	cout<<mapE.size()<<" "<<mapE[A];

	int aaaa = sc;
	cout<<endl<<aaaa<<endl;
	cout<<sa<<sb<<sc<<endl;
	
	return 0;
}


