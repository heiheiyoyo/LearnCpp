#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char buffer[128]{0};
	mkdir("test-dir",S_IRUSR|S_IWUSR|S_IXUSR);
	write(1,"Workspace:",10);
	getcwd(buffer,128);
	write(1,buffer,128);
	write(1,"\n",1);
	rmdir("test-dir");
}
