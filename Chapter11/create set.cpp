#include <iostream>
#include <string>
#include <set>

int main()
{
    std::set<std::string> ss{"v","a","b","o","g"};
    for(const auto &i:ss)
    {
        std::cout<<i;
    }
}