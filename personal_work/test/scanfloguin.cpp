#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//<qzone uin="622007668">
	
	ifstream in("log_GetBlogTag.log");
	ofstream out("uinlist_log"); 
	//ofstream out_c("tmp.txt");
	
	int uin, blogid, tmp = -1;
	char buf[10][128];
	while(!in.eof())
	{
		in>>buf[0]>>buf[1]>>buf[2]>>buf[3]>>buf[5]>>uin>>buf[4]>>blogid;
		
		if(uin != tmp)
		{
			out<<uin<<endl;
			tmp = uin;
		}		
	}

	return 0;
}

