#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    struct timeval ts;
    char buffer[30];

    gettimeofday(&ts, NULL);
    printf("%ld\t%ld\n", (long)ts.tv_sec, (long)ts.tv_usec);

    time_t curtime=ts.tv_sec;
    strftime(buffer,30,"%m-%d-%Y  %T:",localtime(&curtime));

    printf("%s->%ld\n",buffer,ts.tv_usec);
    return 0;
}
