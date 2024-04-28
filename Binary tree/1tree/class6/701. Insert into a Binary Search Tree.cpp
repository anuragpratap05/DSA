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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if(root==nullptr)
    {
        return new TreeNode(val);
    }

    if(root->val<val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else{
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

int main()
{
    return 0;
}