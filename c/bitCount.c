#include <stdio.h>

void method1(int num);
void method2(int num);

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    method1(num);
    method2(num);

    return 0;
}

void method1(int num)
{
    int count = 0;

    while (num) {
        count += num & 1;
        num >>= 1;
    }
    printf("In number of set bits are %d\n", count);
}

void method2(int num)
{
    int count = 0;

    while (num) {
        num &= (num - 1);
        count++;
    }
    printf("In number of set bits are %d\n", count);
}
