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

void display(vector<vector<int>> &dp)
{
    for (auto &vec : dp)
    {
        for (int ele : vec)
        {
            cout << ele << " , ";
        }
        cout << endl;
    }
    cout << endl;
}

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int maxLen = 0;

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i][j] = (i == 0 or j == 0) ? 1 : (dp[i - 1][j - 1] + 1);
                if (dp[i][j] > maxLen)
                    maxLen = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    findLength(nums1, nums2);
    return 0;
}