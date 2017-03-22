#include <stdio.h>

struct foo
{
    char c[20];
};

int main()
{
    char buff[20] = "hello world";
    struct foo f;

    // f = (struct foo*)buff;
    // puts(f->c);

    f = *(struct foo*)buff;
    puts(f.c);
}

