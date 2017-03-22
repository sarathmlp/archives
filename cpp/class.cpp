#include <iostream>
using namespace std;

class Fun
{
public:
    Fun()
    {}
    Fun(const Fun& lhs)
    {
        cout << "In CC" << endl;
    }
};

Fun fun()
{
    Fun f;
    return f;
}

int main()
{
    Fun f = fun();
    return 0;
}
