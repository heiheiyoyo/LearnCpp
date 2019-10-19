#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s{"2019-10-19"};
    std::replace(s.begin(),s.end(),'-','/');
    std::cout<<s<<std::endl;
}