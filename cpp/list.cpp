#include <string.h>
#include <iostream>
#include <list>
using namespace std;


int main()
{
    list<int>* L = new list<int>;
    // memset(L, 0, sizeof((std::list)));
    L->push_back(0);              // Insert a new element at the end
    L->push_front(0);             // Insert a new element at the beginning
    L->insert(++L->begin(),2);     // Insert "2" before position of first argument
    // (Place before second argument)
    L->push_back(6);

    cout << L->size() << endl;
    list<int>::iterator i;
    for(i=L->begin(); i != L->end(); ++i)
        cout << *i << " ";
    cout << endl;
    // for(i=L->begin(); i != L->end();)
    // {
    //     if (*i == 0)
    //         L->erase(i++);
    //     else
    //         ++i;
    // }
    cout << L->size() << endl;
    for(i=L->begin(); i != L->end(); ++i)
        cout << *i << " ";
    cout << endl;
    return 0;
}
