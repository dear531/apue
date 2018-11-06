#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void print_mode(int fd, char *file)
{
	struct stat buf;
	memset(&buf, 0x00, sizeof(buf));
	if (-1 == fstat(fd, &buf))
	{
		fprintf(stderr, "fstat error :%m\n");
		goto out;
	}
	fprintf(stdout, "file %s mode:%o\n", file, buf.st_mode);
out:
	return;

}

int main(void)
{
	char *pfile1 = "chmod.txt",  *pfile2 = "fchmod.txt";
	char szfile1[PATH_MAX] = {0}, szfile2[PATH_MAX] = {0};
	int fd1 = -1;
	int fd2 = -1;

	snprintf(szfile1, sizeof(szfile1) - 1, "%s/tmp/%s", getenv("HOME"), pfile1);
	snprintf(szfile2, sizeof(szfile2) - 1, "%s/tmp/%s", getenv("HOME"), pfile2);

	fprintf(stdout, "before change:\n");
	unlink(szfile1);

	fd1 = creat(szfile1, S_IRWXU | S_IRWXG | S_IRWXO);
	if (-1 == fd1)
	{
		fprintf(stderr , "create file %s failed\n", szfile1);
		goto out;
	}
	print_mode(fd1, szfile1);

	unlink(szfile2);

	fd2 = creat(szfile2, S_IRWXU | S_IRWXG | S_IRWXO);
	if (-1 == fd2)
	{
		fprintf(stderr , "create file %s failed\n", szfile2);
		goto out;
	}
	print_mode(fd2, szfile2);

	fprintf(stdout, "after change:\n");
#if 1
	chmod(szfile1, S_IRUSR);
	print_mode(fd1, szfile1);

	fd2 = open(szfile2, O_RDONLY);
	if (-1 == fd2) {
		fprintf(stderr, "open error :%m\n");
		goto out;
	}

	if (-1 == fchmod(fd2, S_IRUSR)) {
		fprintf(stderr, "fchmod error :%m\n");
		goto out;
	}
#endif
	print_mode(fd2, szfile2);
out:
	if (-1 == fd2) {
		close(fd2);
		fd2 = -1;
	}

	if (-1 == fd1)
	{
		close(fd1);
		fd1 = -1;
	}

	return 0;
}
