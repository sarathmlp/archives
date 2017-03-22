#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    uint8_t;
    stringstream ss;
    unsigned char arr[] = { 0x14, 0x11 };
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    for (int i = 0 ; i <= 1 ; i++)
    {
        int x = arr[i] & 0x0f;
        // int y = (arr[0] & 0xf0) >> 4;
        int y = arr[i]  >> 4;
        cout << x << endl;
        cout << y << endl;
        ss << y << x;
    }
    cout << ss.str() << endl;
    return 0;
}
