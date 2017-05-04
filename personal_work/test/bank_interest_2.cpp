#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		cerr<<"\n\tUsage: "<<argv[0]<<" 每期还款额  年利息(%) 期数(月)"<<endl<<endl;
		return 1;
	}
	
	double a = atof(argv[1]);
	double e = atof(argv[2]) / 100 / 12;
	int n = atoi(argv[3]);
	cout<<"本金是："<<setiosflags(ios::fixed)<<setprecision(2)<<a * (pow((1 + e), n) - 1) / (pow((1 + e), n) * e)<<endl;  
	
	return 0;
}


