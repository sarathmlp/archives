#include <iostream>

using namespace std;

bool jw_search ( int *list, int size, int key, int& rec );
int count = 0;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 24, 34, 36, 43, 47, 50, 52, 53, 57, 59, 61, 63, 64, 67, 69, 70, 72, 73, 75, 77, 80, 83, 85, 87, 89, 91, 93, 95, 97, 99};
    int i = 0, out;
    cout << "Enter the Key to be searched" << endl;
    cin >> i;
    bool isPresent = jw_search(arr, (sizeof(arr)/sizeof(arr[0])), i, out);
    if(isPresent)
    {
        cout << "Key found in the array at position : " << out << endl;
        cout << "COUNT: " << count << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    return 0;
}

bool jw_search ( int *list, int size, int key, int& rec )
{
    // Interpolation search
    bool found = false;
    int low = 0, high = size - 1;
    while ( list[high] >= key && key > list[low] ) {
        count++;
        double low_diff = (double)key - list[low];
        double range_diff = (double)list[high] - list[low];
        double count_diff = (double)high - low;
        int range = (int)( low_diff / range_diff * count_diff + low );
        if ( key > list[range] )
            low = range + 1;
        else if ( key < list[range] )
            high = range - 1;
        else
            low = range;
    }
    if ( key == list[low] ) {
        found = true;
        rec = low + 1;
        //rec = list[low];
    }

    return found;
}
