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

int countExactlyOneChild(TreeNode *root)
{
    if (root == nullptr or (root->left == nullptr and root->right == nullptr))
    {
        return 0;
    }
    int lc = countExactlyOneChild(root->left);
    int rc = countExactlyOneChild(root->right);
    if (root->left == nullptr or root->right == nullptr)
    {
        return lc+rc+1;
    }
    return lc+rc;
}

int main()
{
    return 0;
}