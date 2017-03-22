#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void FillIt(char* str)
{
    int len = strlen(str);
    char count = '1';
    int dat   = str[0];
    int j = 0;
    for (int i=1; i < len; i++)
    {
        if (str[i] == dat)
        {
            count++;
        }
        else
        {
            char tmp = str[i];
            str[++j] = count;
            str[++j] = tmp;
            count = '1';
            dat = tmp;
        }
    }
    str[++j] = count;
    str[++j] = '\0';
}

int main()
{
    char arr[50] = {0};
    cout << "Enter the string: ";
    gets(arr);

    FillIt(arr);
    cout << arr << endl;
    return 0;
}
