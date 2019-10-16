#include <iostream>

int main()
{
    std::cout<<static_cast<double>(6)/5<<std::endl;
    unsigned long l_value=0xF;
    auto l_ptr=&l_value;
    char *lchar=reinterpret_cast<char*>(l_ptr);
    std::cout<<*lchar<<std::endl;
}