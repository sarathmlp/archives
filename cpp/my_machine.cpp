#include <iostream>
using namespace std;

int main()
{
    unsigned int check = 0x01;
    unsigned char* var = (unsigned char*)&check;

    if (var[0])
    {
        cout << "Little dick" << endl;
    }
    else
    {
        cout << "Big dick" << endl;
    }

    return 0;
}
