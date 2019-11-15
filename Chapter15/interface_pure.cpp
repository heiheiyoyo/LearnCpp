#include <iostream>
#include <vector>
#include <cstring>

#define interface class

template <typename T>
interface IList
{
public:
    virtual std::vector<T> get()=0;
    IList()=default;
    IList(const IList&)=default;
    IList& operator=(const IList&)=default;
    IList(IList&&)=default;
    IList& operator=(IList&&)=default;
    virtual ~IList()=default;
};

class Mystring final:public IList<char>
{
public:
    Mystring();
    ~Mystring();
    std::vector<char> get() override;
private:
    char *content;
    std::size_t len;
};

Mystring::Mystring()
:len(14)
{
    auto p=new char[14];
    std::strcpy(p,"Hello,world!\n");
    content=p;

}

Mystring::~Mystring()
{
    delete [] content;
}

std::vector<char> Mystring::get()
{
    return std::vector<char>(content,content+14);
}

int main()
{
    Mystring a;
    IList<char> *list=&a;
    auto vec=list->get();
    for(auto &i:vec)
    {
        std::cout<<i;
    }
}