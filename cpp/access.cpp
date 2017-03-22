#include <iostream>
#include <vector>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#define MAC data
using namespace std;

vector<string>string_vec = {"fish"};
string data("fish");

string fun()
{
    return data;
}

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
    cout << string_vec[0] << endl;
    print_time();
    cout << MAC << endl;
    print_time();
    cout << fun() << endl;
    print_time();
    return 0;
}
