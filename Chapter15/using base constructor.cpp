class Base
{
private:
    int value;
public:
    Base(int i) :value(i){}
    ~Base() =default;
};

class Derived:public Base
{
private:
    
public:
    using Base::Base;
};

int main()
{
    Derived(1);
}