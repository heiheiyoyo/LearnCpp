#include <iostream>
#include <unordered_set>

int main()
{
    std::string s;
    while(std::cin>>s)
    {
        std::cout<<std::hash<std::string>()(s)<<std::endl;
    }
}