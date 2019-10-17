
#include <iostream>
#include <string>

struct Persion {
    std::string name;
    int age;
};

int main()
{
    Persion p1{"Anna",18};
    std::cout<<"Name: "<<p1.name<<"\nage: "<<p1.age<<std::endl;
}