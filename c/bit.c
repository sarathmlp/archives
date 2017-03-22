#include <stdio.h>

int main()
{
    unsigned int mcc = 424;
    unsigned int mnc = 152;

    unsigned char mcc_arr[3] = {'\0'};
    unsigned char mnc_arr[3] = {'\0'};
    unsigned char plmn[3] = {'\0'};

    printf("mcc:%d\n", mcc);
    printf("mnc:%d\n", mnc);

    int i;
    for (i = 0 ; i < 3 ; i++)
    {
        mcc_arr[i] = mcc % 10;
        mcc = mcc / 10;
    }
    for (i = 0 ; i < 3 ; i++)
    {
        if (!(mnc/100) && i == 0)
        {
            mnc_arr[i] = 0xff;
            continue;
        }
        mnc_arr[i] = mnc % 10;
        mnc = mnc / 10;
    }
    for (i = 0 ; i < 3 ; i++)
    {
        printf("%d\n", mcc_arr[i]);
    }
    for (i = 0 ; i < 3 ; i++)
    {
        printf("%d\n", mnc_arr[i]);
    }

    plmn[0] = (mnc_arr[1] << 4)|mcc_arr[2];
    plmn[1] = (mnc_arr[0] << 4)|mcc_arr[0];
    plmn[2] = (mcc_arr[1] << 4)|mnc_arr[2];

    printf("-----------------\n");
    printf("%x", plmn[0]);
    printf("%x", plmn[1]);
    printf("%x", plmn[2]);
    printf("\n");
    printf("-----------------\n");
    return 0;
}
