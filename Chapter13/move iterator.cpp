#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<std::string> svec{"Hello,","World!\n"};
    decltype(svec) s2;
    std::copy(std::make_move_iterator(svec.begin()),
              std::make_move_iterator(svec.end()),
              std::back_inserter(s2));
    for(auto i:s2)
    {
        std::cout<<i;
    }
    svec.clear();
}