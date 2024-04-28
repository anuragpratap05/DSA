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

TreeNode *lcaNode = nullptr;

bool lowestCommonAncestorHelp(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return false;

    bool self = root == p or root == q;

    bool left = lowestCommonAncestorHelp(root->left, p, q);
    if (left && self)
    {
        lcaNode = root;
        return true;
    }

    if (lcaNode != nullptr)
        return true;

    bool right = lowestCommonAncestorHelp(root->right, p, q);
    if ((self && right) or (left && right))
    {
        lcaNode = root;
        return true;
    }
    return self || left || right;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    lowestCommonAncestorHelp(root, p, q);
    return lcaNode;
}

int main()
{
    return 0;
}