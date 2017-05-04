#include <iostream>
#include <vector>
#include <string>
#include <sys/time.h>
#include <algorithm>

using namespace std;

int main()
{
	string str = "abcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+}{:";

	timeval tv;
	gettimeofday(&tv, NULL);
	cout<<"a time:"<<tv.tv_sec<<" "<<tv.tv_usec<<endl;

	while(str.size() < 500 * 1024 * 1024)
	{
		gettimeofday(&tv, NULL);
		cout<<"a time:"<<tv.tv_sec<<" "<<tv.tv_usec<<" "<<str.size()<<endl;
		str += str;
	}

	gettimeofday(&tv, NULL);
    cout<<"b time:"<<tv.tv_sec<<" "<<tv.tv_usec<<endl;
	

	string findStr = "u543+G";
	str += findStr;

	cout<<str.find(findStr)<<endl;

	gettimeofday(&tv, NULL);
	cout<<"c time:"<<tv.tv_sec<<" "<<tv.tv_usec<<endl;

	std::vector<std::string> vs;
	for(int i = 0; i < 1000000; ++i)
	{
		char buf[32];
		snprintf(buf, sizeof(buf), "123456%d", i);
		vs.push_back(buf);
	}
	gettimeofday(&tv, NULL);
	cout<<"d time:"<<tv.tv_sec<<" "<<tv.tv_usec<<endl;

	vs.push_back("123456123456a");

    std::string findstr = "123456123456a";
	std::find(vs.begin(), vs.end(), findstr);

	gettimeofday(&tv, NULL);
	cout<<"e time:"<<tv.tv_sec<<" "<<tv.tv_usec<<endl;

	
	
	
	return 0;
};
