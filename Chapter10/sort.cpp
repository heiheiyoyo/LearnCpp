#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>

int main()
{
    clock_t start,stop;
    std::ifstream nums("nums.txt");
    std::string s;

    std::istream_iterator<int> in_iter(nums),eof;
    {
    std::vector<int> ivec(in_iter,eof);
    nums.close();

    start=clock();
    std::sort(ivec.begin(),ivec.end());
    stop=clock();
    auto time1=(double)(stop=start)/CLOCKS_PER_SEC;
    
    std::cout<<"Vector Time Cost: "<<time1<<"s\n";
    }
    nums.open("nums.txt");
    std::istream_iterator<int> in_iter2(nums);
    std::list<int> ilist(in_iter2,eof);
    nums.close();



    start=clock();
    ilist.sort();
    stop=clock();
    auto time2=(double)(stop=start)/CLOCKS_PER_SEC;

    
    
    std::cout<<"List Time Cost: "<<time2<<"s"<<std::endl;
    //Vector Time Cost: 34.363s RAM Cost:591MB
    //List Time Cost: 147.416s RAM cost:4756MB
    
    
}