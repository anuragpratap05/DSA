#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {1, 0}};

int minPathSumMemo(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == grid.size() - 1 and j == grid[0].size() - 1)
        return dp[i][j] = grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int myAns = 1e8;

    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < grid.size() and c < grid[0].size())
        {
            int recAns = minPathSumMemo(grid, r, c, dp);
            if (recAns + grid[i][j] < myAns)
                myAns = recAns + grid[i][j];
        }
    }
    return dp[i][j] = myAns;
}

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minPathSumMemo(grid, 0, 0, dp);
}

int main()
{
    return 0;
}