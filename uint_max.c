#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	fprintf(stdout, "INT_MAX:\t%d\n", INT_MAX);
	fprintf(stdout, "UINT_MAX:\t%u\n", UINT_MAX);
	fprintf(stdout, "0xffffffff:\t%u\n", 0xffffffff);
	fprintf(stdout, "_POSIX_PATH_MAX:\t%d\n", _POSIX_PATH_MAX);
	fprintf(stdout, "PATH_MAX:\t%d\n", PATH_MAX);
	fprintf(stdout, "_POSIX_NAME_MAX:\t%d\n", _POSIX_NAME_MAX);
	fprintf(stdout, "NAME_MAX:\t%d\n", NAME_MAX);
	fprintf(stdout, "_POSIX_PATH_MAX:\t%d\n", _POSIX_PATH_MAX);
	fprintf(stdout, "PATH_MAX:\t%d\n", PATH_MAX);
	return 0;
}
