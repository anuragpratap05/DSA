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
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int inorderSi, int inorderEi)
{
    if (inorderSi >= inorderEi)
        return inorderSi > inorderEi ? nullptr : new TreeNode(preorder[idx++]);

    TreeNode *root = new TreeNode(preorder[idx++]);

    int rootIdx = inorderSi;
    while (inorder[rootIdx] != root->val)
        rootIdx++;
    root->left = buildTree(preorder, inorder, inorderSi, rootIdx - 1);
    root->right = buildTree(preorder, inorder, rootIdx + 1, inorderEi);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder, inorder, 0, inorder.size() - 1);
}

int main()
{
    return 0;
}