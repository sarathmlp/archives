#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <iostream>
using namespace std;

#define  NUMTHREADS   16

class Test
{
public:
    static GetCount()
    {
        return count;
    }
private:
    static int count;
}

void *theThread(void *parm)
{
}

int main(int argc, char **argv)
{
    pthread_t thread[NUMTHREADS];
    int       rc=0;
    int       i;
    for (i=0; i <NUMTHREADS; ++i)
    {
        rc = pthread_create(&thread[i], NULL, theThread, NULL);
    }

    for (i=0; i <NUMTHREADS; ++i)
    {
        rc = pthread_join(thread[i], NULL);
    }

    return 0;
}
