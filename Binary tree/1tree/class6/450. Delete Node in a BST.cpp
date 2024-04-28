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

int getmin(TreeNode* root)
{
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else{
        if(root->left==nullptr or root->right==nullptr)
        {
            return (root->left==nullptr?root->right:root->left);
        }
        int minval = getmin(root->right);
        root->val=minval;
        root->right=deleteNode(root->right,minval);
    }
    return root;
    


}

int main()
{
    return 0;
}