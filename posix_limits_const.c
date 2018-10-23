#include <stdio.h>
#include <limits.h>

int main(void)
{
	struct limits {
		char *string;
		long long value;
	} limits[] = {
		{"_POSIX_ARG_MAX", _POSIX_ARG_MAX},
		{"_POSIX_CHILD_MAX", _POSIX_ARG_MAX},
		{"_POSIX_HOST_NAME_MAX", _POSIX_HOST_NAME_MAX},
		{"_POSIX_LINK_MAX", _POSIX_LINK_MAX},
		{"_POSIX_LOGIN_NAME_MAX", _POSIX_LOGIN_NAME_MAX},
		{"_POSIX_MAX_CANON", _POSIX_MAX_CANON},
		{"_POSIX_MAX_INPUT", _POSIX_MAX_INPUT},
		{"_POSIX_NAME_MAX", _POSIX_NAME_MAX},
		{"_POSIX_NGROUPS_MAX", _POSIX_NGROUPS_MAX},
		{"_POSIX_OPEN_MAX", _POSIX_OPEN_MAX},
		{"_POSIX_PATH_MAX", _POSIX_PATH_MAX},
		{"_POSIX_PIPE_BUF", _POSIX_PIPE_BUF},
		{"_POSIX_RE_DUP_MAX", _POSIX_RE_DUP_MAX},
		{"_POSIX_SSIZE_MAX", _POSIX_SSIZE_MAX},
		{"_POSIX_STREAM_MAX", _POSIX_STREAM_MAX},
		{"_POSIX_SYMLINK_MAX", _POSIX_SYMLINK_MAX},
		{"_POSIX_SYMLOOP_MAX", _POSIX_SYMLOOP_MAX},
		{"_POSIX_TTY_NAME_MAX", _POSIX_TTY_NAME_MAX},
		{"_POSIX_TZNAME_MAX", _POSIX_TZNAME_MAX},
	};

	int i = 0;

	for (i = 0; sizeof(limits) / sizeof(*limits) > i; i++) {
		fprintf(stdout, "%s\t:\t%lld\n",
			limits[i].string, limits[i].value);
	}

	return 0;
}
