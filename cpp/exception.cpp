#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
        ptr1 = new char[100];
        throw "exception";
        ptr2 = new char[100];
    }

    ~Test()
    {
        delete[] ptr1;
        delete[] ptr2;
    }

private:
    char* ptr1;
    char* ptr2;
};

int main()
{
    try
    {
        Test t1;
    }
    catch(...)
    {
        cout << "exception caught" << endl;
    }
    return 0;
}
