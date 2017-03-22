#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n;
    cout << "the array: " << endl;
    for (int i=0; i < 9; i++)
        cout << arr[i] << ", ";
    cout << endl;
    cout << "Enter the number to delete: ";
    cin >> n;
    int i;
    for (i=0; i < 9; i++)
    {
        if (arr[i] == n)
        {
            arr[i] =0;
            break;
        }
    }
    for (int k=i; k < 9; k++)
        arr[k] = arr[k+1];
    cout << "the array: " << endl;
    for (int i=0; i < 9; i++)
        cout << arr[i] << ", ";
    cout << endl;
    return 0;
}
