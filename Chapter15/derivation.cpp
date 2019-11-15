#include <iostream>

class Base
{
public:
    virtual void sayHello()
    {
        std::cout<<"Hello,I'am Base\n";
    }
    void publfun()
    {
        std::cout<<"Base::publfun\n";
    }
protected:
    void protfun()
    {
        std::cout<<"Base::protfun\n";
    }
private:
    void privfun()
    {
        std::cout<<"Base::privfun\n";
    }
};

class Pub_Derv : public Base
{
public:
    void test()
    {
        publfun();
        protfun();
        //privfun();
    }
};


class Priv_Detv :private Base
{
public:
    void test()
    {
        publfun();
        protfun();
        //privfun();
    }
    using Base::protfun;

};

class Derived_from_Public:public Pub_Derv
{
public:
    void test()
    {
        publfun();
        protfun();
        //privfun();
    }

};

class Derived_from_Private:public Priv_Detv
{
public:
    void test()
    {
        //publfun();
        protfun();
        //privfun();
    }

};

int main()
{
    Derived_from_Public().test();
    Derived_from_Private().test();
}