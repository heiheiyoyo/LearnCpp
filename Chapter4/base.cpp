#include <iostream>

int main()
{
    int a=10;
    auto intptr=new int{5};
    decltype(*intptr) p=a; // "*intptr" is a lvalue, so the type of "p" is int&
}