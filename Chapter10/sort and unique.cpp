#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string str("apple pine");
    std::cout<<"origin string: "<<str<<std::endl;

    std::sort(str.begin(),str.end());
    std::cout<<"after sort: "<<str<<std::endl;

    auto end_unique=std::unique(str.begin(),str.end());
    std::cout<<"after unique: "<<str<<std::endl;

    str.erase(end_unique,str.end());
    std::cout<<"after erase: "<<str<<std::endl;
}