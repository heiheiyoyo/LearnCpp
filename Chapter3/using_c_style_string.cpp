#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <typeinfo>


int main()
{
  char ca1[]{"Apple"};
  char ca2[]{"Banana"};
  auto ca3len=std::strlen(ca1)+std::strlen(ca2)+2;
  auto ca3=new char[ca3len];
  std::strcpy(ca3,ca1);
  std::strcat(ca3," ");
  std::strcat(ca3,ca2);
  //std::cout<<ca3;
  for(auto i :ca2)
  {
    std::cout<<i;
  }
  //std::cout<<typeid(ca3).name()<<std::endl;

}