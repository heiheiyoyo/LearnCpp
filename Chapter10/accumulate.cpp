#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main()
{
    std::vector<int> vec{42, 14, 58, 45, 11, 98};
    auto sum = std::accumulate(vec.begin(), vec.end(), 0); //accumulate in numeric
    std::cout << "\nSum: " << sum<<std::endl;

    int iarray[]{1,2,3,4,5};
    std::cout<<std::accumulate(iarray,iarray+3,0)<<std::endl;

}