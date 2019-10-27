#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

int main()
{
    std::plus<int> intAdd;
    std::negate<int> intNegate;
    int sum=intAdd(1,2);
    sum=intNegate(sum);

    std::string s{"Hello"};
    std::sort(s.begin(),s.end());
    std::cout<<s;
    std::sort(s.begin(),s.end(),std::greater<char>());
    std::cout<<s;

    std::map<std::string,int(*)(int,int)> binopsv1{{"+",[](int i,int j){return i+j;}}};
    std::map<std::string,std::function<int(int,int)>> binopsv2{{"+",std::plus<int>()},{"-",std::minus<int>()}};
    binopsv1["+"](1,2);
    binopsv2["+"](1,2);
}