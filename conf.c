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

void show_sys_max_value(void)
{
	printf("show sys max value\n");
#ifdef CHAR_BIT
	printf("CHAR_BIT:%d\n", CHAR_BIT);
#else
	printf("CHAR_BIT is not defined\n");
#endif
#ifdef CHAR_MAX
	printf("CHAR_MAX :%d\n", CHAR_MAX);
#else
	printf("CHAR_MAX is not defined\n");
#endif

#ifdef SCHAR_MAX
	printf("SCHAR_MAX :%d\n", SCHAR_MAX);
#else
	printf("SCHAR_MAX is not defined\n");
#endif

#ifdef SCHAR_MIX
	printf("SCHAR_MIX :%d\n", SCHAR_MIX);
#else
	printf("SCHAR_MIX is not defined\n");
#endif
#ifdef UCHAR_MAX
	printf("UCHAR_MAX:%d\n", UCHAR_MAX);
#else
	printf("UCHAR_MAX is not defined\n");
#endif
#ifdef UCHAR_MIN
	printf("UCHAR_MIN :%d\n", UCHAR_MIN);
#else
	printf("UCHAR_MIN is not defined\n");
#endif
#ifdef MB_LEN_MAX
	printf("MB_LEN_MAX :%d\n", MB_LEN_MAX);
#else
	printf("MB_LEN_MAX is not defined\n");
#endif
#ifdef ULLONG_MAX
	printf("ULLONG_MAX :\t%llu\n", ULLONG_MAX);
#else
	printf("ULLONG_MAX is not defined\n");
#endif
#ifdef LLONG_MAX
	printf("LLONG_MAX :\t%lld\n", LLONG_MAX);
#else
	printf("LLONG_MAX is not defined\n");
#endif
#ifdef FOPEN_MAX
	printf("FOPEN_MAX :%d\n", FOPEN_MAX);
#else
	printf("FOPEN_MAX is not defined\n");
#endif
#ifdef TMP_MAX
	printf("TMP_MAX :%d\n", TMP_MAX);
#else
	printf("TMP_MAX is not defined\n");
#endif
	printf("=========\n");
}

void show_posix_value(void)
{
	printf("show posix value\n");
#ifdef _POSIX_CHILD_MAX
	printf("_POSIX_CHILD_MAX defined to be %d\n", _POSIX_CHILD_MAX);
#else
	printf("_POSIX_CHILD_MAX is not defined\n");
#endif
	printf("=========\n");
#ifdef SSIZE_MAX
	printf("SSIZE_MAX :%ld\n", SSIZE_MAX);
#else
	printf("SSIZE_MAX is not defined\n");
#endif
#ifdef _POSIX_LINK_MAX
	printf("_POSIX_LINK_MAX :%d\n", _POSIX_LINK_MAX);
#else
	printf("_POSIX_LINK_MAX is not defined\n");
#endif
#ifdef _POSIX_HOST_NAME_MAX
	printf("_POSIX_HOST_NAME_MAX :%d\n", _POSIX_HOST_NAME_MAX);
#else
	printf("_POSIX_HOST_NAME_MAX is not defined\n");
#endif
#ifdef _POSIX_PATH_MAX
	printf("_POSIX_PATH_MAX :%d\n", _POSIX_PATH_MAX);
#else
	printf("_POSIX_PATH_MAX is not defined\n");
#endif
#ifdef _POSIX_NGROUPS_MAX
	printf("_POSIX_NGROUPS_MAX :%d\n", _POSIX_NGROUPS_MAX);
#else
	printf("_POSIX_NGROUPS_MAX is not defined\n");
#endif
#ifdef _POSIX_OPEN_MAX
	printf("_POSIX_OPEN_MAX :%d\n", _POSIX_OPEN_MAX);
#else
	printf("_POSIX_OPEN_MAX is not defined\n");
#endif

#ifdef _POSIX_PIPE_BUF
	printf("_POSIX_PIPE_BUF :%d\n", _POSIX_PIPE_BUF);
#else
	printf("_POSIX_PIPE_BUF is not defined\n");
#endif

#ifdef _POSIX_STREAM_MAX
	printf("_POSIX_STREAM_MAX :%d\n", _POSIX_STREAM_MAX);
#else
	printf("_POSIX_STREAM_MAX is not defined\n");
#endif
}


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

	show_sys_max_value();
	show_posix_value();
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
