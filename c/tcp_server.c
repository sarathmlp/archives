#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port   = htons( 3333 );
    addr.sin_addr.s_addr   = inet_addr("127.0.0.1");
    bind(sfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
    listen(sfd, 1);
    int sz = sizeof(struct sockaddr_in);
    int cfd = accept(sfd, (struct sockaddr*)&addr, &sz);
    while (1)
    {
        char buf[20] = {'\0'};
        read(cfd, buf, 20);
        printf("%s\n", buf);
    }
    return 0;
}
