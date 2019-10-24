#include "TextQuery.h"
#include "QueryResult.h"

int main()
{
    std::string filename;
    std::cout << "Input file name: ";
    if (std::cin >> filename)
    {

        std::ifstream ifs(filename);
        if (ifs)
        {
            TextQuery textQuery(ifs);
            std::cout << "Query: ";
            std::string q;
            std::cin >> q;
            auto result = textQuery.query(q);
            std::cout << result << std::endl;
            return 0;
        }
        else
        {
            std::cerr << "file error!" << std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Input error!" << std::endl;
        return -1;
    }
}