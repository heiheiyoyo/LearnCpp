#include <string>

int main()
{
    std::string s("Hello"); 
    std::string s2="Hello"; //copy
    std::string s3=std::string("Hello"); //take the same effect
    std::string &&s4=std::string("Hello"); //rvalue reference, faster
}