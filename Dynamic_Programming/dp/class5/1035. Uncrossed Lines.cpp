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

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == nums1.size() or i2 == nums2.size())
        return dp[i1][i2] = 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    if (nums1[i1] == nums2[i2])
        return dp[i1][i2] = maxUncrossedLines(nums1, nums2, i1 + 1, i2 + 1, dp) + 1;
    else
        return dp[i1][i2] = max(maxUncrossedLines(nums1, nums2, i1, i2 + 1, dp), maxUncrossedLines(nums1, nums2, i1 + 1, i2, dp));
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size() + 1, m = nums2.size() + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return maxUncrossedLines(nums1, nums2, 0, 0, dp);
}

int main()
{
    return 0;
}