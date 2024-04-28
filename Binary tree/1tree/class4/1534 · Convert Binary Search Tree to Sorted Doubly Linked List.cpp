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
    while(root->right!=nullptr and root->right!=c)
    {
        root=root->right;
    }
    return root;
}

TreeNode* morris_inorder(TreeNode* root)
{
    TreeNode* c=root;
    TreeNode* dummy=new TreeNode(-1);
    TreeNode* p=dummy;
    while(c!=nullptr)
    {
        TreeNode* l=c->left;
        if(l==nullptr)
        {
            //cout<<c->val;
            c->left=p;
            p->right=c;
            p=p->right;
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
            else{
                rmnode->right=nullptr;
                //cout<<c->val;
                p->right=c;
                c->left=p;
                p=p->right;
                c=c->right;
            }
        }
    }
    TreeNode *rn = dummy->right;
    dummy->right = nullptr;
    rn->left = p;
    p->right = rn;
    return rn;
}

TreeNode *treeToDoublyList(TreeNode *root)
{
    return morris_inorder(root);
}

int main()
{
    return 0;
}