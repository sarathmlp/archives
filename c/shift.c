#include <stdio.h>

int main() {
    unsigned int key = 1;
    unsigned int val = key << 32;
    printf("val %d\n", val);
    return 0;
}
