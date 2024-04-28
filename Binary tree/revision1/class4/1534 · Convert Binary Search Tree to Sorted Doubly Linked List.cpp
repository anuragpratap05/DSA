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

TreeNode *giverm (TreeNode* root,TreeNode* c)
{
    while(root->right!=nullptr and root->right!=c)
    {
        root=root->right;
    }
    return root;
}

TreeNode *morris_inorder(TreeNode *root)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    TreeNode* dummy=new TreeNode(-1);
    TreeNode* p=dummy;

    TreeNode* curr=root;
    while(curr!=nullptr)
    {
        TreeNode* l=curr->left;
        if(l==nullptr)
        {
            //cout<<curr->val;
            p->right=curr;
            curr->left=p;
            p=curr;
            curr=curr->right;

        }
        else
        {
            TreeNode* rmnode=giverm(l,curr);
            if(rmnode->right==nullptr)
            {
                rmnode->right=curr;
                curr=curr->left;
            }
            else
            {
                rmnode->right=nullptr;
                p->right = curr;
                curr->left = p;
                p = curr;
                curr=curr->right;
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