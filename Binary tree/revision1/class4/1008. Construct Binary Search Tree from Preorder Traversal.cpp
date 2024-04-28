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

TreeNode *bstFromPreorder_help(vector<int> &preorder, int lr, int rr)
{
    if(idx==preorder.size() or lr>=preorder[idx] or rr<=preorder[idx])
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[idx]);
    idx++;
    root->left = bstFromPreorder_help(preorder, lr, root->val);
    root->right = bstFromPreorder_help(preorder, root->val, rr);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return bstFromPreorder_help(preorder,-(1e9),1e9);
}

int main()
{
    return 0;
}