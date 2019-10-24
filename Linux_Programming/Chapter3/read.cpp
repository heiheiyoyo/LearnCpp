#include <unistd.h>
#include <cstdlib>

int main()
{
	char buffer[128];
	int nread;
	nread = read(0,buffer,128);
	if(nread==-1)
		write(2,"read error\n",11);
	if(write(1,buffer,nread)!=nread)
		write(2,"write error\n",12);
	exit(0);
}

