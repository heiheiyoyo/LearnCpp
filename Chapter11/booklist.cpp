#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <set>

int main()
{
    std::ifstream booklist_read("booklist.txt");
    //std::istream_iterator<std::string> in(booklist_read),eof;
    //std::set<std::string> booklist(in,eof);
    std::set<std::string> booklist;
    std::string bookname_in;
    while (std::getline(booklist_read, bookname_in))
    {
        if (!bookname_in.empty())
        {
            booklist.insert(bookname_in);
        }
    }
    booklist_read.close();
    
    if (!booklist.empty())
    {
        std::cout << "Book List:\n";
        for (const auto &i : booklist)
        {
            std::cout << i << "\n";
        }
    }

    std::cout << "Add more books? (y/N)" << std::endl;
    if (std::cin.get() == 'y')
    {
        std::cout << "\nInput bookname:\n";
        std::string bookname;
        while (std::getline(std::cin, bookname))
        {
            if (!bookname.empty())
            {
                booklist.insert(bookname);
            }
        }
    }
    std::ofstream booklist_write("booklist.txt");
    for (const auto &i : booklist)
    {
        booklist_write << i << "\n";
    }
}