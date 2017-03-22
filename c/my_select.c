#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

int list[5];
int highSock;
int fd;
fd_set fds;

void fill_fds()
{
    int i;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    for (i = 0; i < 5; i++)
    {
        if (list[i] != 0)
        {
            FD_SET(list[i], &fds);
            if (list[i] > highSock)
            {
                highSock = list[i];
            }
        }
    }
}

void handle_new_connection()
{
    int newConnection;
    int i;
    newConnection = accept(fd, NULL, NULL);
    // May be we can set the socket as non-blocking
    for (i = 0; i < 5; i++)
    {
        if (list[i] == 0)
        {
            list[i] = newConnection;
            printf("Accepted connection slot %d fd %d\n", i, newConnection);
            break;
        }
    }

    if (i == 5)
    {
        printf("No room for new connection\n");
        write(newConnection, "Server too busy!", 20);
        close(newConnection);
    }
}

void handle_data(int index)
{
    char buff[100];
    int i;
    if (read(fd, buff, 100) < 0)
    {   
        printf("Connection lost slot %d fd %d\n", index, list[index]);
        close(list[index]);
        list[index] = 0;
    }
    else
    {
        printf("Data received %s\n", buff);
        for (i = 0; i < strlen(buff); i++)
        {
            buff[i] = toupper(buff[i]);
        }
        write(list[index], buff, 100);
    }
}

void handle_events()
{
    if (FD_ISSET(fd, &fds))
    {
        handle_new_connection();
    }

    int i;
    for (i = 0; i < 5; i++)
    {
        if (FD_ISSET(list[i], &fds))
        {
            handle_data(i);
        }
    }
}

int main(int argc, char** argv)
{
    int port;
    struct timeval timeout;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (argc < 2)
    {
        printf("Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void*)&opt, 4);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port   = htons(port);
    addr.sin_family = AF_INET;

    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(fd, 5) < 0)
    {   
        perror("listen");
        exit(EXIT_FAILURE);
    }
    highSock = fd;

    while (1)
    {
        int ret;
        fill_fds();
        ret = select(highSock + 1, &fds, NULL, NULL, &timeout); 
        if (ret == -1)
        {
            perror("select");
            exit(EXIT_FAILURE);
        }
        else if (ret == 0)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        else
        {
            handle_events();
        }
    }
    return 0;
}
