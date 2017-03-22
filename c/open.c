#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio_ext.h>

#define SZ  40

int main()
{
    int fd = open("file.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Open");
    }
    
    char choice;
    printf("Enter your choice, r/w:");
    scanf("%c", &choice);
    if ( choice == 'r')
    {
        char r_buff[SZ];
        int r_count = read(fd, r_buff, SZ);
        r_buff[r_count] = '\0';
        puts(r_buff);
    }
    else
    {
        char w_buff[SZ];
        printf("Enter the data to write:");
        __fpurge(stdin);
        gets(w_buff);
        int w_count = write(fd, w_buff, strlen(w_buff));
        printf("%s\n", w_buff);
    }
    
    close(fd);
    return 0;
}
