#include <iostream>
using namespace std;

// Given an array arr[] of size N,
// check if it is sorted in non-decreasing order or not

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << isSorted(arr, 5);
    return 0;
}