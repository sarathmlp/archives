#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    while(1)
    {
        i = (int *) malloc(1000);
        //just to avoid lazy allocation
        *i = 100;

        if(i == NULL)
        {
            printf("Memory Not Allocated\n");
        }
        sleep(1);
    }
}
