#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	int run();
private:

	int caller(vector<int> &vecInt);	
	
	vector<int> m_vecInt;
};

int A::run()
{

	caller(m_vecInt);
	
	return 0;
}


int A::caller(vector<int> &vecInt)
{
	cout<<vecInt.size()<<endl;
	cout<<m_vecInt.size()<<endl;

	vecInt.push_back(0);
	cout<<vecInt.size()<<endl;
        cout<<m_vecInt.size()<<endl;

	m_vecInt.push_back(0);
        cout<<vecInt.size()<<endl;
        cout<<m_vecInt.size()<<endl;	

	return 0;
}


int main()
{
	A a;
	a.run();

	return 0;
}


