#include <iostream>
#include <vector>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#define MAC data
using namespace std;

void print_time()
{
    struct timeval tv;
    char buffer[30];
    time_t curtime;

    gettimeofday(&tv, NULL); 
    curtime=tv.tv_sec;

    strftime(buffer,30,"%T",localtime(&curtime));
    printf("%s:%ld\n",buffer,tv.tv_usec);
}

int main()
{
    print_time();
    for (int i =0; i<10000000; i++)
    {}
    print_time();
    return 0;
}
