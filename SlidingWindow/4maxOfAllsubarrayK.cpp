#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    list<int> l;
    int j = 0, i = 0;
    while (j < nums.size())
    {
        while (l.empty() == false && l.back() < nums[j])
        {
            l.pop_back();
        }
        l.push_back(nums[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (l.front() == nums[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 1, 2, 0, 5};
    vector<int> v2 = maxSlidingWindow(v, 3);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    return 0;
}