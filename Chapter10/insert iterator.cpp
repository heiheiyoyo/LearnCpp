#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main()
{
    std::deque<int> dq{1,2,3};
    auto fiter=std::front_inserter(dq);
    *fiter=0;
    auto biter=std::back_inserter(dq);
    *biter=5;
    
    auto p=std::find(dq.begin(),dq.end(),5);
    auto iiter=std::inserter(dq,p);
    *iiter=4;
    
    std::for_each(dq.begin(),dq.end(),[](int i){std::cout<<i<<std::ends;});
}