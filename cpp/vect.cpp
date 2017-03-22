#include <string.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int>* L = new vector<int>(5);

    cout << "Max size " << L->capacity() << endl;
    L->push_back(1);
    cout << "Max size " << L->capacity() << endl;
    L->push_back(2);
    cout << "Max size " << L->capacity() << endl;
    L->push_back(3);
    L->push_back(4);
    L->push_back(5);
    L->push_back(6);
    L->push_back(7);
    cout << "Max size " << L->capacity() << endl;

    cout << L->size() << endl;

    vector<int>::iterator i;
    for(i=L->begin(); i != L->end(); ++i)
        cout << *i << " ";
    cout << endl;

    return 0;
}
