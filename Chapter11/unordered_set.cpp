#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

int main()
{

    std::unordered_set<std::string> us{"Hello","World","Anna","John","Faker","Google","Microsoft","Apple"};
    us.insert("Test");
    us.insert("Hello");

    //Show Content
    std::cout<<"Content: ";
    std::for_each(us.begin(),us.end(),[](const std::string &i){std::cout<<i<<" ";});

    //Show Status
    std::cout<<"\n\n"<<std::string(10,'-')<<"Status"<<std::string(10,'-')<<"\n";
    std::cout<<"bucket_count:"<<us.bucket_count()<<"\n";
    std::cout<<"max_bucket_count:"<<us.max_bucket_count()<<"\n";
    std::cout<<"load_factor:"<<us.load_factor()<<"\n";
    std::cout<<"max_load_factor:"<<us.max_load_factor()<<"\n";

    //Show Bucker Status
    std::cout<<"\n-----Bucket Stauts-----\n";
    for(int i=0;i!=us.bucket_count();++i)
    {
        std::cout<<"Bucket "<<i<<" :\n";
        std::cout<<"    Size: "<<us.bucket_size(i)<<"\n    Content: ";
        std::for_each(us.begin(i),us.end(i),[](const std::string &i){std::cout<<i<<" ";});
        std::cout<<"\n";
    }
}