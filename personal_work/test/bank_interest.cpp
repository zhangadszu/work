#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		cerr<<"\n\tUsage: "<<argv[0]<<" 本金 年利息(%) 期数(月)"<<endl<<endl;
		return 1;
	}
	
	double a = atof(argv[1]);
	double e = atof(argv[2]) / 100 / 12;
	int n = atoi(argv[3]);
	cout<<"每期还款额："<<setiosflags(ios::fixed)<<setprecision(2)<<a * pow((1 + e), n) * e / (pow((1 + e), n) - 1)<<endl;  
	
	return 0;
}


