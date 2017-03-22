#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while (T--) {
        int K;
        int N;
        bool dupe = false;
        
        cin >> K;
        cin >> N;
        int arr[N];
        for (int i=0; i < N; i++) {
            cin >> arr[i];
        }
        
        for (int i=0; i < N; i++) {
            for (int j=i+1; j < N && j <= i+K; j++) {
                if (arr[i] == arr[j]) {
                    dupe = true;
                    goto done;
                }
            }
        }
done:
        if (dupe)
            cout << "True" << endl;
        else
            cout << "False" << endl;
        
    }
    return 0;
}
