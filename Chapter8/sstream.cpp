#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
    
};


int main()
{
    std::cout<<"Input Information (name phonenumber phonenumber ...)\n"
    "e.g. Tom 110 119"<<std::endl;
    std::string line, word;
    std::vector<PersonInfo> people;
    while(std::getline(std::cin,line)) {
        PersonInfo info;
        std::istringstream record(line);
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    std::ostringstream oss;
    for(auto p:people)
    {
        oss<<"Name: "<<p.name<<"\n"<<"Phonenumber:";
        for(auto n:p.phones)
        {
            oss<<" "<<n;
        }
        oss<<std::endl;
    }
    std::cout<<oss.str()<<std::endl;
}