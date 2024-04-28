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
TreeNode* giveit(TreeNode* root,TreeNode* c)
{
    while (root->right != nullptr and root->right != c)
    {
        root = root->right;
    }
    return root;
}


void morris_inorder(TreeNode* root)
{
    TreeNode* c=root;
    while(c!=nullptr)
    {
        TreeNode* l=c->left;
        if(l==nullptr)
        {
            cout<<c->val;
            c=c->right;
        }
        else
        {
            TreeNode* rmnode=giveit(l,c);
            if(rmnode->right==nullptr)
            {
                rmnode->right=c;
                c=c->left;
            }
            else
            {
                rmnode->right=nullptr;
                cout<<c->val;
                c=c->right;
            }
        }
    }

}

int main()
{
    return 0;
}