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

int idx;
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inorderSi, int inorderEi)
{
    if (inorderSi >= inorderEi)
        return inorderSi > inorderEi ? nullptr : new TreeNode(postorder[idx--]);

    TreeNode *root = new TreeNode(postorder[idx--]);

    int rootIdx = inorderSi;
    while (inorder[rootIdx] != root->val)
        rootIdx++;
    root->right = buildTree(inorder, postorder, rootIdx + 1, inorderEi);
    root->left = buildTree(inorder, postorder, inorderSi, rootIdx - 1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    idx = postorder.size() - 1;
    return buildTree(inorder, postorder, 0, inorder.size() - 1);
}

int main()
{
    return 0;
}