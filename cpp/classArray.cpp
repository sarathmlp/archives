#include <iostream>
using namespace std;

class Arr
{
    private:
        int i;
        char arr[100];
    public:
        Arr()
        try:i(0),arr({'\0'})
        {
        }
        catch(...)
        {
        }
};

int main()
{
    Arr arr;
    return 0;
}
