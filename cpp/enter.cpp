#include <iostream>
#include <cstdio>
#include <stdio_ext.h>
using namespace std;

int main()
{
    char arr[10];
    for (int i=0; i < 10; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '\n')
            break;
        __fpurge(stdin);
    }
    getchar();
}
