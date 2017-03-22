#include<stdio.h>

#define MAX_COUNT ((sizeof(array))/(sizeof(array[0])))
int array[] = {23,34,12,17,204,99,16};
int main()
{
    int d;
    unsigned int x = 5;
    // for(d=-1;d <= (MAX_COUNT-2);d++)
    for(d=-1;d <= x;d++)
    {
        printf("%d\n",array[d+1]);
    }
    return 0;
}
