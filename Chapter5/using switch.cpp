#include <iostream>
#include <boost/format.hpp>
#include <getopt.h>

void show_usage()
{
    std::cout << "Usage:\n"
                 "Sorry, the whole function is not completed\n";
}

int main(int argc, char *argv[])
{
    opterr = 0;
    int ch;
    while ((ch = getopt(argc, argv, "a::ehg")) != -1)
    {
        switch (ch)
        {
        case 'a':
            if (optarg != nullptr)
            {
                std::cout << boost::format("option a: %s\n") % optarg;
            }
            else
            {
                std::cout<<"option a has no parameter\n";
            }
            

            //printf("option a: ’%s’\n",optarg);
            break;
        case 'h':
            show_usage();
            break;
        case 'e':case 'g':
            std::cout<<"option e and g are the same\n";
            break;
        case '?':
            std::cout << boost::format("Unknown option: %c\n") % (char)optopt;
            //printf("Unknown option: %c\n", optopt);
            break;
        }
    }
}