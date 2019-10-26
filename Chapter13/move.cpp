#include <iostream>
#include <memory>

class Int
{
public:
    Int() : value(0) {}
    Int(int i) : value(i) {}
    Int(const Int &in) : value(in.value) {}
    Int(Int &&in) noexcept
        : value(in.value) { in.value = 0; }
    Int &operator=(const Int &rhs);
    Int &operator=(Int &&rhs) noexcept;
    int get()
    {
        return value;
    }
    void set(int i)
    {
        value = i;
    }

private:
    int value;
};

int main()
{
    Int a = 1;
    Int b = std::move(a); //move
    std::cout << a.get() << std::endl;
    a.set(1);
    Int &&c = std::move(a);//??
    std::cout << a.get() << std::endl;
}

Int &Int::operator=(const Int &rhs)
{
    value = rhs.value;
    return *this;
}
Int &Int::operator=(Int &&rhs) noexcept
{
    value = rhs.value;
    value = 0;
    return *this;
}