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

int maxDotProductMemo(vector<int> &nums1, vector<int> &nums2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == nums1.size() or i2 == nums2.size())
        return dp[i1][i2] = -1e7;
    if (dp[i1][i2] != -1e8)
        return dp[i1][i2];
    int val = nums1[i1] * nums2[i2];
    int bothNums = maxDotProductMemo(nums1, nums2, i1 + 1, i2 + 1, dp) + val;
    int a = maxDotProductMemo(nums1, nums2, i1 + 1, i2, dp);
    int b = maxDotProductMemo(nums1, nums2, i1, i2 + 1, dp);
    return dp[i1][i2] = max(val, max(bothNums, max(a, b)));
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size() + 1, m = nums2.size() + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1e8));
    return maxDotProductMemo(nums1, nums2, 0, 0, dp);
}

int main()
{
    return 0;
}