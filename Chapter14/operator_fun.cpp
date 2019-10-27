#include <iostream>
#include <vector>

class Delegate
{
public:
    Delegate() = default;
    Delegate(void (*fun)()) : funvec{fun} {}
    Delegate &operator=(void (*)());
    Delegate &operator+=(void (*)());
    void operator()() const;

private:
    std::vector<void (*)()> funvec;
};

void Delegate::operator()() const
{
    for (auto &f : funvec)
    {
        f();
    }
}

Delegate &Delegate::operator+=(void (*fun)())
{
    funvec.push_back(fun);
    return *this;
}

Delegate &Delegate::operator=(void (*fun)())
{
    funvec = std::vector<decltype(fun)>{fun};
    return *this;
}

int main()
{
    Delegate d1([]() { std::cout << "Hello"; });
    d1+=[](){std::cout <<"World";};
    d1();
}