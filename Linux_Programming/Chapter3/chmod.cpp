#include <unistd.h>
#include <sys/stat.h>

int main()
{
	chmod("open.o",S_IRUSR|S_IXUSR|S_IWUSR);
}
