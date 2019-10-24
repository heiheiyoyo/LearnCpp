#include <iostream>
#include <memory>
#include <string>
int main()
{
	auto p=std::make_shared<std::string>("Hello");
	auto q=p;
	if(!p.unique())
		p.reset(new std::string(*p));
	*p+=",world!";
	std::cout<<"q: "<<*q<<std::endl;
	std::cout<<"p: "<<*p<<std::endl;


    
}
