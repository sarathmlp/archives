#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char *path;
    // path = (char *)::getenv("FISH");
    path = getenv("FISH");
    int i = atoi(path);
    cout<< path << endl;
    cout<< i  << endl;
}
