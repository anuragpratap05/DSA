#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};
int maxGoldHelp(int n, int m, vector<vector<int>>& M, int i, int j, vector<vector<int>> &dp)
{
    if (j == m - 1)
    {
        return M[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int myAns = 0;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            int recAans = maxGoldHelp(n, m, M, r, c, dp);
            if (recAans + M[i][j] > myAns)
            {
                myAns = recAans + M[i][j];
            }
        }
    }
    dp[i][j] = myAns;
    return myAns;
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        int tempAns = maxGoldHelp(n, m, M, i, 0, dp);
        ans = max(ans, tempAns);
    }
    return ans;
}

int main()
{
    return 0;
}