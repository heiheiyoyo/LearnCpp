#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> process()
{
	return {"Process:","okay"}; // return initiation list
}

int main()
{
	std::vector<std::string> svec=process();
	for(auto i : svec)
	{
		std::cout<<i<<std::endl;
	}
	return 0;
}
