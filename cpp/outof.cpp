#include <iostream>
using namespace std;

int main() {
    char arr[3] = {'a', 'b', 'c'};
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 4; j++) {
            cout << arr[j] << endl;
        }
    }
    return 0;
}
