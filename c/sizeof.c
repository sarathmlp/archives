#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t val = 0x1;
    val <<= 7;

    printf("%u\n", val);

    return 0;
}
