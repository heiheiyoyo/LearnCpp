#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<std::string> svec{"hello","world","Anna"};
    std::ostream_iterator<std::string> out(std::cout,",");
    std::remove_copy(svec.begin(),svec.end(),out,"Anna");
}