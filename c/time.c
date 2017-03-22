#include <stdio.h>
#include <time.h>

int main()
{
    time_t    tx;
    struct tm tbuf, *temp;
    char buff[80];

    time(&tx);
    temp =  localtime_r(&tx, &tbuf);
    printf("%lld\n",tx);
    strftime(buff, 80, "%b%d %Y %H:%M:%S" , &tbuf);
    printf("%s\n", buff);
}

