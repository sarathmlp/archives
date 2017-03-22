#include <iostream>
using namespace std;

int main()
{
    static int i = 0;

    __sync_fetch_and_add(&i, 1);
    cout << i << endl;
    /* for (int j = 0; j < 10; j++)
    {
        __sync_fetch_and_add(&i, 1);
        cout << i << endl;
    }*/

    return 0;
}
