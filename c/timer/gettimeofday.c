#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>

#define MILLION 1000000L

void* ThreadFun(void* arg)
{
    printf("thread id %u\n", pthread_self());
    uint64_t diff;
    struct timeval start, end;
    int i;

    /* measure monotonic time */
    gettimeofday(&start, NULL);	/* mark start time */
    sleep(1);	/* do stuff */
    gettimeofday(&end, NULL);	/* mark the end time */

    diff = MILLION * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadFun, NULL);
    pthread_create(&tid2, NULL, ThreadFun, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
