#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buff[BUFSIZ] = {0};
	int i = 0, rn = 0, wn = 0;
	while (10 > i)
	{
		rn = read(STDIN_FILENO, buff, sizeof(buff));
		if (0 < rn && 0 < (wn = write(STDOUT_FILENO, buff, rn))) {
		}
		else if (0 < rn && 0 >= 0) {
			fprintf(stderr, "write problem\n");
			exit(EXIT_FAILURE);
		} else if (0 == rn) {
			fprintf(stderr, "stdin close\n");
			exit(EXIT_SUCCESS);
		} else if (0 > rn) {
			fprintf(stderr, "read stdin error %m\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return 0;
}
