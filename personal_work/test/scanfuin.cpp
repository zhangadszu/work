#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{	
	int a, b, c, d = 199;
	cout<<sscanf("123|456|789", "%d|%d|%d|%d|", &a, &b, &c, &d)<<endl;;
	
	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;



	int aaa = atoi("123456789123456789");
	cout<<"atoi(\"123456789123456789\") == "<<aaa<<endl;	


	string str = "1000b1002a1003a1004";
	char split[2] = {'b', '\0'};
	unsigned int pos1 = str.rfind(split);//�Ӻ����ҷָ��ַ���
	unsigned int pos2 = 0;
	if(pos1 != string::npos)//������һ�ظ��ˣ�����ǰ�Ļظ��˾��ǵ�һ�������۷���ظ�����
	{
		pos2 = str.rfind(split, pos1 - 1);
		if(pos2 == string::npos)
		{
			pos2 = 0;
		}
		else 
		{
			pos2 += strlen(split);
		}

		int iLastCommetUin = atoi(str.c_str() + pos2);
		cout<<"ilastuin "<<iLastCommetUin<<"\n*********"<<endl;
	}


	//<qzone uin="622007668">
	
	ifstream in("uinlist.txt");
	ofstream out("uinlist"); 
	ofstream out_c("tmp.txt");
	
	int uin;
	char buf[128];
	while(!in.eof())
	{
		in.getline(buf, 127);
		
		uin = 0;
		int ret = sscanf(buf, "  <qzone uin=\"%d\">", &uin);
	
		if(ret == 1 && uin > 10000 && uin <1200000000)
		{
			out<<uin<<endl;
	
			out_c<<"  <qzone uin=\""<<uin<<"\">"<<endl;
		}
		
	}


	return 0;
}

