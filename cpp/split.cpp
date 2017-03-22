#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    vector<string>elems;
    string s = "hello,how,are,you";
    // string s = "hello";
    stringstream ss(s);
    string item;
    while (getline(ss, item, ','))
    {
        elems.push_back(item);
    }

    for (int i=0; i<elems.size(); i++)
    {
        cout << elems[i] << endl;
    }
}
