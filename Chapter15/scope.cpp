#include <iostream>

class Base
{
public:
    void test()
    {
        std::cout<<"Base\n";
    }
};

class Deriv:public Base
{
public:
    void test()
    {
        std::cout<<"Deriv\n";
    }
};

int main()
{
    Deriv d;
    d.test();
    d.Base::test();
}