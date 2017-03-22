#include <time.h>
#include <math.h>
#include <stdio.h>
#define INTERVAL_MS 999

int main()
{
    struct timespec delay;
    delay.tv_sec    = 0;
    delay.tv_nsec   = ((INTERVAL_MS) * pow (10.0, 6.0));
    // delay.tv_nsec   = 1000000000;

    while (1)
    {
        nanosleep(&delay, NULL);
        printf("sleeping\n");
    }
    return 0;
}

