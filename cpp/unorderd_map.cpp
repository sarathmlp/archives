#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>

#define MAP unordered_map
using namespace std;

int main()
{
    MAP<int, string> unMap;
    sleep(10);
    cout << "Allocation started" << endl;
    for (int i=0; i < 100000; i++)
    {
        stringstream ss;
        ss << i << i%2 << i + 2;
        string data = ss.str();
        unMap.insert(pair<int, string>(i,data));
    }
    cout << "Allocation ended" << endl;
    sleep(5);
    unMap.clear();
    cout << "map cleared" << endl;
    sleep(5);
    cout << "Second Allocation started" << endl;
    for (int i=100000; i < 200000; i++)
    {
        stringstream ss;
        ss << i << i%2 << i + 2;
        string data = ss.str();
        unMap.insert(pair<int, string>(i,data));
    }
    cout << "Second Allocation ended" << endl;
    sleep(5);
    unMap.clear();
    cout << "map cleared" << endl;
    sleep(5);

    return 0;
}
