#include <iostream>
#include <cstdio>
#include <cstdlib>

void del_fun(int* p)
{
    printf("&p = %p, p = %p, *p = %d\n",&p, p, *p);
    free(p);
    p = NULL;
}

void one_more(char* p)
{
    // p = (char*) malloc(1);
    *p = 'g';
    printf("&p = %p, p = %p, *p = %d\n",&p, p, *p);
    p = NULL;
    printf("&p = %p, p = %p\n",&p, p);
}

int main()
{
    int* p = (int*) malloc(sizeof(int));
    printf("&p = %p, p = %p, *p = %d\n",&p, p, *p);
    *p = 10;
    del_fun(p);
    printf("&p = %p, p = %p, *p = %d\n",&p, p, *p);

    printf("------------------------------------------------\n");
    char* ptr;
    ptr = (char*) malloc(1);
    printf("&ptr = %p, ptr = %p, *ptr = %d\n",&ptr, ptr, *ptr);
    one_more(ptr);
    printf("&ptr = %p, ptr = %p, *ptr = %d\n",&ptr, ptr, *ptr);
    return 0;
}

