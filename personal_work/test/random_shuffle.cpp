#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	vector<unsigned int> vecA(6000000);
	for(int i = 0; i < 6000000; i++)
		vecA[i] = i;

	std::random_shuffle(vecA.begin(), vecA.end());
	std::random_shuffle(vecA.begin(), vecA.end());
	vecA.resize(4500000);

	ofstream out("a");
	for(vector<unsigned int>::iterator it = vecA.begin(); it != vecA.end(); it++)
		out<<*it<<endl;

	return 0;
}

