#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);
    uint64_t user_start_time = 
        start.ru_utime.tv_sec * 1000000 + start.ru_utime.tv_usec;
    uint64_t sys_start_time = 
        start.ru_stime.tv_sec * 1000000 + start.ru_stime.tv_usec;

    int i;
    struct timeval tv;
    for (i=0; i < 1000; i++)
        // gettimeofday(&tv, NULL);

    getrusage(RUSAGE_SELF, &end);
    uint64_t user_end_time = 
        end.ru_utime.tv_sec * 1000000 + end.ru_utime.tv_usec;
    uint64_t sys_end_time = 
        end.ru_stime.tv_sec * 1000000 + end.ru_stime.tv_usec;

    printf("User time %f\n", (float)(user_end_time - user_start_time));
    printf("System time %f\n", (float)(sys_end_time - sys_start_time));
    return 0;

}
