#include <iostream>
#include <algorithm>

int main()
{
    char s1[]{"Hello,world"};
    char s2[15]{0};
    std::copy(std::begin(s1),std::end(s1),s2);
    std::cout<<s2<<std::endl;
}