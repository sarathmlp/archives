#include<stdio.h>
#include<string.h>

void main()
{
    char c[15], count;
    int i, n, asc;
    printf("Enter the string: \n");
    gets(c);

    for(asc==97;asc<=122;asc++)
    {
        n=0;
        count=0;

        for(i=0;c[i]!=NULL;i++)
        {
            if(asc==c[i])
            {
                n++;   //inc the char
                count=1;
            }
        }
        if(count==1)
        {
            printf("%c""%d\n",asc,n);
        }

        getchar();
    }
}



