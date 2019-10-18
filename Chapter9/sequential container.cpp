#include <iostream>
#include <string>
#include <vector>
#include <array>

int main()
{
    //use a vector initialize an another vector
    std::vector<int> ivec={1,2,3,4,5};
    auto c2=ivec;
    for(auto i:c2){std::cout<<i;}
    std::cout<<"\n"<<std::string(15,'-')<<std::endl;
    
    //use swap
    ivec={1,2,3};
    ivec.swap(c2);
    for(auto i:c2){std::cout<<i;}
    std::cout<<"\n"<<std::string(15,'-')<<std::endl;

    //string also support swap
    std::string s1{"Hello"},s2{"World"};
    s1.swap(s2);
    std::cout<<s1<<"-"<<s2<<"\n"<<std::string(15,'=')<<std::endl;
    
    //use assign
    std::array<int,10> ar= {1,2,3,4,5};
    c2.assign(ar.cbegin(),ar.cend());
    for(auto i:c2){std::cout<<i;}
    std::cout<<"\n"<<std::string(15,'-')<<std::endl;
    
    //use insert
    auto iter=c2.end()-1;
    c2.insert(iter,1);
    for(auto i:c2){std::cout<<i;}
    std::cout<<"\n"<<std::string(15,'-')<<std::endl;

    //access to elements
    std::cout<<*c2.begin()<<"=="<<c2.front()<<" "<<*(c2.end()-1)<<"=="<<c2.back()<<std::endl;

    

}