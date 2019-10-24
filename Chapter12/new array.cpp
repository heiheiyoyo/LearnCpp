#include <iostream>
#include <memory>

int main()
{
    int *pi=new int[100];
    delete[] pi;
    std::unique_ptr<char[]> buffer(new char[128]);
    buffer.release();
    std::shared_ptr<int> sp(new int[10],[](int *p){delete[] p;});
    sp.reset();
}