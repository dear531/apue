#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	fprintf(stdout, "INT_MAX:\t%d\n", INT_MAX);
	fprintf(stdout, "UINT_MAX:\t%u\n", UINT_MAX);
	fprintf(stdout, "0xffffffff:\t%u\n", 0xffffffff);
	return 0;
}
