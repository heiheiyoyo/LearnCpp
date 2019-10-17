//#define NDEBUG
#include<iostream>
#ifndef NDEBUG
	#include <cassert>
#endif

int main()
{
#ifndef NDEBUG
	std::cerr<<"File:"<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<std::endl<<"        Compiled on "<<__DATE__<<" at "<<__TIME__<<std::endl;
	assert(0);
#endif
	std::cout<<"not debug"<<std::endl;
}
	
