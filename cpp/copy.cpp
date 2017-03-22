#include <iostream>
using namespace std;

class Test
{
    char *p;
public:
    Test()
    {
        p = new char;
    }
    ~Test()
    {
        delete p;
        p = NULL;
    }
};

int main()
{
    Test T1;
    Test T2 = T1;
    return 0;
}
