#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> fl{1,2,3,4,5};
    for(auto i:fl)
    {
        std::cout<<i<<std::ends;
    }
    std::cout<<std::endl;

    fl.push_front(0);
    for(auto i:fl)
    {
        std::cout<<i<<std::ends;
    }
    std::cout<<std::endl;

    fl.pop_front();
    for(auto i:fl)
    {
        std::cout<<i<<std::ends;
    }
    std::cout<<std::endl;
}