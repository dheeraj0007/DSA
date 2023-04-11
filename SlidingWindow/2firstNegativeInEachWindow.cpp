#include <bits/stdc++.h>
using namespace std;

vector<int> firstNeg(int arr[], int n, int k)
{
    vector<int> ans;
    list<int> store;
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            store.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (store.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(store.front());
                if (arr[i] == store.front())
                {
                    store.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    vector<int> ans;
    ans = firstNeg(arr, n, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}