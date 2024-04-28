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
TreeNode* gettail(TreeNode* root)
{
    while(root->right!=nullptr)
    {
        root=root->right;
    }
    return root;
}
TreeNode* flatten2(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *left = flatten2(root->left);
    TreeNode *right = flatten2(root->right);

    if(root->left!=nullptr and root->right!=nullptr)
    {
        TreeNode* l=root->left;
        TreeNode* r =root->right;
        root->right=nullptr;
        root->left=nullptr;
        TreeNode* tail=gettail(l);
        tail->right=r;
        root->right=l;
        return root;
    }
    if(root->left!=nullptr)
    {
        TreeNode* l=root->left;
        root->left=nullptr;
        root->right=l;
        return root;
    }
    return root;
}
void flatten(TreeNode *root)
{
    if(root==nullptr)
    {
        return;
    }
     flatten2(root);



}

int main()
{
    return 0;
}