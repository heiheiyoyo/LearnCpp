#include <iostream>
#include <set>

int main()
{
    std::set<int> int_set{1,2,3,4,5};
    auto result=int_set.insert(5);
    std::cout<<"Status:"<<result.second<<std::endl;
    auto result=int_set.insert(6);
    std::cout<<"Status:"<<result.second<<std::endl;
    
}