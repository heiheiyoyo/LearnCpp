#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> int_list{1, 2, 44, 12, 58, 79, 41, 66, 91, 35};
    //show the elements in int_list
    for(auto &i:int_list)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    //delete elements which are bigger than 50
    for (auto b = int_list.begin(); b != int_list.end();)  //don't save int_list.end()， it may be changed
    {
        if (*b > 50)
        {
            b=int_list.erase(b);
        }
        else
        {
            ++b;
        }
    }

    for(auto &i:int_list)
    {
        std::cout<<i<<" ";
    }
}