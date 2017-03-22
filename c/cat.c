#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main()
{
    char ch;

    while (read(0, &ch,1))
        write(1, &ch,1); 

    return 0;
}
