#include <iostream>
using namespace std;

void fun1()
{
    int x;
    x>>=1;
}

void fun2()
{
    int x;
    x>>=1;
}
int main()
{
    for(int i=0; i< 100;i++)
    {
        fun1();
    }

    for(int i=0; i< 1000;i++)
    {
        fun2();
    }
}
