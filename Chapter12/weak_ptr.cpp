#include <iostream>
#include <memory>
#include <string>

int main()
{
    auto ps=std::make_shared<std::string>("Hello,world");
    std::weak_ptr<std::string> wp(ps);
    if(auto np=wp.lock())
    {
        std::cout<<*np<<std::endl;
    }
    else
    {
        std::cerr<<"Failed!"<<std::endl;
    }
    ps.reset();
    if(auto np=wp.lock())
    {
        std::cout<<*np<<std::endl;
    }
    else
    {
        std::cerr<<"Failed!"<<std::endl;
    }
    
}