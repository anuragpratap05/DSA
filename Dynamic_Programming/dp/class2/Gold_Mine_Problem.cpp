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

vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};

int maxGoldHelp(int n, int m, vector<vector<int>> &M, int sr, int sc, vector<vector<int>> &dp)
{
    if (sc == m - 1)
        return dp[sr][sc] = M[sr][sc];
    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    int maxGold = 0;
    for (vector<int> &vec : dir)
    {
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            int recGold = maxGoldHelp(n, m, M, r, c, dp);
            if (recGold + M[sr][sc] > maxGold)
                maxGold = recGold + M[sr][sc];
        }
    }
    return dp[sr][sc] = maxGold;
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    int maxGold = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        maxGold = max(maxGold, maxGoldHelp(n, m, M, i, 0, dp));
    }
    return maxGold;
}

int main()
{
    vector<vector<int>> M = {{1, 3, 1, 5},
                             {2, 2, 4, 1},
                             {5, 0, 2, 3},
                             {0, 6, 1, 2}};

    int n = 4, m = 4;
    cout << "ans--> " << maxGold(n, m, M);
    return 0;
}