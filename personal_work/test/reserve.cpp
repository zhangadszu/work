#include <vector>
#include <iostream>

using namespace std;

int test()
{
	vector<int> vInt;
        vInt.reserve(1);
        //cout<<"size: "<<vInt.size()<<endl;


        for(int i = 0; i < 111; i++)
        {
                //difference
                //vInt[i] = i;
                vInt.push_back(i);
        }
	

	return 0;
}

int main()
{

	for(int i = 0; i < 1000000; i++)
		test();



	return 0;
}

