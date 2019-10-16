#include <string>

int main()
{
    int k=0;
    //k={3.14}; Can't using double to initiate int variable value
    double d_value=0;
    d_value={3.14};
    std::string s1{"Hello,world"};
    auto s1ptr=&s1;
    auto n = s1.size();
    n = s1ptr->size();
    n = (*s1ptr).size();
    // can;t use *s1ptr.size()

    
}