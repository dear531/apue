#if 0
zhangly@ubuntu:/mnt/data/gitstorage/apue$ hexdump -c file.hole 
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0
\0  \0
0000010  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
\0  \0
*
0004000   A   B   C   D   E   F   G   H   I   J                        
000400a
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";
	int fd = -1;
	if (-1 == (fd = creat("file.hole", S_IRUSR | S_IWUSR)))
	{
		fprintf(stderr, "creat error :%m\n");
		exit(EXIT_FAILURE);
	}

	if (-1 == write(fd, buf1, strlen(buf1)))
	{
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}

	if (-1 == lseek(fd, 16384, SEEK_SET))
	{
		fprintf(stderr, "lseek error :%m\n");
		exit(EXIT_FAILURE);
	}

	if (-1 == write(fd, buf2, strlen(buf2)))
	{
		fprintf(stderr, "write error :%m\n");
		exit(EXIT_FAILURE);
	}
	if (-1 != fd)
	{
		close(fd);
		fd = -1;
	}
	return 0;
}
