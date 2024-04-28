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

TreeNode* getmin(TreeNode* root)
{
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root==nullptr)
    {
        return NULL;
    }

    if(root->val>key)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(root->val<key)
    {
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left==nullptr or root->right==nullptr)
        {
            return (root->left==nullptr?root->right:root->left);
        }
        else
        {
            TreeNode* temp= getmin(root->right);
            root->val=temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

    }
    return root;
}

int main()
{
    return 0;
}