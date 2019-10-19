#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::ostream_iterator<int> out_iter(std::cout," ");
    std::copy(vec.begin(),vec.end(),out_iter);
}