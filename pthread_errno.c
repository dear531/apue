#include <stdio.h>
#include <pthread.h>
#include <errno.h>

void *pthread_func(void *arg)
{
	errno = 1;
	int i = 0;
	for (i = 0; 10 > i; i++) {
		sleep(1);
		fprintf(stdout, "errno :%d\n", errno);
	}
	pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
#if 0
       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
						 void *(*start_routine) (void *), void *arg);
#endif
	pthread_t pthread = 0;
	pthread_create(&pthread, NULL, pthread_func, NULL);
	errno = 2;
	int i = 0;
	for (i = 0; 10 > i; i++) {
		sleep(1);
		fprintf(stdout, "errno :%d\n", errno);
	}
	pthread_join(pthread, NULL);
	pthread_exit(NULL);
	return 0;
}
