#include <stdio.h>

typedef enum {
    one,
    two
} type;

struct st {
    type t;
    union {
        int a;
        char c;
    };
};

int main()
{
    struct st s1;

    s1.t = two;
    s1.a = 65;

    if (s1.t == one)
        printf("%d\n", s1.a);
    else
        printf("%c\n", s1.c);

    return 0;
}
