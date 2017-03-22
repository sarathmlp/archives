#include <iostream>
using namespace std;

int main()
{
    char* ptr = new char[10];

    for (int i=0; i < 10; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }
    return 0;
}
