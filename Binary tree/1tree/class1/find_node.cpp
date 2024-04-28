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

bool find(TreeNode* root,int data)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->val==data)
    {
        return true;
    }

    return find(root->left,data) or find(root->right,data);
}

int main()
{
    return 0;
}