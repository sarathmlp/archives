#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#include <iostream>

extern int errno;
using namespace std;

pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;
pthread_mutex_t pmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t parent_tid;

void* thr_func(void* arg)
{
    char* var = (char*)arg;
    struct timespec ts;
    while(true)
    {
        clock_gettime(CLOCK_REALTIME, &ts);
        ts.tv_sec += 5;
        pthread_cond_timedwait(&condvar, &pmutex, &ts);
        if (strlen(var))
        {
            cout << endl << "We got : " << var << endl;
        }
        else
        {
            pthread_kill(parent_tid, SIGUSR1);
        }
    }
}

void signal_handler(int arg)
{
    cout << "You didnt enter anything..." << endl;
}

int main( int argc, char* argv[])
{
    char* something = (char*)malloc(1024);
    parent_tid = pthread_self();
    struct sigaction oldsig;
    //sigaction(SIGUSR1, NULL, &oldsig);
    signal(SIGUSR1, signal_handler);
    pthread_t th = pthread_create(&th, NULL, &thr_func, (void*)something);
    while (true)
    {
        cout << endl << "Enter something: ";
        scanf("%s", something);
        if (errno == EINTR)
        {
            continue;
        }
        pthread_cond_signal(&condvar);
    }
    return 0;
}
