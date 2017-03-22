#include <cstdio>
#include <iostream>

#define DISPLAY_TITLE()\
    printf("|------------------------The Fish Display mechanism----------------------------|\r\n")
#define DISPLAY_LINE()\
    printf("|--------------------+-------------------+------------------+------------------|\r\n")
#define DISPLAY_BLANK()\
    printf("|--------------------|-------------------|------------------|------------------|\r\n")
#define DISPLAY_COLUMN()\
    printf("|                    |                   |                  |                  |\r\n")
#define DISPLAY_DATA(D1, D2, D3, D4)\
    printf("|%-20d|%-19d|%-18d|%-18d|\r\n",(D1), (D2), (D3), (D4))
#define DISPLAY_HEAD()\
    printf("|--------time--------+--------date-------+-------fish-------+--------frog------|\r\n")

int main()
{
    int i = 0xF0000000, j = -220, k = 70 , l = 120;
    while(1)
    {
        DISPLAY_TITLE();
        DISPLAY_LINE();
        DISPLAY_COLUMN();
        DISPLAY_HEAD();
        DISPLAY_COLUMN();
        DISPLAY_BLANK();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_COLUMN();
        DISPLAY_DATA(i, j, k, l);
        DISPLAY_LINE();
        i++; j++; k++; l++;
        sleep(1);
    }
    return 0;
}
