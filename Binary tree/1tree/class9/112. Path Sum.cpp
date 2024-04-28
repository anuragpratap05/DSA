#include<bits/stdc++.h>
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

bool hasPathSum2(TreeNode *root, int targetSum, int sum)
{
    if (root == nullptr)
    {
        return false;
    }

    sum += root->val;
    bool left = hasPathSum2(root->left, targetSum, sum);
    if (left)
    {
        return true;
    }
    bool right = hasPathSum2(root->right, targetSum, sum);
    if (right)
    {
        return true;
    }
    cout << root->val << "  " << sum << endl;
    if (sum == targetSum and (root->left == nullptr and root->right == nullptr))
    {
        return true;
    }
    else
        return false;
}
bool hasPathSum(TreeNode *root, int targetSum)
{

    return hasPathSum2(root, targetSum, 0);
}

int main()
{
    return 0;
}