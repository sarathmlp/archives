#include <stdio.h>

struct fish {
    int val;
    char let;
};

struct frog {
    int val;
    char let;
};

void fill(struct frog* ptr)
{
    ptr->val = 220;
    ptr->let = 'A';
}

int main()
{
    // struct fish v1;
    struct frog v1;
    struct frog v2;
    v1.val = 100;
    v1.let = 'c';
    
    // fish

    v2 = v1;
    printf("val %d letter %c\n", v2.val, v2.let);

    fill(&v2);
    printf("val %d letter %c\n", v2.val, v2.let);
    return 0;
}
