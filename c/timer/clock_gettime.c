#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>

#define BILLION 1000000000L

void* ThreadFun(void* arg)
{
    printf("thread id %u\n", pthread_self());
    long diff, diff1;
    struct timespec start, end;
    int i;

    /* measure monotonic time */
    clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
    usleep(200);	/* do stuff */
    clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    diff1 = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000;
    printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
    printf("elapsed time = %llu microseconds\n", (long long unsigned int) diff1);
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
