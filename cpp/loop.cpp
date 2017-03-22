#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Compile with --> g++ loop.cpp -std=c++0x
    long long var = 1111;
    string fish = std::to_string(var);
    cout << fish << endl;
    return 0;
}
