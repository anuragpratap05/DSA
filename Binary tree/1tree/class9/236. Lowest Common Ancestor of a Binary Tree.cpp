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
bool lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return false;
    }
    bool self = (root == p or root == q);
    bool left = lowestCommonAncestor2(root->left, p, q);
    if (lca != nullptr)
    {
        return true;
    }
    bool right = lowestCommonAncestor2(root->right, p, q);
    if (lca != nullptr)
    {
        return true;
    }
    if ((self and left) or (self and right) or (left and right))
    {
        lca = root;
        return true;
    }
    return self or left or right;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    lowestCommonAncestor2(root, p, q);
    return lca;
}

int main()
{
    return 0;
}