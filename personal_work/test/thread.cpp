// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <unistd.h>

using namespace std; 
void foo() 
{
  // do stuff...
  std::cout<<"aaaaaa "<<time(NULL)<<endl;
  sleep(5);
  std::cout<<"cccccc "<<time(NULL)<<endl;
}

void bar(int x)
{
  // do stuff...
  std::cout<<"bbbbb "<<time(NULL)<<endl;
  sleep(3);
  std::cout<<"cdddd "<<time(NULL)<<endl;
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
