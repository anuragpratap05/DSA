#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int findPathsMemo(int n, int m, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
{
    if (i < 0 or i >= n or j < 0 or j >= m or maxMove == 0)
    {
        if (i < 0 or i >= n or j < 0 or j >= m)
            return 1;
        else
            return 0;
    }
    if (dp[i][j][maxMove] != -1)
        return dp[i][j][maxMove];

    long cnt = 0;

    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        cnt += findPathsMemo(n, m, maxMove - 1, r, c, dp);
    }
    return dp[i][j][maxMove] = cnt % 1000000007;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
    return findPathsMemo(m, n, maxMove, startRow, startColumn, dp);
}

int main()
{
    int m = 1;
    int n = 3;
    int maxMove = 3;
    int startRow = 0;
    int startColumn = 1;
    int ways = findPaths(n, m, maxMove, startRow, startColumn);
    cout << "Total Ways = " << ways << endl;
    return 0;
}