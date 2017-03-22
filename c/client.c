#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
    int sock_fd;
    char buff[20] = {'\0'};
    struct sockaddr_in client_sock;
    client_sock.sin_family = AF_INET;
    client_sock.sin_port = htons(atoi(argv[1]));
    // client_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_sock.sin_addr.s_addr = inet_addr("172.16.3.31");

    // Create the socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // Set socket options
    int opt;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("setsockopt");
    }
#if 0
    // Bind it
    if (bind(sock_fd, (const struct sockaddr*)&client_sock,
                sizeof(client_sock)) < 0)
    {
        perror("bind");
    }
#endif
    // Connect
    if (connect(sock_fd, (const struct sockaddr*)&client_sock, 
                sizeof(client_sock)) < 0)
    {
        perror("failed ");
        exit(-1);
    }
    write(sock_fd, "hello server", 20);
    int len = read(sock_fd, buff, 20);
    buff[len] = '\0';
    printf("DATA: %s\n", buff);

    return 0;
}
