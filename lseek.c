#if 0
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out < /etc/motd 
lseek OK
zhangly@ubuntu:/mnt/data/gitstorage/apue$ cat /etc/motd |./a.out 
can not lseek :Illegal seek
#endif
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (-1 == lseek(STDIN_FILENO, 0, SEEK_CUR))
		fprintf(stderr, "can not lseek :%m\n");
	else
		fprintf(stdout, "lseek OK\n");
	return 0;
}
