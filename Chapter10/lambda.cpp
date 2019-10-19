#include <iostream>
#include <string>

int main()
{
    int i=1;
    auto f=[i]() mutable ->int {if(i>0)return ++i;else return 0;}; //you can change the value of i in this lambda expression
    auto j=f();

    std::string s{"Hello,world"};
    auto sayHello=[&](){std::cout<<s;};
    sayHello();

}