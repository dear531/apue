#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <linux/limits.h>
#if 1
static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);
#else
#endif

int main(int argc, char *argv[])
{
#if 1
	char arg[] = "/";
#else
	if (argc != 2) {
		fprintf(stderr, "usage: a.out <dirname>\n");
		exit(EXIT_FAILURE);
	}
#endif

#ifdef _POSIX_CHILD_MAX
	printf("_POSIX_CHILD_MAX defined to be %d\n", _POSIX_CHILD_MAX);
#else
	printf("_POSIX_CHILD_MAX is not defined\n");
#endif
	printf("=========\n");
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n", ARG_AMX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("_SC_ARG_MAX = ", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
	printf("=========\n");
#ifdef MAX_CANON
	printf("MAX_CANON defined to be %d\n", MAX_CANON+0);
#else
 	printf("no symbol for MAX_CANON\n");
#endif
#ifdef _PC_MAX_CANON
#  if 0
	pr_pathconf("_PC_MAX_CANON = ", argv[1], _PC_MAX_CANON);
#  else
	pr_pathconf("_PC_MAX_CANON = ", arg, _PC_MAX_CANON);
#  endif
#else
	printf("no symbol for _PC_MAX_CANON\n");
#endif

	printf("=========\n");
#ifdef CHILD_MAX
	printf("CHILD_MAX %ld", CHILD_MAX);
#else
	printf("CHILD_MAX is not defined\n");
#endif
#ifdef _SC_CHILD_MAX
	pr_sysconf("_SC_CHILD_MAX = ", _SC_CHILD_MAX);
#else
	printf("_SC_CHILD_MAX not defined\n");
#endif
	printf("=========\n");
#ifdef HOST_NAME_MAX
	printf("HOST_NAME_MAX :%d\n", HOST_NAME_MAX);
#else
	printf("HOST_NAME_MAX is not defined\n");
#endif
#ifdef _SC_HOST_NAME_MAX
	pr_sysconf("_SC_HOST_NAME_MAX = ", _SC_HOST_NAME_MAX);
#else
	printf("_SC_HOST_NAME_MAX is not defined\n");
#endif
	printf("=========\n");

#ifdef LOGIN_NAME_MAX
	printf("LOGIN_NAME_MAX :%d\n", LOGIN_NAME_MAX);
#else
	printf("LOGIN_NAME_MAX is not defined\n");
#endif
#ifdef _SC_LOGIN_NAME_MAX
	pr_sysconf("_SC_LOGIN_NAME_MAX = ", _SC_LOGIN_NAME_MAX);
#else
	printf("_SC_LOGIN_NAME_MAX is not defined\n");
#endif
	printf("=========\n");
#ifdef _SC_CLK_TCK
	pr_sysconf("_SC_CLK_TCK = ", _SC_CLK_TCK);
#else
	printf("_SC_CLK_TCK is not defined\n");
#endif
	printf("=========\n");

#ifdef OPEN_MAX
	printf("OPEN_MAX :%d\n", OPEN_MAX);
#else
	printf("OPEN_MAX is not defined\n");
#endif
#ifdef _SC_OPEN_MAX
	pr_sysconf("_SC_OPEN_MAX = ", _SC_OPEN_MAX);
#else
	printf("_SC_OPEN_MAX is not defined\n");
#endif
	printf("=========\n");
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
		fputs(" (no difined limit )\n", stdout);
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
		fputs("(no defined limit)\n", stdout);
	} else {
		printf(" %ld\n", val);
	}
}
#endif
