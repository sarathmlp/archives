#include <iostream>
using namespace std;

int main()
{
    string fish = "hello";
    switch (fish)
    {
        case "fish":
                cout << "fuck u" << endl;
                break;
        case "hello":
                cout << "got it" << endl;
                break;
        default:
                break;
    }
    switch(1)
    {
        case 3:
            cout<<"frog"<<endl;
            break;
        case 2:
        case 1:
            cout<<"fish 2"<<endl;
    }

    return 0;
}
