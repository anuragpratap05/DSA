#include <bits/stdc++.h>
using namespace std;

// Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

// Input : mat[][] =

// { {1, 1, 0, 0, 0},
// {  0, 1, 0, 0, 1},
// {  1, 0, 0, 1, 1},
// {  0, 0, 0, 0, 0},
// { 1, 0, 1, 0, 1}

// Output : 5

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<int>> &matrix, int i, int j)
{
    int n = matrix.size();
    int m = matrix[0].size();
    matrix[i][j] = 0;

    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and matrix[r][c] == 1)
        {
            dfs(matrix, r, c);
        }
    }
}

int numberOfIslands(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int uniqueIslands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                uniqueIslands++;
                dfs(matrix, i, j);
            }
        }
    }
    return uniqueIslands;
}

int main()
{

        return 0;
}