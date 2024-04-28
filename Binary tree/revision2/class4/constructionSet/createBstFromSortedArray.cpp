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

TreeNode *sortedArrayToBST(vector<int> &nums, int s, int e)
{
    if (s > e)
        return nullptr;

    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, s, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, e);
    return root;
}

int main()
{
    vector<int> nums = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);
    return 0;
}