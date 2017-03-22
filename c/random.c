#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    int vectSize = 1000000;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    // printf("%ld\n", tv.tv_usec);
    // printf("%ld\n", tv.tv_sec);
    unsigned int seed = tv.tv_usec;
    printf("%u\n", seed);
    srand(seed);
    // srand(tv.tv_sec);
    int index = rand() % vectSize;
    printf("%d\n", index);
    return 0;
}
