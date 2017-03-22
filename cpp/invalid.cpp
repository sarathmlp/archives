#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char *attr[])
{
    while(attr)
    {
        const char *ch = *attr;
        if (strlen(ch) != 0)
        {
            const char *str = *attr;
            bool unknownFlag = false;

            while(*str)
            {
                if(isdigit(*str))
                {
                    str++;
                    continue;
                }
                else
                {
                    unknownFlag = true;
                    printf("-->Unknown value passed in VendorId\n");
                    printf("-->Setting to default value --> 0\n");
                    break;
                }
            }
        }
        attr++;
    }
}

