#include <stdint.h>
#include <iostream>
#include <sstream>
using namespace std;

static string printHex(const string& str)
{
    stringstream ss;
    ss << "[ " << hex;
    for (int i = 0; i < str.size(); i++)
    {
        ss << (((uint32_t)str[i] )& 0xFF) << " ";
    }
    ss << "]" << dec;

    return ss.str();
}

int main()
{
    char ptr[] = {0xff, 0x00, 0x4d, 0xff, 0xdd};
    string str(ptr,ptr+5);
    cout << printHex(str) << endl;
    return 0;
}
