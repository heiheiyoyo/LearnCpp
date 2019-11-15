#include <iostream>

#define interface class

interface iFun {
public:
    virtual std::string toString();
    virtual ~iFun()=default;
};

std::string iFun::toString()
{
    return "";
}

class MyClass final :public iFun
{
public:
    std::string toString() override;
};

std::string MyClass::toString()
{
    return "MyClass";
}

int main()
{
    MyClass a;
    iFun *p=&a;
    std::cout<<p->toString()<<std::endl;
}