#include <string>
#include <iostream>

using namespace std;

int main()
{
   string empty;
   cout<<"find_first_of:"<< (empty.find_first_of(" ")) << endl;


    string url = "http://qqadapt.qpic.cn/wecam_pic/0/1009_3e384bf5486d4ca08f1d49331b0d470b_1/0?w5=0&h5=0";
    auto p = url.find("_1/0");
    if(p != string::npos)
    {
        url[p + 1] = '2';
        cout<<url;
    }


    //string s20130412 = NULL;
    //string s20130412;
	//char *p = NULL;
	//s20130412 = p;
	//s20130412.assign(p, 1);


    string aaaa = "1123213";
    string bbbb = aaaa.substr(aaaa.size());
    cout<<aaaa<<" "<<bbbb<<endl;

	string str201008;
	//str201008.assign(NULL, 1);
	cout<<str201008.size()<<endl;
	string str201007 = "abcdefg";
	str201007.replace(2, string::npos - 2, "a");
	cout<<str201007<<endl;
	return 0;


	string str200911 = "dhf";
	string str200911a = str200911.substr(1, 0);
	cout<<"|"<<str200911a<<"|"<<endl;
	return 0;

	string strNPOS = "ABCDEFGHIJK";
	if(strNPOS.find("I", string::npos) == string::npos)
	{
		cout<<"you are right!"<<endl;
	}
	else
	{
		cout<<"you are wrong "<<strNPOS.find("I", string::npos)<<endl;
	}	

	unsigned int iPos = string::npos;
	cout<<iPos + 1 <<endl;
	iPos += 1;
	cout<<iPos<<endl;	
	
	return 0;

	string straaa = "abcdefgabck";
	cout<<straaa.substr(straaa.size())<<"|"<<endl;

	cout<<straaa.find("aa", string::npos)<<endl;
	
	cout<<straaa.find_first_of("ab", 5)<<endl;
	
	return 0;
	
	string strFindFirstOf = "123456789";
	strFindFirstOf += -13;

	cout<<strFindFirstOf<<" size: "<<strFindFirstOf.size()<<endl;
	cout<<(strFindFirstOf[9] == -13 ? "YES":"NO")<<endl;
	
	if(strFindFirstOf.find_first_of("") == string::npos)
	{
		cout<<"find_first_of... no"<<endl;		

	}
	

	string strAssign;
	char szAssign[] = {0, 0, 1};
	strAssign.assign(szAssign, 3);
	strAssign.assign(szAssign, 3);
	if(strAssign[2] == 1)
	{
		cout<<"YES"<<endl;
	}
	cout<<strAssign.size()<<endl;

	return 0;


	string strAppend = "abc";
	cout<<strAppend<<" size: "<<strAppend.size()<<endl;
	strAppend.append(string(""));
	cout<<strAppend<<" size: "<<strAppend.size()<<endl;
	strAppend.append(string("defg"));
        cout<<strAppend<<" size: "<<strAppend.size()<<endl;

	string strFilter = "\x01";
	cout<<"size: "<<strFilter.size()<<" content: "<<strFilter<<endl;
	

	//string strtest(NULL);     //coredump
	//string strtest = NULL;    //coredump

	string strtest = (1 == 0) ? "aaaaaa" : "bbbbbbb";
	cout<<strtest<<endl;

	const char *pc = "1234567890";	
	cout<<(const char *)pc<<" "<<sizeof(pc)<<endl;

	cout<<(void *)""<<endl;
	cout<<(void *)""<<endl;

	string str = "abcdefg123456789abcdefghijklmnopqrstuvwxyz";

	printf("%d\n", str.find("9a"));
	printf("%d\n", str.find("efg", str.find("9a")));

	printf("%u\n", str.find("NOTESEXIT"));
	printf("%d\n", str.find("efg", str.find("NOTESEXIT")));
	
	unsigned int pos = string::npos;
	printf("%u\n", pos);

	return 0;
}

