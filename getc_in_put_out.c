#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c = 0;
	int i = 0, pr = 0;
	while (10 > i)
	{
		c = getc(stdin);
		if (c == EOF && 0 != feof(stdin)) {
			fprintf(stdout, "stdin close\n");
			exit(EXIT_SUCCESS);
		} else if (c == EOF) {
			fprintf(stderr, "get stdin error\n");
			exit(EXIT_FAILURE);
		} else if (c != EOF && EOF == (pr = putc(c, stdout))) {
			fprintf(stderr, "put error %m\n");
			exit(EXIT_FAILURE);
		} else if (c != EOF && EOF != pr) {
			i++;
		}
	}
	return 0;
}
