#include <stdio.h>

int main(int argc, char *argv[])
{
	fprintf(stdout, "uid :%d, gid:%d\n", getuid(), getgid());
	return 0;
}
