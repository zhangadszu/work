#include <string>
#include <cstdio>
#include <iostream>
#include <dlfcn.h>

using namespace std;
int main()
{
	void *so_handle = NULL;
	typedef int (*func_handle)(int, float, string, string *);

	so_handle = dlopen("./interface.so", RTLD_NOW);
	if(!so_handle)
	{
		cout<<"so_handle NULL, msg:"<<dlerror()<<endl;
		return 1;
	}
	
	func_handle fh = (func_handle)dlsym(so_handle, "so_interface");
	if(!fh)
	{
		cout<<"func_handle NULL, msg:"<<dlerror()<<endl;
		return 2;
	}
	
	string str = "befor";
	string pstr = "befor";
	//注意引用参数，和指针的区分，引用其实是不生效的
	int ret = (*fh)(6461, 123150.54f, str, &pstr);
	cout<<"call func, ret:"<<ret<<endl;	
	
	
	string s;
	char buf[128];
	//注意引用参数，和指针的区分，引用其实是不生效的
	snprintf(buf, sizeof(buf), "print from main, i=%d, f=%f, str=%s, pstr=%s", 6461, 12350.54f, str.c_str(), pstr.c_str());
	s = buf;
	cout<<s<<endl;
	
	dlclose(so_handle);

	return 0;
}


