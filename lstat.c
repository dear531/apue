#if 0
zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out /etc/tty
/dev/log /dev/console link_1.txt 
lstat /etc/tty
/etc/tty unknown file type
/dev/log S_ISSOCK
/dev/console S_ISCHR
link_1.txt S_ISLNK

zhangly@ubuntu:/mnt/data/gitstorage/apue$ ./a.out link_1.txt
1.txt 
lstat:
link_1.txt:S_ISLNK inode:266730
stat
link_1.txt:S_ISREG inode:265559
lstat:
1.txt:S_ISREG inode:265559
stat
1.txt:S_ISREG inode:265559

#endif
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	struct stat buf;
	char *ptr = NULL;
	for (i = 1; argc > i; i++) {
		if (-1 == lstat(argv[i], &buf)) {
			fprintf(stderr, "lstat %s\n", argv[i]);
		}
		if (S_ISREG(buf.st_mode)) 
			ptr = "S_ISREG";
		else if (S_ISDIR(buf.st_mode))
			ptr = "S_ISDIR";
		else if (S_ISCHR(buf.st_mode))
			ptr = "S_ISCHR";
		else if (S_ISBLK(buf.st_mode))
			ptr = "S_ISBLK";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "S_ISFIFO";
		else if (S_ISLNK(buf.st_mode))
			ptr = "S_ISLNK";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "S_ISSOCK";
		else
			ptr = "unknown file type";
		fprintf(stdout, "lstat:\n%s:%s inode:%ld\n", argv[i], ptr,
				buf.st_ino);

		if (-1 == stat(argv[i], &buf)) {
			fprintf(stderr, "lstat %s\n", argv[i]);
		}
		if (S_ISREG(buf.st_mode)) 
			ptr = "S_ISREG";
		else if (S_ISDIR(buf.st_mode))
			ptr = "S_ISDIR";
		else if (S_ISCHR(buf.st_mode))
			ptr = "S_ISCHR";
		else if (S_ISBLK(buf.st_mode))
			ptr = "S_ISBLK";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "S_ISFIFO";
		else if (S_ISLNK(buf.st_mode))
			ptr = "S_ISLNK";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "S_ISSOCK";
		else
			ptr = "unknown file type";
		fprintf(stdout, "stat\n%s:%s inode:%ld\n", argv[i], ptr,
				buf.st_ino);
	}
	return 0;
}
