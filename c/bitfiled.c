#include <stdio.h>

struct {
    unsigned int is_keyword:1;
    unsigned int is_extern:1;
    unsigned int is_static:1;
} flags;

int main()
{
    flags.is_keyword=1;
    flags.is_static=1;
    printf("%lu\n", sizeof(flags));
    printf("%d\n", flags.is_keyword);
    printf("%d\n", flags.is_extern);
    printf("%d\n", flags.is_static);
    return 0;
}
