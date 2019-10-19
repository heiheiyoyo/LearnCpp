#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
    
    string s;
    auto newGetline=bind(static_cast<istream&(*)(istream&,string&)>(getline),ref(cin),_1);
    newGetline(s);

    auto printint=bind(static_cast<ostream& (ostream::*)(int)>(&ostream::operator<<), ref(cout), _1);
    auto print=bind(static_cast<ostream& (*)(ostream&,const string&)>(&operator<<),ref(cout), _1);
    print("You input: "+s+"\n");
    printint(0)<<endl;

    vector<string> svec{"Hello\n","World!\n"};
    for_each(svec.begin(),svec.end(),print);
    

}