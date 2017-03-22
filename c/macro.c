#include <stdio.h>

#define FISH

int fun(void)
{
#define MACRO 33
    return MACRO;
}
    
int main()
{
    int ret = fun();
    printf("%d\n", ret);
    printf("%d\n", MACRO);
#ifdef FISH
    printf("fish\n");
#endif

    return 0;
}

