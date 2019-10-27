#include <iostream>
#include <cstring>

class Str
{
    friend std::ostream &operator<<(std::ostream &os, const Str &s);

public:
    Str() : value(nullptr) {}
    Str(const char *);
    ~Str() { delete value; }
    bool operator==(const Str &) const;
    char &operator[](std::size_t n) { return value[n]; }
    const char &operator[](std::size_t n) const { return value[n]; }
    explicit operator bool() const { return value; }
    std::size_t size() { return std::strlen(value) + 1; }

private:
    char *value;
};

Str::Str(const char *c)
{
    auto data = new char[std::strlen(c) + 1];
    std::strcpy(data, c);
    value = data;
}

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    os << s.value;
    return os;
}

bool Str::operator==(const Str &rhs) const
{
    return std::strcmp(value, rhs.value);
}

int main()
{
    Str s = "123";
    std::cout << s.size();
    if (s) //==if(s.operator bool())
    {
        std::cout << s[1];
        std::cout << s;
    }
    
}