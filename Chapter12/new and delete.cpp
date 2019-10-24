#include <iostream>
int main()
{
    int *pi =new int; //uninitialized
    int *pi2 = new int(); //initialized as 0
    int *pi3;
    try
    {
        pi3=new int[544644456485];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //pi3=nullptr;
    }
    std::cout<<"pi3: " <<pi3<<std::endl;
    int *pi4 = new (std::nothrow) int[544644456485];
    std::cout<<"pi4: "<<pi4<<std::endl;

    auto pi5=new auto(*pi);
    
    delete pi;
    delete pi2;
    delete[] pi4;
    delete pi5;
}