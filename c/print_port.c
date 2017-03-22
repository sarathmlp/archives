#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    uint16_t port;
    port = ntohs(10714);
    printf("%d\n", port);

    return 0;
}
