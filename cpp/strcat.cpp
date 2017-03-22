#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    long long imsi_number=1000000000;
    std::string var("hello");
    char s[]="@3gppntework.org";
    char arr[100];

    sprintf(arr, "%lld@%s%s", imsi_number, var.c_str(), s);
    cout << arr << endl;

    return 0;
}
