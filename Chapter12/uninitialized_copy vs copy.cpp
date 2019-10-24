#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class A
{
public:
    explicit A(int i) : value(i) {}
    int get() const { return value; }

private:
    int value;
};

int main()
{
    std::vector<A> avec(10, A(3));
    std::allocator<A> alloc;
    auto const p=alloc.allocate(20);
    int initarray[10]{0,1,2,3,4,5,6,7,8,9};
    std::uninitialized_copy(std::begin(initarray),std::end(initarray),p);
    std::copy(avec.begin(),avec.end(),p+10);
    auto q=p;
    while(q!=p+20)
    {
        std::cout<<q->get()<<"\n";
        q++;
    }

}