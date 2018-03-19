#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static int pathmax_tmp = PATH_MAX;
#else
static int pathmax_tmp = 0;
#endif

#define SUSV3	200112L

static long posix_version = 0;
#define PATH_MAX_GUESS	1024

char *path_alloc(int *sizep)
{
	char *ptr	= NULL;
	int size	= 0;
	int pathmax	= 0;
	pathmax		= pathmax_tmp;
	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);
	printf("posix_version :%ld\n", posix_version);
	errno = 0;
	if (pathmax_tmp == 0 && (pathmax = pathconf("/", _PC_PATH_MAX)) < 0 && errno == 0) {
		pathmax = PATH_MAX_GUESS;
	} else if (pathmax_tmp == 0 && pathmax < 0 && errno != 0) {
		fprintf(stderr, "pathconf error %m\n");
		exit(EXIT_FAILURE);
	} else if (pathmax_tmp == 0 && pathmax > 0) {
		pathmax++;
	}

	if (posix_version < SUSV3) {
		size = pathmax + 1;
	} else {
		size = pathmax;
	}
	if ((ptr = malloc(size)) == NULL) {
		fprintf(stderr, "malloc error :%m\n");
		exit(EXIT_FAILURE);
	}
	if (sizep != NULL) {
		*sizep = size;
	}
	return (ptr);
}

int main(void)
{
#ifdef PATH_MAX
	printf("PATH_MAX :%d\n", PATH_MAX);
#else
	printf("PATH_MAX is not defined\n");
#endif
	int size = 0;
	char *path = NULL;
	path = path_alloc(&size);
	fprintf(stdout, "path %p, size %d\n",
			path, size);
	return 0;
}
