#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
    /* lock the variable to avoid race conditions*/
    pthread_mutex_lock(&mutex);
    global++;
    pthread_mutex_unlock(&mutex);

    return (NULL);
}

void *threadfun2(void* arg)
{
    /* lock the variable to avoid race conditions*/
    pthread_mutex_lock(&mutex);
    global++;
    pthread_mutex_unlock(&mutex);

    return (NULL);
}
