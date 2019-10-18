#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input("IO status.cpp");
    char i;
    while(input>>i)
    {
        std::cout<<i;
    }

}