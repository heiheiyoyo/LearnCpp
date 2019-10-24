#include <unistd.h>
#include <cstdlib>

int main()
{
	if((write(1,"Hello,world\n",12))!=12)
		write(2,"error\n",6);
	exit(0);
}
