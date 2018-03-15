#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#if 1
static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);
#else
#endif

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: a.out <dirname>\n");
		exit(EXIT_FAILURE);
	}
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n", ARG_AMX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("_SC_ARG_MAX = ", _SC_ARG_MAX);
#else
	fprintf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef MAX_CANON
	printf("MAX_CANON defined to be %d\n", MAX_CANON+0);
#else
	printf("no symbol for MAX_CANON\n");
#endif
#ifdef _PC_MAX_CANON
	pr_pathconf("_PC_MAX_CANON = ", argv[1], _PC_MAX_CANON);
#else
	printf("no symbol for _PC_MAX_CANON\n");
#endif
	return 0;
}

static void pr_sysconf(char *mesg, int name)
{
	long	val;
	fputs(mesg, stdout);
	errno = 0;
	if ((val = sysconf(name)) < 0 && errno == EINVAL) {
		fputs(" (not supported)\n", stdout);
	} else if (val < 0 && errno != 0) {
		fprintf(stderr, "sysconf error\n");
		exit(EXIT_FAILURE);
	} else if (val < 0) {
		fputs(" (no limit )\n", stdout);
	} else {
		fprintf(stdout, "%ld\n", val);
	}
}
#if 1
static void pr_pathconf(char *mesg, char *path, int name)
{
	long	val;
	fputs(mesg, stdout);
	errno = 0;
	if ((val = pathconf(path, name)) < 0 && errno == EINVAL) {
		fputs(" (not supported)\n", stdout);
	} else if (val < 0 && errno != 0) {
		fprintf(stderr, "pathconf error, path = %s\n", path);
		exit(EXIT_FAILURE);
	} else if (val < 0) {
		fputs("(no limit)\n", stdout);
	} else {
		printf(" %ld\n", val);
	}
}
#endif
