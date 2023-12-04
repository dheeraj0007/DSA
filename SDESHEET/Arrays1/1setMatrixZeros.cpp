#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/set-matrix-zero/
// https://leetcode.com/problems/set-matrix-zeroes/

// O(n2) solution
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1; // mark the row as 1
                col[j] = 1; // mark the column as 1
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[j] == 1 || row[i] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// optimal solution
void setZeroes2(vector<vector<int>> &matrix)
{
    int col0 = 1;
    int n = matrix.size();
    int m = matrix[0].size();
    // vector<int> col(m, 0); -> matrix[0][...]
    // vector<int> row(n, 0); -> matrix[...][0]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the i-th row
                matrix[i][0] = 0;

                // mark the j-th column
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(vector<vector<int>> matrix)
{
    // iterate over the matrix
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes2(matrix);
    printMatrix(matrix);
    return 0; 
}