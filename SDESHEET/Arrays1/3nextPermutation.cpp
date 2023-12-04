#include <bits/stdc++.h>
using namespace std;

// next permutation
/*
    1. First find the index where a[i]<a[i+1]
        if the index is -1 then
            reverse the array and return (edge case where the permutation is the largest)
        else
            1. start finding the element from the back where a[index]<a[i]
            2. then swap these elements
            3. Now just reverse the array from index+1 to end and return the permutation

    eg.
        2 1 5 4 3 0 0
        1. index where a[i]<a[i+1] is i=1 i.e., 1
        2. Now the element from back where a[1]<a[i] is i=4 i.e., 3
        3. Now swap 1 and 3 i.e., swap a[1] & a[4]
        4. Now array becomes
            2 3 5 4 1 0 0
        5. Now just reverse the array from 2 to end and return the permutation i.e., 5 4 1 0 0 to get the nearest greater element
        6. ans = 2 3 0 0 1 4 5
*/

void next_permutation(vector<int> &a)
{
    int index = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return;
    }
    for (int i = n - 1; i > index; i--)
    {
        if (a[i] > a[index])
        {
            swap(a[i], a[index]);
            break;
        }
    }
    reverse(a.begin() + index + 1, a.end());
}

int main()
{
    vector<int> v = {2, 1, 5, 4, 3, 0, 0};
    next_permutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}