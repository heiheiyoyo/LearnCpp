#include<iostream>
#include<vector>
int main()
{
    std::vector<int> vec;
    std::cout<<vec.capacity()<<std::ends;
    vec.push_back(1);
    //vec.reserve(5);
    std::cout<<vec.capacity()<<std::ends;
    vec.push_back(2);
    std::cout<<vec.capacity()<<std::ends;
    for(int i=0;i!=10;++i)
    {
        vec.push_back(i+2);
    }
    std::cout<<vec.capacity()<<std::ends;
}