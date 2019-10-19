#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

int main()
{
    std::vector<int> vec;
    auto insert_iter=std::back_inserter(vec);
    *insert_iter=42;
    *insert_iter=-45;
    std::fill_n(insert_iter,5,6);
    *insert_iter=1;
    std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<std::ends;});

    std::vector<int> positive;
    std::vector<int> data{654,-565,598,8,-47,0,58,-8,-9,47,-995};
    std::transform(data.begin(),data.end(),std::back_inserter(positive),[](int i){return i>0;});
    std::cout<<"PosNum: "<<std::accumulate(positive.begin(),positive.end(),0)<<std::endl;

}