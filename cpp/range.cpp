#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    // int int_val = 0x7FFFFFFF;
    uint32_t int_val = 0xFFFFFFFF;
    long long_val = 0x7FFFFFFFFFFFFFFF;
    long long  long_long = 0x7FFFFFFFFFFFFFFF;

    cout << sizeof(int_val) << ":" << int_val << endl;
    cout << sizeof(long_val) << ":" << long_val << endl;
    cout << sizeof(long_long) << ":" << long_long << endl;

    return 0;
}
