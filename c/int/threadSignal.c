#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond   = PTHREAD_COND_INITIALIZER;

/* initialize gloabl var to 1 */
int global = 1;

/* functions to be used by the threads */
void *threadfun1(void*);
void *threadfun2(void*);

int main()
{
    pthread_t Thread1, Thread2;

    /* create the threads */
    if (pthread_create(&Thread1, NULL, threadfun1, NULL)) {
        printf("Thread creation failed!");
        abort();
    }
    if (pthread_create(&Thread2, NULL, threadfun2, NULL)) {
        printf("Thread creation failed!");
        abort();
    }
    /* wait for the two threads to finish*/
    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);

    printf("Global variable value after execution %d\n", global);
    return (0);
}

void *threadfun1(void* arg) 
{
    /* lock and wait for signal*/
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("In threadfun1, when global is %d\n", global);
    global++;
    pthread_mutex_unlock(&mutex);

    return (NULL);
}

void *threadfun2(void* arg)
{
    /* lock and signal when condition is met*/
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("In threadfun2, when global is %d\n", global);
        if (global == 2) {
            /* criteria met, signal function 1*/
            printf("Signalling when global is %d\n", global);
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            break;
        } else {
            global++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}
