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
    if(root==nullptr)
    {
        return root;
    }
    TreeNode* curr=root;
    while(curr!=nullptr)
    {
        if(curr->val>p->val and curr->val>q->val)
        {
            curr=curr->left;
        }

        else if (curr->val < p->val and curr->val < q->val)
        {
            curr = curr->right;
        }
        else
        {
            break;
        }
    }
    return curr;
}

int main()
{
    return 0;
}