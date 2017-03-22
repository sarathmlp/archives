#include <iostream>
using namespace std;

struct nothing {
};

int main()
{
    nothing n1;

    cout << sizeof(n1) <<  endl;

    return 0;
}
