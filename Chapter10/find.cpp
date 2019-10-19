#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> vec{1,2,8,64,89,21,44};
    auto result=std::find(vec.begin(),vec.end(),89);  //find in algorithm
    if(result!=vec.end())
    {
        std::cout<<"Position: "<<result-vec.begin();
    }

    //it can also be used on array
    const char str[]{"Hello,world"};
    auto cptr=std::find(std::begin(str),std::end(str),'w');
    std::cout<<"\nChar Index: "<<(cptr-str)<<std::endl;
}