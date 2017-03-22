#include <iostream>
using namespace std;

int main()
{
    string fish = {0x34, 0x00, 0x36, 0x00, 0x00};
    // char fish[] = {0x34, 0x00, 0x36, 0x00, 0x00};
    cout << sizeof(fish) << endl;
    
    // unsigned char* ptr = (unsigned char*)fish;
    unsigned char* ptr = (unsigned char*)fish.c_str();
    cout << ptr << endl;
    cout << sizeof(ptr) << endl;

    // cout << ptr[0] << endl;
    // cout << ptr[1] << endl;
    // cout << ptr[2] << endl;
    // cout << ptr[3] << endl;
    // cout << ptr[4] << endl;
    
    // cout << fish[0] << endl;
    // cout << fish[1] << endl;
    // cout << fish[2] << endl;
    // cout << fish[3] << endl;
}
