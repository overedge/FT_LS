#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	struct stat infos;
 	if (lstat(argv[1], &infos) != 0)
		perror("");
}
