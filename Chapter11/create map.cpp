#include <iostream>
#include <string>
#include <map>
#include <iomanip>

int main()
{   
    std::map<std::string,int> name_age{{"Tom",16},{"Jeff",17},{"Faker",23},{"UZI",22},{"Rookie",22}};
    name_age["xiaohu"]=20;
    for(auto i:name_age)
    {
        std::cout<<i.first<<" is "<<i.second<<" years old.\n";
    }
    std::cout<<std::endl;
    
    std::map<std::pair<int,int>,int> sparse_matrix{{{1,5},3},{{2,1},88},{{1,3},66},{{7,1},3},{{5,6},4}};
    for(int i=1;i!=8;i++)
    {
        std::cout<<"|";
        for(int j=1;j!=7;j++)
        {
            auto iter=sparse_matrix.find({i,j});
            std::cout<<std::setw(2)<<std::left;
            if(iter==sparse_matrix.end())
            {
                std::cout<<0<<" ";
            }
            else
            {
                std::cout<<iter->second<<" ";
            }
            
        }
        std::cout<<"|"<<std::endl;
    }
}