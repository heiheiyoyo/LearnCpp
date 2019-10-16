#include <iostream>

int main()
{
    std::cout<<static_cast<double>(6)/5<<std::endl;
    unsigned long l_value=0x4f4c4c4548;
    // For little end machine, this means HELLO. In ASCII, H is 48, and E is 48, so on.
    auto l_ptr=&l_value;
    char *lchar=reinterpret_cast<char*>(l_ptr);
    std::cout<<lchar<<std::endl;
}
