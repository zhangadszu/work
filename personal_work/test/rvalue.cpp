#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int &&i = 1;
	cout<<i<<endl;
	i = 2;
	cout<<i<<endl;

	int ii = 1;
	const int &iii = std::move(ii);
	cout<<ii<<" "<<iii<<endl; 
	//iii = 2;
	ii = 3;
	cout<<ii<<" "<<iii<<endl;
	cout<<(void *)&ii<<" "<<(void *)&iii<<endl;

	string &&sr = string("abc");
	cout<<sr<<endl<<endl;

	string ss = "123";
	const string sr2 = std::move(ss);
	//const string &sr2 = std::move(ss); //reference
	//string sr2 = std::move(ss);
	//string &sr2 = std::move(ss); invalid
	//string &&sr2 = std::move(ss);
	//const string &&sr2 = std::move(ss);
	cout<<sr2<<" # "<<ss<<endl;

	std::string foo = "foo-string";
	std::string bar = "bar-string";
	std::vector<std::string> myvector;

	myvector.push_back (foo);                    // copies
	myvector.push_back (std::move(bar));         // moves

	std::cout << "myvector contains:";
	for (std::string& x:myvector) std::cout << ' ' << x;
	std::cout << endl;
	cout<<"bar: "<<bar<<endl;

	std::move(foo);
	cout<<"foo: "<<foo<<endl;

	return 0;
}

