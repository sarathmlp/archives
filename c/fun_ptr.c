#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test {
    int val;
    int (*ptr) (void);
};

int fun(void)
{
    return 0;
}

int main()
{
    struct test* ptr = (struct test*) malloc (sizeof(struct test));
    memset(ptr, 0, sizeof(struct test));

    typedef int (*test_ptr) (void);
    test_ptr* test;
    *test = fun;

    printf("%d\n", ptr->val);
    printf("%p\n", ptr->ptr);
    return 0;
}
