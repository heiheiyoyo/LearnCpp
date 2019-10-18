#include<iostream>
#include<string>
using std::cin;

void show_status(std::istream& is)
{
    std::cout<<std::string(15,'-')+"\n"+
    "Status: eof: "<<is.eof()<<
    "\n        fail: "<<is.fail()<<
    "\n        bad: "<<is.bad()<<
    "\n        good: "<<is.good()<<"\n"<<
    std::string(15,'-')<<std::endl;
}

int main()
{
    show_status(cin);
    int i;
    while(cin>>i)
    {
        std::cout<<"OK\ni="<<i<<std::endl;
    }
    show_status(cin);
}