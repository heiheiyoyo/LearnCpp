#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main()
{
    std::stack<int,std::vector<int>> istack{std::vector<int>{1,2,3}};
    std::string s="Hello,world!";
    std::stack<char,std::string> cstack{s};
    for(std::vector<int>::size_type i=0,s=istack.size();i!=s;++i)
    {
        std::cout<<istack.top()<<std::ends;
        istack.pop();
    }
    for(decltype(cstack.size()) i=0,s=cstack.size();i!=s;++i)
    {
        std::cout<<cstack.top();
        cstack.pop();
    }
    return 0;
}