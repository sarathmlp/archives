#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    struct timeval ts1, ts2;
    long long time1, time2, diff;
    int i,var;

    scanf("%d",&var);
    gettimeofday(&ts1, NULL);
    time1 = (ts1.tv_sec * 1000000) + ts1.tv_usec;

    for (i=0;i<var;i++);

    gettimeofday(&ts2, NULL);
    time2 = (ts2.tv_sec * 1000000) + ts2.tv_usec;

    printf("-------------------------\n");
    diff = time2 - time1;
    printf("total %ld microseconds\n", diff);
    printf("%ld seconds\n", diff/1000000);
    diff %= 1000000;
    printf("%ld milliseconds\n", diff/1000);
    diff %= 1000;
    printf("%ld microseconds\n", diff);
    printf("-------------------------\n");
    return 0;
}
