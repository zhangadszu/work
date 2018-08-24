#include <vector>
#include <iostream>
using namespace std;
int a(char *&p)
{
	if(!p)
	{
		p=new char;
	}
	return 0;
}

vector<int> &GetRef(vector<int> &v)
{
	return v;
}


int &GetRef(int & i)
{
	return i;
}

int main()
{
   char *aa = NULL;
   a(aa);
   cout<<(void *)aa<<endl;

   int i = 1000;
   cout<<i<<endl;
   int &ii = GetRef(i);
   ii = 1999;
   cout<<i<<" "<<ii<<endl;
   int iii = GetRef(i);
   iii = 888;
   cout<<i<<" "<<ii<<" "<<iii<<endl;


   vector<int> v({1, 2, 3});
   cout<<v.size()<<endl;
   vector<int> &vv = GetRef(v);
   cout<<vv.size()<<endl;
   vv.push_back(4);
   cout<<v.size()<<" "<<vv.size()<<endl;
   vector<int> vvv = GetRef(v);
   vvv.push_back(5);
   cout<<v.size()<<" "<<vv.size()<<" "<<vvv.size()<<endl;
 



   return 0;
}

