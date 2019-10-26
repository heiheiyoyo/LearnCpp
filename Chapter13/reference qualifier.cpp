class Foo {
    public:
    Foo &operator=(const Foo&) &;
};

Foo &Foo::operator=(const Foo &rhs) &
{
    return *this;
}

Foo &retFoo()
{
    return *(new Foo);
}

Foo retVal()
{
    return Foo();
}

int main()
{
    Foo i,j;
    i=j;
    auto &tem=retFoo()=j;
    //retVal()=j; error
    i=retVal();
    delete &tem;
}