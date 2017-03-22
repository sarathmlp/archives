#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <errno.h>
#include <fcntl.h>

extern int errno;

#define MAX_BUFFER 1024
#define MY_PORT_NUM 3333
static int reqIn;

int main()
{
    int listenSock, connSock, ret, in , flags, i;
    struct sockaddr_in servaddr;
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;
    char buffer[MAX_BUFFER] = {'\0'};

    listenSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP );

    bzero( (void *)&servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    servaddr.sin_port = htons(MY_PORT_NUM);

    ret = bind( listenSock, (struct sockaddr *)&servaddr, sizeof(servaddr) );

    /* 5 streams per socket */
#if 0
    memset( &initmsg, 0, sizeof(initmsg) );
    initmsg.sinit_num_ostreams = 3;
    initmsg.sinit_max_instreams = 3;
    initmsg.sinit_max_attempts = 2;
    ret = setsockopt( listenSock, IPPROTO_SCTP, SCTP_INITMSG, 
            &initmsg, sizeof(initmsg) );
#endif
    listen( listenSock, 1 );
    printf("Listening for connection\n");

    connSock = accept( listenSock, (struct sockaddr *)NULL, (int *)NULL );
    if(connSock == -1)
        perror("accept()");

    flags = fcntl(listenSock, F_GETFL, 0);
    fcntl(listenSock, F_SETFL, flags | O_NONBLOCK);

    while (1)
    {
        bzero((void *)buffer, sizeof(buffer));
        in = sctp_recvmsg( connSock, (void *)buffer, sizeof(buffer),
                (struct sockaddr *)NULL, 0, &sndrcvinfo, &flags );
        //printf("Data : %s[%d] - %d\n", buffer, in, errno);
        if (in > 0)
        {
            // printf("Data : %s[%d] \n", buffer, in);
            reqIn++;
        }
        else
        {
            perror("Error ");
            fprintf(stderr, "   %d\n", reqIn);
        }

        /* if (strlen(buffer) > 0)
        {
            reqIn++;
        }*/
        if (!strcmp(buffer, "EOL"))
        {
            reqIn--;
            printf("Total no. of req in: %d\n", reqIn);
            close( connSock );
            return 0;
        }
    }
    close( connSock );
    return 0;
}
