#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char buff[BUFSIZ] = {0};
	int rn = 0, wn = 0;
	int new_stdout = -1, new_stderr = -1;
	new_stdout = dup(STDOUT_FILENO);
	new_stderr = dup(STDERR_FILENO);
	while (1)
	{
		memset(buff, 0x00, strlen(buff));
		if (0 < (rn = read(STDIN_FILENO, buff, sizeof(buff)))
		&& 0 < (wn = write(STDOUT_FILENO, buff, rn))) {
			sleep(1);
			write(new_stdout, "read and write1\n", strlen("read and write1\n"));	
			continue;
		} else if (0 > rn) {
			fprintf(stderr, "read error :%m\n");
			exit(EXIT_FAILURE);
		} else if (0 > wn) {
			fprintf(stderr, "write error :%m\n");
			exit(EXIT_FAILURE);
		} else if (0 == rn) {
			fprintf(stdout, "end of file\n");
			break;
		}
	}
	close(new_stdout);
	close(new_stderr);
	return 0;
}
