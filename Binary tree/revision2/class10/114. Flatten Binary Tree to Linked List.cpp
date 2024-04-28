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

TreeNode *getTail(TreeNode *root)
{
    while (root->right)
        root = root->right;
    return root;
}

void flatten(TreeNode *root)
{
    if (root == nullptr)
        return;

    flatten(root->left);
    flatten(root->right);

    if (root->left)
    {
        TreeNode *rightSubTree = root->right;
        TreeNode *lc = root->left;
        root->left = nullptr;
        TreeNode *tl = getTail(lc);
        root->right = lc;
        tl->right = rightSubTree;
    }
}

int main()
{
    return 0;
}