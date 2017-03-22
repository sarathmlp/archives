#include <iostream>
#include <unordered_map>
using namespace std;

class Arr
{
public:
    int arr[10000];
    string name;
};

int main()
{
    typedef unordered_map<int,Arr> my_map;
    my_map Map;

    pair<my_map::iterator, bool> ret;
    Arr arr;
    arr.name = "hello";

    ret = Map.insert(pair<int, Arr>(1, arr));

    for (int i=0; i < 10000; i++)
    {
        if (i == 1000)
        {
            Arr arr;
            arr.name = "world";
            ret = Map.insert(pair<int, Arr>(i, arr));
        }
        Arr arr;
        arr.name = "hello";
        Map.insert(pair<int, Arr>(i, arr));
    }

    cout << (ret.first)->second.name << endl;
    return 0;
}
