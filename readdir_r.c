#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(void)
{
	/* opendir */
#if 0
       #include <sys/types.h>
       #include <dirent.h>

       DIR *opendir(const char *name);
#endif
	DIR *dir = NULL;
	if (NULL == (dir = opendir("/mnt/h/")))
	{
		fprintf(stderr, "opendir error :%m\n");
		exit(EXIT_FAILURE);
	}
	/* readdir_r */
#if 0
int readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result);
           struct dirent {
               ino_t          d_ino;       /* inode number */
               off_t          d_off;       /* not an offset; see NOTES */
               unsigned short d_reclen;    /* length of this record */
               unsigned char  d_type;      /* type of file; not supported
                                              by all filesystem types */
               char           d_name[256]; /* filename */
           };
#endif
#if 1
#include <unistd.h>
#include <stddef.h>
#include <string.h>
	struct dirent *entry = NULL;
	struct dirent *result = NULL;
	int name_max = 0, len = 0;
	name_max = pathconf("/mnt/h/", _PC_NAME_MAX);
	if (name_max == -1)         /* Limit not defined, or error */
		name_max = 255;         /* Take a guess */
	len = offsetof(struct dirent, d_name) + name_max + 1;
	entry = malloc(len);
	memset(entry, 0x00, len);
	int ret = 0;
	while (1)
	{
		if (0 != (ret = readdir_r(dir, entry, &result))) {
			fprintf(stderr, "readdir error %m\n");
			goto out1;
		} else if (0 == ret && NULL != result) {
			fprintf(stdout, "%s\n", entry->d_name);
		
		} else if (0 == ret && NULL == result) {
			fprintf(stdout, "finish \n");
			break;
		}
	}
#else
	struct dirent entry = {.d_name[0] = 0};
	struct dirent *result = NULL;
	int ret = 0;
	while (1)
	{
		if (0 != (ret = readdir_r(dir, &entry, &result))) {
			fprintf(stderr, "readdir error %m\n");
			goto out1;
		} else if (0 == ret && NULL != result) {
			fprintf(stdout, "%s\n", entry.d_name);
		
		} else if (0 == ret && NULL == result) {
			fprintf(stdout, "finish \n");
			break;
		}
	}
#endif
out1:
	/* closedir */
	if (NULL != dir)
	{
		closedir(dir);
		dir = NULL;
	}
	return 0;
}
