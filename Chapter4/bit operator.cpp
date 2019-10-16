#include <iostream>

int main()
{
    unsigned long i=1;
    std::cout<<std::hex<<i<<std::endl;
    auto b=i<<4;
    std::cout<<std::hex<<b<<std::endl;
    std::cout<<std::hex<<(i|b)<<std::endl;
    std::cout<<std::hex<<((i|b)&0xF0L)<<std::endl;
    b=b^b; //set b to zero
    std::cout<<std::hex<<b<<std::endl;

}