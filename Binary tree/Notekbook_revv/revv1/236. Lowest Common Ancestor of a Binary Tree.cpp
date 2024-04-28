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

TreeNode *lca = nullptr;
bool lowestCommonAncestorHelp(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return false;

    bool selfPresent = root == p or root == q;
    bool leftpresent = lowestCommonAncestorHelp(root->left, p, q);
    if (lca != nullptr)
        return true;

    if (selfPresent and leftpresent)
    {
        lca = root;
        return true;
    }
    bool rightpresent = lowestCommonAncestorHelp(root->right, p, q);
    if ((selfPresent and rightpresent) or (leftpresent and rightpresent))
        lca = root;

    return selfPresent || leftpresent || rightpresent;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    lowestCommonAncestorHelp(root, p, q);
    return lca;
}

int main()
{
    return 0;
}