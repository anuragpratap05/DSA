#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

vector<vector<int>> dirs = {{0, 1}, {1, 0}};

int minPathSumHelp(vector<vector<int>> &grid, int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er and sc == ec)
        return dp[sr][sc] = grid[sr][sc];
    int minSum = 1e9;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    for (vector<int> &vec : dirs)
    {
        int r = sr + vec[0];
        int c = sc + vec[1];

        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            int recAns = minPathSumHelp(grid, r, c, er, ec, dp);
            if (recAns + grid[sr][sc] < minSum)
                minSum = recAns + grid[sr][sc];
        }
    }
    return dp[sr][sc] = minSum;
}

int minPathSumHelpTabu(vector<vector<int>> &grid, int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int sc = ec; sc >= 0; sc--)
    {
        for (sr = er; sr >= 0; sr--)
        {
            if (sr == er and sc == ec)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }
            int minSum = 1e9;

            for (vector<int> &vec : dirs)
            {
                int r = sr + vec[0];
                int c = sc + vec[1];

                if (r >= 0 and c >= 0 and r <= er and c <= ec)
                {
                    int recAns = dp[r][c];
                    if (recAns + grid[sr][sc] < minSum)
                        minSum = recAns + grid[sr][sc];
                }
            }
            dp[sr][sc] = minSum;
        }
    }
    return dp[0][0];
}

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minPathSumHelp(grid, 0, 0, n - 1, m - 1, dp);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
    return 0;
}