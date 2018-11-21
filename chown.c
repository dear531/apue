#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>



int main(void)
{
#if 0
	int stat(const char *path, struct stat *buf);
	           struct stat {
               dev_t     st_dev;     /* ID of device containing file */
               ino_t     st_ino;     /* inode number */
               mode_t    st_mode;    /* protection */
               nlink_t   st_nlink;   /* number of hard links */
               uid_t     st_uid;     /* user ID of owner */
               gid_t     st_gid;     /* group ID of owner */
               dev_t     st_rdev;    /* device ID (if special file) */
               off_t     st_size;    /* total size, in bytes */
               blksize_t st_blksize; /* blocksize for file system I/O */
               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
               time_t    st_atime;   /* time of last access */
               time_t    st_mtime;   /* time of last modification */
               time_t    st_ctime;   /* time of last status change */
           };
#endif
	char *pszfile1 = "/home/zhangly/tmp/chown.txt";
	struct stat stat_buf = {.st_dev = 0};
	int fd1 = -1;
	unlink(pszfile1);

	fd1 = creat(pszfile1, S_IRWXU | S_IRWXG | S_IRWXO);
	stat(pszfile1, &stat_buf);

	fprintf(stdout, "file:%s stat_buf.st_uid:%d, stat_buf.st_gid:%d\n",
	pszfile1, stat_buf.st_uid, stat_buf.st_gid);
#if 0
	struct passwd *getpwnam(const char *name);
           struct passwd {
               char   *pw_name;       /* username */
               char   *pw_passwd;     /* user password */
               uid_t   pw_uid;        /* user ID */
               gid_t   pw_gid;        /* group ID */
               char   *pw_gecos;      /* user information */
               char   *pw_dir;        /* home directory */
               char   *pw_shell;      /* shell program */
           };
#endif
	struct passwd *pretpw = NULL;
	char *user = "zhangly";
	pretpw = getpwnam(user);
	fprintf(stdout, "user %s's epretpw->pw_name:%s, pretpw->pw_uid:%d, pretpw->pw_gid:%d\n",
		user, pretpw->pw_name, pretpw->pw_uid, pretpw->pw_gid);
	user = "statd";

	pretpw = getpwnam(user);
	fprintf(stdout, "user %s's epretpw->pw_name:%s, pretpw->pw_uid:%d, pretpw->pw_gid:%d\n",
		user, pretpw->pw_name, pretpw->pw_uid, pretpw->pw_gid);
#if 0
	chown();
#endif
	if (-1 == chown(pszfile1, pretpw->pw_uid, -1))
	{
		fprintf(stderr, "chown error %m\n");
		exit(EXIT_FAILURE);
	}
	stat(pszfile1, &stat_buf);

	fprintf(stdout, "file:%s stat_buf.st_uid:%d, stat_buf.st_gid:%d\n",
	pszfile1, stat_buf.st_uid, stat_buf.st_gid);
	return 0;
}
