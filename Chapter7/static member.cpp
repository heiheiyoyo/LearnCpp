#include <iostream>
#include <string>

namespace MyProgram {
    class MyClass {
        public:
        static void Main()
        {
            std::cout<<status<<std::endl;
        }
        private:
        static int status;
        static int initstatus();

    };
};

int MyProgram::MyClass::initstatus()
{
    return 0;
}

int MyProgram::MyClass::status=initstatus();

int main()
{
    MyProgram::MyClass::Main();
}
