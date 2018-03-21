#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	char wbuff[] = "12345", rbuff[10] = {0}, wbuff2[] = "67890";
	int fd = -1, n = 0;
	off_t len = 0;
	if (-1 == (fd = open("lseek.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR))) {
		fprintf(stderr, "open error :%m\n");
		exit(EXIT_FAILURE);
	}
#if 0
	if (-1 == (n = write(fd, wbuff, strlen(wbuff))))
#else
	if (-1 == (n = pwrite(fd, wbuff, strlen(wbuff), 0)))
#endif
	{
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}
	system("cat lseek.txt");
	if (-1 == (n = write(fd, wbuff2, strlen(wbuff2))))
	{
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	system("cat lseek.txt");
	if (-1 == (len = lseek(fd, 0, SEEK_CUR)))
	{
		fprintf(stderr, "lseek error :%m\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	fprintf(stdout, "len: %ld\n", len);
	if (-1 != fd) {
		close(fd);
		fd = -1;
	}
}
