#include <stdio.h>
#include <stdint.h>

void hexDump (void *addr, int len, char* out)
{
    uint32_t i;
    uint8_t *pc = (uint8_t *)addr;

    if (len <= 0 || addr == NULL || out == NULL) {
        return;
    }

    for (i = 0; i < len; i++) {
        out += sprintf (out, "%02X", pc[i]);
        if (i % 4 == 3)
            out += sprintf (out, " ");
    }
}

int main (int argc, char *argv[])
{
    char my_str[] = "a char string greater than 16 chars";
    char buff[1024];
    hexDump (&my_str, sizeof (my_str), buff);

    printf("%s\n", buff);
    return 0;
}
