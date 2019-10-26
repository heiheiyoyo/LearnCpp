#include <string>
#include <memory>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec &);            //拷贝构造函数
    StrVec &operator=(const StrVec &) &; //拷贝赋值运算符
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept ;
    ~StrVec();
    void push_back(const std::string &);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return first_free - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc; //分配元素

    //检查大小是否到达上限，被添加元素的函数使用
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();             //销毁元素并释放内存
    void reallocate();       //获得更多内存并移动已有元素
    std::string *elements;   //第一个元素的指针
    std::string *first_free; //指向第一个空闲元素
    std::string *cap;        //尾后指针
};

std::allocator<std::string> StrVec::alloc; //定义静态变量

StrVec::StrVec(std::initializer_list<std::string> init)
{
    if(init.size())
    {
        auto data=alloc.allocate(init.size());
        std::uninitialized_copy(init.begin(),init.end(),data);
        elements=data;
        first_free=cap=data+init.size();
    }
    else
    {
        elements=first_free=cap=nullptr;
    }
    
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free, s);
    first_free++;
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    //分配空间并获得指针
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    //如果elements为空，则什么都不做
    if (elements)
    {
        for (auto p = first_free; p != elements;/*空*/ )
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    //调用alloc_n_copy来分配空间
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) &
{
    //分配与rhs一样大的内存并拷贝
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //释放自身空间
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept
:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    s.elements=s.first_free=s.cap=nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if(this!=&rhs)
    {
        free();
        elements=rhs.elements;
        first_free=rhs.first_free;
        cap=rhs.cap;
        rhs.elements=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1; //分配两倍内存
    auto newdata = alloc.allocate(newcapacity);
    // auto dest = newdata; //复制的目标，指向新数组的元素
    // auto elem = elements; //复制的源，指向就数组的元素
    // for(std::size_t i=0;i!=size();++i)
    // {
    //     alloc.construct(dest++,std::move(*elem++));

    // }
    // free();
    auto dest = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()),
                                        newdata);
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}

#include <iostream>

int main()
{
    StrVec a{"1","2"};
    for(auto p=a.begin();p!=a.end();++p)
    {
        std::cout<<*p;
    }
}