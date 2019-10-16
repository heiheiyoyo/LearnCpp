#include<iostream>

void get_value(std::initializer_list<int> input)
{
    for(auto beg =input.begin();beg!=input.end();++beg)
    {
        std::cout<<*beg<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    get_value({1,2,3});
}