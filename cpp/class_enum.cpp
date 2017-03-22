#include <iostream>
using namespace std;

class Enum
{
public:
    enum
    {
        one = 1,
        two = 2
    };
};

int main()
{
    Enum e1;
    cout << Enum::two << endl;
    cout << e1.two << endl;
    return 0;
}
