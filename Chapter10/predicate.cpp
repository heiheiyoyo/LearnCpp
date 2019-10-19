#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> svec{"Hello","World","Tom","Apple","a"};
    auto isShorter=[](const std::string &s1,const std::string &s2){return s1.size()<s2.size();};
    std::sort(svec.begin(),svec.end(),isShorter);
    for(auto &i:svec)
    {
        std::cout<<i<<std::endl;
    }
}