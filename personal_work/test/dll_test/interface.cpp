#include <string>
#include <iostream>
#include <cstdio>
#include "interface.h"

using namespace std;

//ע�����ò�������ָ������֣�������ʵ�ǲ���Ч��
extern "C" int so_interface(int i, float f, std::string &str, std::string *pstr)
{
	string s;
	char buf[128];
	snprintf(buf, sizeof(buf), "print from interface so, i=%d, f=%f, str=%s, pstr=%s", i, f, str.c_str(), pstr->c_str());
	s = buf;
	cout<<s<<endl;
	
	str = "after";
	*pstr = "after";
	return 123456789;
}

extern "C" int sum(int i, int j)
{
    return i + j;
}

