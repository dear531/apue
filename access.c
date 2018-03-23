#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc != 2)
	{
		fprintf(stderr, "usage: a.out <pathname>\n");
		exit(EXIT_FAILURE);
	}
	struct acc {
		int mode;
		char *name;
	} acc[] = {
		{R_OK, "read",},
		{W_OK, "write",},
		{X_OK, "preform",},
		{F_OK, "existence",},
	};

	for (i = 0; sizeof(acc) / sizeof(*acc) > i; i++)
	{
		if (access(argv[1], acc[i].mode) == -1 && errno == EACCES) {
			fprintf(stdout, "%s acc bad\n",
					acc[i].name);
		} else if (access(argv[1], acc[i].mode) == -1 && errno != EACCES) {
			fprintf(stderr, "acc error :%m for %s\n",
					argv[1]);
		} else {
			fprintf(stdout, "%s acc ok\n",
					acc[i].name);
		}
	}

	return 0;
}
