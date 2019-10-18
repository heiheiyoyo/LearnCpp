#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("IO status.cpp");
    std::string s;
    while(std::getline(input,s))
    {
        std::cout<<s<<std::endl;
    }
}