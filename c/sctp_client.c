#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <math.h>

#define MAX_BUFFER 1024
#define MY_PORT_NUM 3333
#define INTERVAL_MS 999

void handler(int sig_no);

int connSock;
char buffer[MAX_BUFFER] = "hello world";
static int reqOut;

int main(int argc, char *argv[])
{
    int bSize, duration, gap;
    if (argc < 4)
    {
        printf("usage: ./client [duration(seconds)] [burstSize] [gap(milliseconds)]\n");
        exit(0);
    }
    else
    {
        duration   = atoi(argv[1]);
        bSize = atoi(argv[2]);
        gap   = atoi(argv[3]);
        printf("duration: %d, burstSize: %d, gap: %d\n",duration, bSize, gap);
    }
    int in, i, ret, flags, burst;
    struct sockaddr_in servaddr;
    struct sctp_status status;
    struct timespec delay;
    signal(SIGINT, handler);

    connSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP );

    if(connSock == -1)
        perror("socket()");

    bzero( (void *)&servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MY_PORT_NUM);
    servaddr.sin_addr.s_addr = inet_addr( "127.0.0.1" );

    ret = connect( connSock, (struct sockaddr *)&servaddr, sizeof(servaddr) );

    if(ret == -1)
        perror("connect()");

    if ( gap == 1000)
    {
        delay.tv_sec    = 1;
        delay.tv_nsec   = 0;
    }
    else
    {
        delay.tv_sec    = 0;
        delay.tv_nsec   = (gap * pow (10.0, 6.0));
    }

    time_t init_time;
    time(&init_time);
    while (1)
    {
        for (burst=0; burst < bSize; burst++)
        {
            reqOut++;
            ret = sctp_sendmsg( connSock, (void *)buffer, (size_t)strlen(buffer),
                    NULL, 0, 0, 0, 0, 0, 0 );
        }
        time_t  curr_time;
        time(&curr_time);
        if (( curr_time - init_time ) >= duration)
        {
            printf("\nTerminating load\n");
            strcpy(buffer, "EOL");
            sctp_sendmsg( connSock, (void *)buffer, (size_t)strlen(buffer),
                    NULL, 0, 0, 0, 0, 0, 0 );
            printf("Total no. of req sent out: %d\n", reqOut);
            close(connSock);
            return 0;
        }
        nanosleep(&delay, NULL);
        // printf("sleeping\n");
    }
    close(connSock);
    return 0;
}

void handler(int sig_no)
{
    printf("\nTerminating load\n");
    strcpy(buffer, "EOL");
    sctp_sendmsg( connSock, (void *)buffer, (size_t)strlen(buffer),
            NULL, 0, 0, 0, 0, 0, 0 );
    printf("Total no. of req sent out: %d\n", reqOut);
    exit(0);
}
