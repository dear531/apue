#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
#if 0
	       #include <sys/types.h>
	       #include <dirent.h>

	       DIR *opendir(const char *name);
	              DIR *fdopendir(int fd);
#endif
	DIR *dir = NULL;
	dir = opendir("/mnt/h/gitstorage");
#if 0
           struct dirent {
               ino_t          d_ino;       /* inode number */
               off_t          d_off;       /* not an offset; see NOTES */
               unsigned short d_reclen;    /* length of this record */
               unsigned char  d_type;      /* type of file; not supported
                                              by all filesystem types */
               char           d_name[256]; /* filename */
           };
#endif
	if (NULL == dir)
	{
		fprintf(stderr, "opendir error :%m\n");
		goto out1;
	}

	struct dirent *entry = NULL;
	while (NULL != (entry = readdir(dir)))
	{
		fprintf(stdout, "%s\n", entry->d_name);
	}

	if (NULL != dir)
	{
		closedir(dir);
		dir = NULL;
	}
out1:
	return 0;
}
