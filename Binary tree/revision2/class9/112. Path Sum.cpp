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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    if (root->left == nullptr and root->right == nullptr)
        return targetSum - root->val == 0;

    bool ans = hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    return ans;
}

int main()
{
    return 0;
}