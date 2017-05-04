#include <iostream>
#include <string>

using namespace std;

static string getMainDomain(const std::string &url)
{
	const string http_protocol = "http://";
	const string https_protocol = "https://";
	size_t start_pos = 0;
	if(url.find(http_protocol) == 0)
	{
		start_pos = http_protocol.size();
	}
	else if(url.find(https_protocol) == 0)
	{
		start_pos = https_protocol.size();
	}
	else
	{
		return ""; 
	}

	string domain;
	size_t end_pos = url.find("/", start_pos);
	if(string::npos == end_pos) //Èçhttp://www.qq.com
	{
		domain = url.substr(start_pos);
	}
	else //Èçhttp://user.qzone.qq.com/103041149
	{
		domain = url.substr(start_pos, end_pos - start_pos);
	}

	size_t spot_pos = domain.rfind(".");
	if(string::npos == spot_pos
			|| 0 == spot_pos) 
	{
		return "";
	}

	--spot_pos;
	spot_pos = domain.rfind(".", spot_pos);
	if(string::npos == spot_pos) 
	{
		return domain;
	}
	else
	{
		return domain.substr(spot_pos + 1);
	}
}

int main()
{
	string a = "http://www.qq.com";
	string b = "https://www.qq.com";
	string c = "http://www.aaa.qq.com";
	string d = "http://www.aaa.qq.com/adsf/fsdf";
	string e = "http://.qq.com/sdf/";
	string f = "http://.com/sdfsd/sdfs/fsdfd";
	
	cout<<a<<" "<<getMainDomain(a)<<endl;
	cout<<b<<" "<<getMainDomain(b)<<endl;
	cout<<c<<" "<<getMainDomain(c)<<endl;
	cout<<d<<" "<<getMainDomain(d)<<endl;
	cout<<e<<" "<<getMainDomain(e)<<endl;
	cout<<f<<" "<<getMainDomain(f)<<endl;
	
	return 0;
}


