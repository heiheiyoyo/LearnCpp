#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char c;
	int in;

	in=open("read.cpp",O_RDONLY);
	write(1,"-----read.cpp-----\n",19);
	while(read(in,&c,1)==1)
		write(1,&c,1);
	write(1,"------------------\n",19);
	if(close(in)==0)
		write(1,"Close complete\n",15);
	exit(0);
}
