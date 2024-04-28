#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulationMemo(vector<int> &values, int si, int ei, vector<vector<int>> &dp)
{
    if (ei - si <= 2)
    {
        return dp[si][ei] = ei - si == 1 ? 0 : values[si] * values[si + 1] * values[ei];
    }
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int minScore = 1e9;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = minScoreTriangulationMemo(values, si, cut, dp);
        int right = minScoreTriangulationMemo(values, cut, ei, dp);
        int self = values[si] * values[cut] * values[ei];
        minScore = min(minScore, left + self + right);
    }
    return dp[si][ei] = minScore;
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minScoreTriangulationMemo(values, 0, n - 1, dp);
}

int main()
{
    return 0;
}