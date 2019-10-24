#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::allocator<std::string> alloc;
    auto const p=alloc.allocate(10);
    for(int i=0;i!=10;i++)
    {
        alloc.construct(p+i,std::to_string(i));
    }
    auto q=p;
    while(q!=p+10)
    {
        std::cout<<*q<<"\n";
        q++;
    }

    std::allocator<char> buffer_alloc;
    auto buffer=buffer_alloc.allocate(128);
    std::uninitialized_fill_n(buffer,128,0);
    std::cout<<"Input something: ";
    std::cin>>buffer;
    std::cout<<"You input: "<<buffer<<std::endl;
}