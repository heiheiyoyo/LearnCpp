#include <iostream>

class Int
{
public:
    Int(int i):int_(i) {}
    Int(const Int& I):int_(I.int_) {}
    int get(){return int_;}
    
private:
    int int_;
};

class Int2
{
public:
    explicit Int2(int i):int_(i) {}
    Int2(const Int2& I):int_(I.int_) {}
    int get(){return int_;}
    
private:
    int int_;
};


int main()
{
    Int i1=3;//equal to Int i1=Int(3) or Int i1(Int(3))
    Int i2=Int(3);
    Int i3(Int(3));

    Int2 i4=Int2(3);
    //Int2 i5=3; error
    
}