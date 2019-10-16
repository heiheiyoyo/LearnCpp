#include<iostream>
#include<string>
#include<vector>

int main()
{
    for(auto i:{1,2,3})
    {
        std::cout<<i<<std::endl;
    }
    std::vector<int> ivec{0,2,4,8,16};
    std::cout<<std::string(10,'-')<<std::endl;
    for(auto &r:ivec)
    {
        r*=2;
    }
    auto s=ivec.begin(),e=ivec.end();
    while (s!=e)
    {
        std::cout<<*s<<std::endl;
        s++;
    }
    
}