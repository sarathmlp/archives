#include <iostream>
using namespace std;

class Base
{
// private:
protected:
    int b;
public:
    Base(int x): b(x)
    {}
};

class Derived : public Base 
{
    int d;
public:
    Derived(int x):Base(x), d(x)
    {
        // b = x;
    }
    void print()
    {
        cout << b;
    }
};

int main()
{
    Derived d(10);
    return 0;
}
