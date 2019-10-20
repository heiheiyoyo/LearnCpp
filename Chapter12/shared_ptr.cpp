#include <iostream>
#include <memory>
#include <string>

int main()
{
    auto sp1=std::make_shared<std::string>(15,'-');
    auto sp2=std::make_shared<std::string>(15,'|');
    std::cout<<"sp1:"<<*sp1<<" sp2:"<<*sp2<<"\n";
    std::swap(sp1,sp2);
    std::cout<<"sp1:"<<*sp1<<" sp2:"<<*sp2<<"\n";
    {
    auto sp3=sp2;
    std::cout<<"sp3 use count: "<<sp2.use_count()<<std::endl;
    }
    std::cout<<"sp3 use count: "<<sp2.use_count()<<std::endl;
    
}