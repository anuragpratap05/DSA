#include <bits/stdc++.h>
using namespace std;

int knapSackMemo(int tar, int wt[], int val[], int n, int idx, vector<vector<int>> &dp)
{
    if (idx == n)
        return dp[tar][idx] = 0;
    if (dp[tar][idx] != -1)
        return dp[tar][idx];
    int include = 0,
        exclude = 0;
    if (tar - wt[idx] >= 0)
        include = knapSackMemo(tar - wt[idx], wt, val, n, idx, dp) + val[idx];
    exclude = knapSackMemo(tar, wt, val, n, idx + 1, dp);
    return dp[tar][idx] = max(include, exclude);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(W + 1, vector<int>(N + 1, -1));
    return knapSackMemo(W, wt, val, N, 0, dp);
}

int main()
{
    int N = 4;
    int W = 8;
    int val[4] = {10, 40, 50, 70};
    int wt[4] = {1,
                 3,
                 4,
                 5};
    int ans = knapSack(N, W, val, wt);
    cout << "ans-->" << ans << endl;
    return 0;
}