#include <iostream>
using namespace std;

class Base
{
private:
    int i;
public:
    Base(int data = 9):i(data)
    {
        cout << "In Base class constructor" << endl;
    }
    virtual void display()
    {
        cout << "In Base class" << endl;
        cout << "i = " << i << endl;
    }
    virtual ~Base()
    {
        cout << "In Base class destructor" << endl;
    }
};

class Derived: public Base
{
private:
    int j;
public:
    Derived(int data = 10):Base(11),j(data)
    {
        cout << "In Derived class constructor" << endl;
    }
    void display()
    {
        cout << "In Derived class" << endl;
        cout << "j = " << j << endl;
    }
    ~Derived()
    {
        cout << "In Derived class destructor" << endl;
    }
};

int main()
{
    Base b1;
    Derived d1;
    return 0;
}
