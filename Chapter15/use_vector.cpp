#include <iostream>
#include <vector>
#include <memory>

class Base
{
    public:
    virtual void sayHello()
    {
        std::cout<<"Hello,I'm Base\n";
    }
};

class Detrive :public Base
{
    public:
    void sayHello() override
    {
        std::cout<<"Hello,I'm Detrive\n";
    }
};

int main()
{
    std::vector<std::shared_ptr<Base>> basket;
    basket.push_back(std::make_shared<Base>());
    basket.push_back(std::make_shared<Detrive>());
    basket[0]->sayHello();
    basket[1]->sayHello();

}