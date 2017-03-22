#include <stdio.h>
#include <stdint.h>

void conv(uint8_t* out, uint16_t in)
{
    out[0] = (in >> 8)  & 0xFF;
    out[1] = (in >> 0)  & 0xFF;
}

int main()
{
    uint16_t in = 1;
    uint16_t val;

    conv((uint8_t*)&val, in);
    printf("%u\n", val);

    return 0;
}
