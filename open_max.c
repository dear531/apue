#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#if 0
#ifdef OPEN_MAX
static long open_max_flag = OPEN_MAX;
#else
static long open_max_flag = 0;
#endif
#define OPEN_MAX_GUESS 256

long open_max(void)
{
	long open_max = 0;
	open_max = open_max_flag;
	if (0 == open_max_flag && 0 > (open_max = sysconf(_SC_OPEN_MAX)) && 0 == errno) {
		open_max = OPEN_MAX_GUESS;
	} else if (0 == open_max_flag && 0 > open_max && 0 != errno) {
		fprintf(stderr, "sysconf error :%m\n");
		exit(EXIT_FAILURE);
	}
	return open_max;
}
#else
#define OPEN_MAX_GUESS 256
long open_max(void)
{
	long open_max = 0;
#ifdef OPEN_MAX
	open_max = OPEN_MAX;
#else
	if (0 > (open_max = sysconf(_SC_OPEN_MAX)) && 0 == errno) {
		open_max = OPEN_MAX_GUESS;
	} else if (0 > open_max && 0 != errno) {
		fprintf(stderr, "sysconf error :%m\n");
		exit(EXIT_FAILURE);
	}
#endif
	return open_max;
}
#endif

int main(void)
{
	printf("open_max:%ld\n", open_max());
	return 0;
}
