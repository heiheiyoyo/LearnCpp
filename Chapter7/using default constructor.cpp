#include <iostream>
#include <string>

std::string s();//declare a function, s is a function, not a class object
int main()
{
    std::cout<<s()<<std::endl;
    std::string s2; //s is a string
    //std::string s2() <- error
    s2 = "Hello,tom";
    std::cout<<s2<<std::endl;
}

std::string s()
{
    return "Hello,world";
}