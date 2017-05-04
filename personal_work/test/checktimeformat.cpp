#include <stdio.h>
#include <string>

using namespace std;

bool checkdatetimeformat(const string &str)
{
	int year, month, day, hour, minute, second;
	int  retcode = sscanf(str.c_str(), "%4d-%2d-%2d %2d:%2d:%2d",	
		&year, &month, &day, &hour, &minute, &second);
	if (6 !=retcode)
	{
		return false;
	}
	if(year < 2008 || year > 3000)
	{
		return false;
	}
	if(month < 1 || month > 12)
	{
		return false;
	}
	if(day < 1 || day > 31)
	{
		return false;
	}
	if(hour < 0 || hour > 23)
	{
		return false;
	}
	if(minute < 0 || minute > 59)
	{
		return false;
	}
	if(second < 0 || second > 59)
	{
		return false;
	}

	return true;
}


int main ()
{
	char buf[1024];
	while(1)
	{	
		printf("please input strings\n");
		fgets(buf, sizeof(buf)-1, stdin);

		string str = buf;
		
		if (checkdatetimeformat(str))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		
	}


}

