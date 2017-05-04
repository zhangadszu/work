#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for_each(v.begin(), v.end(), [](int i){cout<<i<<endl;});
    for_each(v.begin(), v.end(), [](int &i){ i = 100 + i;});
    for_each(v.begin(), v.end(), [](int i){cout<<i<<endl;});

    return 0;
}

