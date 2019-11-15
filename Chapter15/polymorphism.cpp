#include <iostream>
#include <string>

class Hello {
    public:
    virtual void SayHello() const;
};

class World :public Hello {
    public:
    void SayHello() const override;
};

void Hello::SayHello() const
{
    std::cout<<"Hello";
}

void World::SayHello() const
{
    std::cout<<"World";
}

void testSayHello(Hello in)
{
    in.SayHello();
    std::cout<<"\n";
}

void testSayHello2(const Hello &in)
{
    in.SayHello();
    std::cout<<"\n";
}

int main()
{
    Hello a;
    a.SayHello();
    World b;
    b.SayHello();
    std::cout<<"\n";
    
    testSayHello(b);
    testSayHello2(b);
    std::cout<<"\n";
    static_cast<Hello>(b).SayHello();

    
    
    //使用指针
    Hello *hp=&b;
    hp->SayHello();

    //使用引用
    Hello &hr=b;
    std::cout<<"\n";
    b.Hello::SayHello();
    b.SayHello();

}