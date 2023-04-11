#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n, int k)
{
    int i = 0, j = 0, maxSum = INT_MIN;
    int sum = 0;
    while (j < n)
    {
        sum = sum + arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxSum = max(maxSum, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

// 2nd code with same approach

int maxSumSubarray2(int arr[], int n, int k)
{
    int sum = 0;
    // sum of first window
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int s = 0, e = k, maxSum = sum;
    while (e < n)
    {
        // moving the window and finding the sum of next
        sum = sum - arr[s] + arr[e];
        maxSum = max(maxSum, sum);
        s++;
        e++;
    }
    return maxSum;
}

int main()
{
    // Given array size , array elements, window size k
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << maxSumSubarray2(arr, n, k);
    return 0;
}