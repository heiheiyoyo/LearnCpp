#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::unique_ptr<std::string> p1(new std::string("Hello,world!"));
    std::cout<<*p1<<std::endl;
    std::unique_ptr<std::string> p2(p1.release());
    *p2+="2";
    std::cout<<*p2<<std::endl;
    p2=nullptr;
}