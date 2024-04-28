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

int idx = 0;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int s, int e)
{
    if (s > e)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[idx++]);
    int i = s;
    for (; i <= e; i++)
    {
        if (root->val == inorder[i])
            break;
    }

    root->left = buildTree(preorder, inorder, s, i - 1);
    root->right = buildTree(preorder, inorder, i + 1, e);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder, inorder, 0, preorder.size() - 1);
}

int main()
{
    return 0;
}