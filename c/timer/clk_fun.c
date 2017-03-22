#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define  NUMTHREADS   16

void *theThread(void *parm)
{
#if 0
    struct timeval tv;
    int i;
    for (i=0; i < 1000; i++)
    {
        gettimeofday(&tv, NULL);
    }
#else
    struct timespec tspec;
    int i;
    for (i=0; i < 1000; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &tspec);
    }
#endif
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread[NUMTHREADS];
    int       rc=0;
    int       i;
    struct    rusage start, end;


    getrusage(RUSAGE_SELF, &start);
    uint64_t user_start_time = 
        start.ru_utime.tv_sec * 1000000 + start.ru_utime.tv_usec;
    uint64_t sys_start_time = 
        start.ru_stime.tv_sec * 1000000 + start.ru_stime.tv_usec;

    for (i=0; i <NUMTHREADS; ++i)
    {
        rc = pthread_create(&thread[i], NULL, theThread, NULL);
    }

    for (i=0; i <NUMTHREADS; ++i)
    {
        rc = pthread_join(thread[i], NULL);
    }

    getrusage(RUSAGE_SELF, &end);
    uint64_t user_end_time = 
        end.ru_utime.tv_sec * 1000000 + end.ru_utime.tv_usec;
    uint64_t sys_end_time = 
        end.ru_stime.tv_sec * 1000000 + end.ru_stime.tv_usec;

    printf("User time %f\n", (float)(user_end_time - user_start_time));
    printf("System time %f\n", (float)(sys_end_time - sys_start_time));

    return 0;
}
