#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s{"/Users/tom/.ssh"};
    auto comma=std::find(s.crbegin(),s.crend(),'/');
    std::cout<<std::string(comma.base(),s.cend()); //use member function base() to convert to normal  iterator
}