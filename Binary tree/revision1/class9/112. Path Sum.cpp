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


bool hasPathSum_(TreeNode *root, int targetSum, int ssf)
{
    if (root == nullptr)
    {

        return false;
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        if (targetSum == ssf + root->val)
        {
            return true;
        }
        return false;
    }

    bool l = hasPathSum_(root->left, targetSum, ssf + root->val);
    if (l)
    {
        return true;
    }
    bool r = hasPathSum_(root->right, targetSum, ssf + root->val);
    if (r)
    {
        return true;
    }

    return false;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    return hasPathSum_(root, targetSum, 0);
}

int main()
{
    return 0;
}