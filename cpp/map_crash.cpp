#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;

#define map map

int main()
{
    typedef map<unsigned, string> var;
    var* v1= new var;
    // var* v1= (var*) malloc(sizeof(var));
    // memset(v1,0,sizeof(var));
    v1->insert(pair<unsigned,string>(0, "Frog"));
    v1->insert(pair<unsigned,string>(0, "Fish"));
    for (map<unsigned, string>::iterator it = v1->begin();
            it != v1->end(); ++it)
    {
        cout << "  [" << (*it).first << ", " << (*it).second << "]" << endl;
    }
    cout << v1->size() << endl;
    map<unsigned, string>::iterator it = v1->begin();
    v1->erase(it);
    cout << v1->size() << endl;
    return 0;
}
