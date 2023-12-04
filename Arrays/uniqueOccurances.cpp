#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr
return true if the number of occurrences of each value in the array is unique or false otherwise.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

*/

bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    unordered_set<int> s;
    for (auto i : m)
    {
        s.insert(i.second);
    }
    return m.size() == s.size();
}

int main()
{
    vector<int> v = {1, 2, 2, 1, 1, 3};
    cout << uniqueOccurrences(v) << endl;
    return 0;
}