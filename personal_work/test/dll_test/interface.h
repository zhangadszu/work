#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <string>

//ע�����ò�������ָ������֣�������ʵ�ǲ���Ч��
extern "C" int so_interface(int i, float f, std::string &str, std::string *pstr);

extern "C" int sum(int i, int j);
#endif
