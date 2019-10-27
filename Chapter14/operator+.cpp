class Int
{
public:
    Int() : value(0) {}
    Int(int i) : value(i) {}
    Int(const Int &i) : value(i.value) {}
    Int(Int &&i) : value(i.value) {}
    Int &operator=(const Int &rhs) &;
    Int &operator=(Int &&rhs) & noexcept;
    Int operator+(const Int &rhs) const;
    operator int() const;

private:
    int value;
};

Int &Int::operator=(const Int &rhs) &
{
    value=rhs.value;
    return *this;
}

Int &Int::operator=(Int &&rhs) & noexcept
{
    value=rhs.value;
    return *this;
}

Int Int::operator+(const Int &rhs) const
{
    return Int(value+rhs.value);
}

Int::operator int() const
{
    return value;
}

int main()
{
    Int i1=1;
    Int i2=2;
    int i3=i1+i2;

}