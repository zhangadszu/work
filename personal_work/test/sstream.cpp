#include <sstream>
#include <iostream>

using namespace std;
/*
template<typename T>
string Value2Str(T i)
{
	std::ostringstream oss;
	oss<<i;
	return oss.str();
}

template<typename T>
void Str2Value(const string str, T &value)
{
	    std::istringstream(str)>>value;
}
*/
string Value2Str(uint32_t uValue)
{
	    char szTmp[32];
	    snprintf(szTmp, sizeof(szTmp), "%u", uValue);
	    return string(szTmp);
}

uint32_t Str2Value(const string &str)
{
	    return strtoul(str.c_str(), NULL, 10);
}

int main()
{
	uint8_t c = 65;
	uint32_t i = 1123489666;
	cout<<Value2Str(c)<<endl;
	cout<<Value2Str(i)<<endl;	

	string strc = Value2Str(c);
	string stri = Value2Str(i);

	char cc = Str2Value(strc);
	unsigned int ii = Str2Value(stri);
	cout<<cc<<endl;
	cout<<ii<<endl;

	
	return 0;
}

