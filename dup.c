#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int fd1 = -1, fd2 = -1;
	if (-1 == (fd1 = open("dup.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR))) {
		fprintf(stdout, "open error :%m\n");
		exit(EXIT_FAILURE);
	}
#if 1
	fd2 = 10;
	if (-1 == fcntl(fd1, F_DUPFD, fd2))
	{
		fprintf(stderr, "fcntl error %m\n");
		exit(EXIT_FAILURE);
	}
#else
	fd2 = dup(fd1);
	if (-1 == fd2) {
		fprintf(stderr, "dup error :%m\n");
		exit(EXIT_FAILURE);
	}
#endif
	fprintf(stdout, "fd1 :%d, fd2 :%d\n", fd1, fd2);
	if (-1 == write(fd1, "1", strlen("1"))) {
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}
	if (-1 == write(fd2, "2", strlen("2"))) {
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}
#if 1	/* fsync func test */
	if (-1 == fsync(fd1)) {
		fprintf(stderr, "fsync error :%m\n");
		exit(EXIT_FAILURE);
	}
#endif
	system("cat dup.txt");
	if (-1 == fd1) {
		close(fd1);
		fd1 = -1;
	}
	return 0;
}

