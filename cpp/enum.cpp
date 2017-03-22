#include <iostream>
using namespace std;

class Hello {
    public:
    enum TYPE{
        DICK = 0,
        PUSSY = 1
    };
    enum ANIM{
        FISH = 3,
        FROG = 4
    };
};

int main()
{
    int enumVar;
    // enumVar = (Fish)20;
    enumVar = Hello::DICK;

    cout << enumVar << endl;
    cout << Hello::FROG << endl;
    return 0;
}
