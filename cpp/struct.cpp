#include <iostream>
#include <vector>
using namespace std;

class _data
{
private:
    int num;
    char* src;
    char** fis;
    unsigned char fish[12];
public:
    _data();
};

_data::_data():
    num(0),
    src(NULL),
    fis(NULL),
    fish({0})
{}

int main()
{
    vector<int>::iterator it;
    _data dd;

    return 0;
}
