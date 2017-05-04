#include <string>
#include <iostream>
int main(int argc, char *argv[])
{
    std::hash<std::string> h;
    size_t n = h("Hello, Tencent Qzone!");
    std::cout << n << std::endl;
    return 0;
}
