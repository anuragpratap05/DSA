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
TreeNode *lca = nullptr;
bool lowestCommonAncestor_help(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return false;
    }

    bool self = (root == p or root == q);

    bool left = lowestCommonAncestor_help(root->left, p, q);
    if ((self == true and left == true) or lca != nullptr)
    {
        if (lca == nullptr)
        {
            lca = root;
        }
        return true;
    }

    bool right = lowestCommonAncestor_help(root->right, p, q);
    if ((self == true and right == true) or (left == true and right == true) or lca != nullptr)
    {
        if (lca == nullptr)
        {
            lca = root;
        }
        return true;
    }
    return left or self or right;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    lowestCommonAncestor_help(root, p, q);
    return lca;
}

int main()
{
    return 0;
}