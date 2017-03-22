#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    string samp = "123456789";
    cout<<samp<<endl;

    const char *arr = samp.c_str();
    unsigned char msisdn[20] = {'\0'};
    int i,j;

    for (i=0,j=0;i<(strlen(arr)/2); i++, j+=2)
    {
        msisdn[i] = (arr[j+1] << 4) | (arr[j] & 0x0F);
        printf("%x,", msisdn[i]);
    }

    if (strlen(arr) != j)
    {
        msisdn[i] = 0xF0 | arr[j];
        printf("%x,", msisdn[i]);
    }
    printf("\n");
    return 0;
}
