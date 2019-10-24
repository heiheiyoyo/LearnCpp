#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> p1(new int(1024));
    std::shared_ptr<int> p2{new int(1024)};
    //std::shared_ptr<int> p2=new int(1024); //Constructor is explicit
    
}