#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <string>
using namespace std;

int main()
{
	vector<string> vs;
	vs.push_back("#@#@@#@##@$");
	swap(vs[0], vs[0]);
	cout<<vs[0]<<endl;


	vector<int> va;
	vector<int> vb;

	for(int i = 0; i < 100000000; i++)
		va.push_back(i);

		
	struct timeval tv;
	gettimeofday(&tv, NULL);
	vb = va;
	struct timeval tva;
        gettimeofday(&tva, NULL);	
	cout<<"operator '=' cost time: "<<(tva.tv_sec - tv.tv_sec)*1000000+tva.tv_usec-tv.tv_usec<<endl;

	gettimeofday(&tv, NULL);	
	vector<int> vc;	
	swap(vb, vc);
	gettimeofday(&tva, NULL);
        cout<<"algorithm swap cost time: "<<(tva.tv_sec - tv.tv_sec)*1000000+tva.tv_usec-tv.tv_usec<<endl;

	if(va == vc)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;		
	
	cout<<"va.size() = "<<va.size()<<endl;	
	cout<<"vb.size() = "<<vb.size()<<endl;	
	cout<<"vc.size() = "<<vc.size()<<endl;

	return 0;
}


