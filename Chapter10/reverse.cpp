#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <locale>

int main()
{
    std::ostream_iterator<char> out(std::cout);
    std::string s{"Hello,world!"};
    std::reverse_copy(s.begin(),s.end(),out);
    std::cout<<std::endl;
    
    setlocale(LC_ALL, "");
    std::ostream_iterator<wchar_t,wchar_t> wout(std::wcout);
    std::wstring s2{L"宁静致远"};
    std::reverse_copy(s2.begin(),s2.end(),wout);

}