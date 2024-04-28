#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

double knightProbabilityMemo(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
{
    if (k == 0)
        return dp[k][i][j] = 1.0;
    if (dp[k][i][j] != -1.0)
        return dp[k][i][j];

    double count = 0.0;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < n)
            count += knightProbabilityMemo(n, k - 1, r, c, dp);
    }
    return dp[k][i][j] = count / 8.0;
}

double knightProbability(int n, int k, int row, int column)
{
    vector<vector<vector<double>>> dp(k, vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0)));
    return knightProbabilityMemo(n, k, row, column, dp);
}

int main()
{
    return 0;
}