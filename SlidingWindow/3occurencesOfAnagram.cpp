#include <bits/stdc++.h>
using namespace std;

int countAnagrams(string s, string ptr)
{
    map<char, int> m;
    int size = s.length();
    int k = ptr.length();
    for (int i = 0; i < k; i++)
    {
        m[ptr[i]]++;
    }
    int i = 0, j = 0;
    int ans = 0, count = m.size();
    while (j < size)
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
        {
            count--;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            int check = m[s[i]];
            m[s[i]]++;
            if (check == 0)
            {
                count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    // string s1 = "forxxorfxdofr";
    // string s2 = "for";
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << countAnagrams(s1, s2);
    return 0;
}