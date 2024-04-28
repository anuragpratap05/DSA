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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *lcaNode = nullptr;
    while (lcaNode == nullptr)
    {
        if (root == p or root == q)
            return root;
        if ((p->val < root->val and q->val < root->val) or (p->val > root->val and q->val > root->val))
            root = p->val < root->val and q->val < root->val ? root->left : root->right;
        else
            return root;
    }
    return lcaNode;
}
int main()
{
    return 0;
}