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

int knapSackMemo(int tar, int wt[], int val[], int n, int idx, vector<vector<int>> &dp)
{
    if (idx == n)
        return dp[tar][idx] = 0;
    if (dp[tar][idx] != -1)
        return dp[tar][idx];
    int include = 0,
        exclude = 0;
    if (tar - wt[idx] >= 0)
        include = knapSackMemo(tar - wt[idx], wt, val, n, idx + 1, dp) + val[idx];
    exclude = knapSackMemo(tar, wt, val, n, idx + 1, dp);
    return dp[tar][idx] = max(include, exclude);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    return knapSackMemo(W, wt, val, n, 0, dp);
}

int main()
{
    int n = 4;
    int wt[4] = {2, 3, 5, 7};
    int val[4] = {10, 11, 9, 20};
    int W = 7;
    int maxGeneratedValue = knapSack(W, wt, val, n);
    cout << "maxGeneratedValue-->" << maxGeneratedValue << endl;
    return 0;
}