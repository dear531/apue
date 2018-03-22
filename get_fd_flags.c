#if 0
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out 0 < 1.txt 
O_RDONLY
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out 1 > tmp.txt 
zhangly@ubuntu:/mnt/data/gitstorage/apue$ cat tmp.txt 
O_WRONLY
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out 2 2>>tmp.txt 
O_WRONLYO_APPEND
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out 5 5<>tmp.txt
O_RDWR
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int val = 0;
	if (argc != 2) {
		fprintf(stdout, "usage : ./a.out FILE_NUMBER\n");
		exit(EXIT_FAILURE);
	}
	if (-1 == (val = fcntl(atoi(argv[1]), F_GETFL))) {
		fprintf(stderr, "fcntl error :%m\n");
		exit(EXIT_FAILURE);
	}
	switch (val & O_ACCMODE) {
		case O_RDONLY:
			fprintf(stdout, "O_RDONLY");
			break;
		case O_WRONLY:
			fprintf(stdout, "O_WRONLY");
			break;
		case O_RDWR:
			fprintf(stdout, "O_RDWR");
			break;
		defalute:
			fprintf(stderr, "unknown access mode");
	}
	if (val & O_APPEND)
		fprintf(stdout, "O_APPEND");
	if (val & O_NONBLOCK)
		fprintf(stdout, "O_NONBLOCK");
#ifdef O_SYNC
	if (val & O_SYNC)
		fprintf(stdout, "O_SYNC");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if (val & O_FSYNC)
		fprintf(stdout, "O_FSYNC");
#endif
	putchar('\n');	
	return 0;
}
