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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while(root!=nullptr)
    {
        if(q->val<root->val and p->val<root->val)
        {
            root=root->left;
        }
        else if (q->val > root->val and p->val > root->val)
        {
            root=root->right;
        }
        else{
            return root;
        }
        
    }
    return nullptr;
}

int main()
{
    return 0;
}