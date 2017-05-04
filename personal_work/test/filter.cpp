#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main ()
{ 
 string str = "http://sz5.photo.store.qq.com/http_imgload.cgi?/rurl4_b=82c9165749cecfd523f23d177339f48e51409a833efdeec544fceb0ecd663f831e6119e4551790239669db9465a6e7d3be40dbd6b290d94213a81fc30ba3cf497002bccf8fb0b3ec06a2de5772c6b55e7ef7d2fc";
 unsigned int pos1 = str.find("photo.store.qq.com");
 if(pos1 == string::npos)
 {
  cout<<"photo.store.qq.com not found!"<<endl;
  return 0;
 }
 
 unsigned int pos2 = str.find("rurl4_b", pos1);
 if(pos2 == string::npos)
 {
  cout<<"rurl4_b not found!"<<endl;
  return 0;
 }
 
 cout<<str<<endl;
 str[pos2 + 6] = 's';
 cout<<str<<endl;
 
 return 0;
}
