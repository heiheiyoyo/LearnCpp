#include <string>

class StringPtr
{
public:
    StringPtr(const std::string &s = std::string())
        : ps(new std::string(s)), use(new std::size_t(1)) {}
    StringPtr(const StringPtr &p)
        : ps(p.ps), use(p.use) { ++*use; }
    StringPtr& operator=(const StringPtr&);

private:
    std::string *ps;
    std::size_t *use;
};

StringPtr& StringPtr::operator=(const StringPtr& rhs)
{
    ++*rhs.use;
    if((--*use)==0)
    {
        delete ps;
        delete use;
    }
    ps=rhs.ps;
    use=rhs.use;
    return *this;
}