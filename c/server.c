#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    int             sock_fd, client_fd;
    char            buff[20];
    struct          sockaddr_in serv_sock, client_sock;

    serv_sock.sin_family = AF_INET;
    serv_sock.sin_port = htons(3000);
    // serv_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_sock.sin_addr.s_addr = inet_addr("172.16.3.31");

    // Create the socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // Set socket options
    int opt;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("setsockopt");
    }
    // Bind it
    if (bind(sock_fd, (const struct sockaddr*)&serv_sock, sizeof(serv_sock)) <
            0)
    {
        perror("bind");
    }
    // Listen
    listen(sock_fd, 1);
    // Accept
    unsigned size = sizeof(client_sock);
    printf("accepting...\n");
    client_fd = accept(sock_fd, (struct sockaddr*)&client_sock, &size);
    int len = read(client_fd, buff, 20);
    buff[len] = '\0';
    printf("DATA: %s\n", buff);
    write(client_fd, "got you", 20);

    return 0;
}
