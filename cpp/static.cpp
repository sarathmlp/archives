#include<iostream>
class Test { 
private:
    int a;
    static int* ptr;
public:
    Test()
    {
        ptr = new int();
    }
    ~Test()
    {
        delete ptr;
    }
};
int* Test::ptr = NULL;

int main()
{
    Test a, b, c;
    return 0;
}
