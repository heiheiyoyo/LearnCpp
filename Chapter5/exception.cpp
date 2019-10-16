#include<iostream>
#include<exception>

int main()
{
    try
    {
        int i,j;
        std::cin>>i>>j;
        if(j==0)
            throw std::logic_error("Can't divided by zero");
        std::cout<<i/j<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        int *a=new int[40073741824];
        for(long long i=0;i<40730741824;i++)
        {
            a[i]=i;
        }
        
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}