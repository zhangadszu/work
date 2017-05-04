#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <string>

//注意引用参数，和指针的区分，引用其实是不生效的
extern "C" int so_interface(int i, float f, std::string &str, std::string *pstr);

extern "C" int sum(int i, int j);
#endif
