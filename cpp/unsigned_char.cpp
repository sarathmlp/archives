#include <iostream>
using namespace std;

int main()
{
    unsigned char arr[] = {0x81,0xab};
    string str(reinterpret_cast<char *>(arr));
    cout << hex << str << endl;

    return 0;
}
