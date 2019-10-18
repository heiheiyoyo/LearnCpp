#include <iostream>

using namespace std;

void show_bits(std::istream& is)
{
    std::cout<<std::hex<<string(15,'-')<<"\n"<<
    "rdstate： "<<is.rdstate()<<"\n"<<
    "failbit: "<<is.failbit<<"\n"<<
    "badbit: "<<is.badbit<<"\n"<<
    "eofbit: "<<is.eofbit<<"\n"<<
    "goodbit: "<<is.goodbit<<"\n"<<
    string(15,'-')<<std::endl;
}

int main()
{
    show_bits(cin);
    int i=0;
    while(cin>>i)
    {
        std::cout<<"OK"<<std::endl;
    }
    show_bits(cin);
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit); //clear failbit and badbit
}