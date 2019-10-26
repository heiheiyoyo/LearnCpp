#include <iostream>
#include <string>
#include <vector>

class Strings
{
    friend std::ostream& operator<<(std::ostream&,const Strings&);
public:
    Strings()=default;
    Strings(const std::string& s) :container{s} {}
    Strings(const Strings& S) :container(S.container) {}
    Strings& operator=(const Strings& S)
    {
        container=S.container;
        return *this;
    }
    void push_back(const std::string&);
private:
    std::vector<std::string> container;
};

std::ostream& operator<<(std::ostream& os,const Strings& S)
{
    for(const auto &i:S.container)
    {
        os<<i<<std::endl;
    }
    return os;
}

void Strings::push_back(const std::string& s)
{
    container.push_back(s);
}

int main()
{
    Strings a("Hello");
    Strings b("World");
    std::cout<<a<<b;
    b=a;
    std::cout<<b;
}