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
bool lowestCommonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return false;

    bool selfpresent = root == p or root == q;
    bool leftPresent = lowestCommonAncestorHelper(root->left, p, q);
    if (lcaNode != nullptr)
        return true;
    if (selfpresent && leftPresent)
    {
        lcaNode = root;
        return true;
    }
    bool rightPresent = lowestCommonAncestorHelper(root->right, p, q);
    if ((selfpresent and rightPresent) or (leftPresent and rightPresent))
        lcaNode = root;

    return selfpresent or leftPresent or rightPresent;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    lowestCommonAncestorHelper(root, p, q);
    return lcaNode;
}

int main()
{
    return 0;
}