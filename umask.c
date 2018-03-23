#if 0
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out 
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ls /home/zhangly/tmp/umask*.txt -l
-rwxrwxrwx 1 zhangly zhangly 0  3月 23 17:33 /home/zhangly/tmp/umask1.txt
-rw-rw-rw- 1 zhangly zhangly 0  3月 23 17:33 /home/zhangly/tmp/umask2.txt
#endif
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#define rwrwrw (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
int main(void)
{
	umask(0);
	if (-1 == creat("/home/zhangly/tmp/umask1.txt", S_IRWXU | S_IRWXG | S_IRWXO))
	{
		fprintf(stderr, "create /home/zhangly/tmp/umask1.txt error :%m\n");
	}
	umask(S_IXUSR | S_IXGRP | S_IXOTH);
	if (-1 == creat("/home/zhangly/tmp/umask2.txt", S_IRWXU | S_IRWXG | S_IRWXO))
	{
		fprintf(stderr, "create /home/zhangly/tmp/umask1.txt error :%m\n");
	}
	return 0;
}
