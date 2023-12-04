#include <iostream>
#include <vector>
using namespace std;

// to find the element at a given place in the triangle

// eg 10C3 ->
/*
1.
    res = res * (10 - 0)
    res = res / (0 + 1)
    ... res = 10
2.
    res = res * (10-1)
    res = res / (1 + 1)
    .. res = 10*9/2 = 45
3.
    res = res * (10-2)
    res = res / (2+1)
    .. res = 45*8/3 = 120

    So 10C3 is 120
*/
int func(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        // Go for r places in the numerator and denominator
        // in numerator go from n * n-1 * n-2 * ... * n-r
        // in denominator go from 1 to r
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// to print any given row of pascal triangle

/*
n = 6 // 1 5 10 10 5 1
1.
    ans = 1
    print(ans)  // 1
2.
    i = 1
    ans = ans * (6-1);
    ans = ans / (1);
    print(ans)  // 5  (1* (5/1))
3.
    i = 2
    ans = ans * (6-2);
    ans = ans / (2);
    print(ans) // 10  (5*(4/2))
4.
    i = 3
    ans = ans * (6-3);
    ans = ans / (3);
    print(ans) // 10  (10*(3/3))
5.
    i = 4
    ans = ans * (6-4);
    ans = ans / (4);
    print(ans) // 5   (10*(2/4))
6.
    i = 5
    ans = ans * (6-5);
    ans = ans / (5);
    print(ans) // 1   (5*(1/5))

    // 1 5 10 10 5 1
*/
void printRow(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

// print the entire pascal triangle

vector<int> generateRow(int n)
{
    vector<int> row;
    int ans = 1;
    row.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i);
        row.push_back(ans);
    }
    return row;
}
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

void printTriangle(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 1.
    // cout << "Element at row " << 11 << " and col " << 4 << " is " << func(11 - 1, 4 - 1);

    // 2.
    // printRow(5);

    // 3.
    vector<vector<int>> ans = pascalTriangle(5);
    printTriangle(ans);
    return 0;
}