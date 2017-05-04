// regex_replace example
#include <iostream>
#include <string>
#include <regex>
#include <iterator>

int main ()
{
    try
    { 
        std::string s ("there is a subsequence in the string\n");
        std::regex e ("\\b(sub)([^[:space:]])");   // matches words beginning by "sub"


        std::cout<<"aaa"<<std::endl;
        // using string/c-string (4) version:
        std::cout << std::regex_replace (s,e, std::string("sub-$2"));
        std::cout<<"bbb"<<std::endl;

        // using range/c-string (6) version:
        std::string result;
        std::regex_replace (std::back_inserter(result), s.begin(), s.end(), e, std::string("$2"));
        std::cout << result;

        // with flags:
        std::cout << std::regex_replace (s,e,std::string("$1 and $2"),std::regex_constants::format_no_copy);
        std::cout << std::endl;

    }
    catch (std::regex_error& e) {
        if (e.code() == std::regex_constants::error_badrepeat)
                std::cerr << "Repeat was not preceded by a valid regular expression.\n";
        else std::cerr << "Some other regex exception happened.\n";
    }

    return 0;
}
