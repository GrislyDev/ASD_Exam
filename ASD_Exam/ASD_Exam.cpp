#include <iostream>
using namespace std;

int SearchBinary(int arr[], int low, int high, int key);
int SearchInterpolation(int arr[], int low, int high, int key);

int main()
{
    int arr[] = { 10,16,23,27,30,32,37,40,47,48,49,52,52,52,53,54,55,56,61,63,83,87,91,92,96 };
    int size = 25;
    int key = 40;
    int index;

    for (int i = 0; i < size; i++)
        cout << arr[i] << "|";
    cout << endl << endl;;

    index = SearchBinary(arr, 0, size-1, key);
    cout << "\n\nIndex of key is: " << index << endl;
    cout << endl << endl;

    index = SearchInterpolation(arr, 0, size-1, key);
    cout << "\n\nIndex of key is: " << index << endl;
}

int SearchBinary(int arr[],int low, int high, int key)
{
    cout << "Binary Search\n\n";
    int mid = 0;

    while (true)
    {
        mid = low + (high - low) / 2;
        cout << "searching..  mid=" << mid << "   A[mid]=" << arr[mid] 
             <<"   low="<<low<<"   high="<<high<< endl;
        if (key < arr[mid])
            high = mid - 1;
        else if (key > arr[mid])
            low = mid + 1;
        else
            return mid;
        if (low > high)
            return 0;
    }
}

int SearchInterpolation(int arr[], int low, int high, int key)
{
    cout << "Interpolation Search\n\n";
    int mid = 0;

    while (true)
    {
        mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        cout << "searching..  mid=" << mid << "   A[mid]=" << arr[mid]
            << "   low=" << low << "   high=" << high << endl;
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else if (arr[mid] == key)
            return mid;
        if (low > high)
            return 0;
    }
}
