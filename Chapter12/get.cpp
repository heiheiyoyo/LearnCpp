#include <iostream>
#include <memory>

void reset(int* pi)
{
    *pi=0;
}

int main()
{
    auto spi=std::make_shared<int>(5);
    reset(spi.get());
    std::cout<<*spi;
}