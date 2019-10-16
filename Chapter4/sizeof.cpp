#include <iostream>
#include <vector>

int main()
{
    std::cout<<sizeof(std::vector<int>)<<std::endl;
    std::cout<<sizeof(std::vector<int>::size)<<std::endl; //using sizeof to get the size of a class member, even it is not a static value
    std::cout<<sizeof(std::vector<int>::size_type);
}