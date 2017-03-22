#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

struct fish {
    int val;
    char flag;
};

int main()
{
    struct fish v1, v2;
    v1.val = 100;
    v1.flag = 'C';
    memcpy(&v2, &htonl(*(uint32_t*)&v1), (sizeof(struct fish)));

    printf("%d\n", v2.val);
    printf("%c\n", v2.flag);

    return 0;
}
