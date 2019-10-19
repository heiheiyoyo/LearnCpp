#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

int main()
{
    std::cout<<"Sum numbers (Ctrl + Z to eof): "<<std::endl;
    std::istream_iterator<int> in_iter(std::cin),eof;
    std::vector<int> vec(in_iter,eof);
    std::for_each(vec.begin(),vec.end()-1,[](int i){std::cout<<i<<"+";});
    std::cout<<*(vec.end()-1)<<"="<<std::accumulate(vec.begin(),vec.end(),0)<<std::endl;
    
}