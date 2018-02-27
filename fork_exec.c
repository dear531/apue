#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buff[1024] = {0};
	while (1)
	{
#if 0
char *fgets(char *s, int size, FILE *stream);
#endif
		fprintf(stdout, "%%");
		if (NULL == fgets(buff, sizeof(buff), stdin))
		{
			fprintf(stdout, "stodin close\n");
			exit(EXIT_SUCCESS);
		}

		if ('\n' == buff[strlen(buff) - 1])
		{
			buff[strlen(buff) - 1] = 0;
		}

		pid_t pid = 0;
		pid = fork();
		if (0 > pid)
		{
			fprintf(stderr, "fork error :%m\n");
			exit(EXIT_FAILURE);
		}
		else if (0 == pid)
		{
			execlp(buff, buff, NULL);
			exit(EXIT_SUCCESS);
		}
		wait(NULL);
	}
	return 0;
}
