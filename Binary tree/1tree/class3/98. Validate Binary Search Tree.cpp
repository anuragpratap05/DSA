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

TreeNode *giveit(TreeNode *root, TreeNode *c)
{
    while (root->right != nullptr)
    {
        root = root->right;
        if (root == c)
        {
            return root;
        }
    }
    return root;
}

bool morris_inorder(TreeNode *root)
{
    TreeNode *c = root;
    TreeNode *p = nullptr;
    int prev=INT_MIN;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            //ans.push_back(c->val);
            if(prev>=c->val)
            {
                return false;
            }
            prev=c->val;
            p = c;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l, c);
            if (rmnode == c)
            {
                p->right = nullptr;
                if (prev >= c->val)
                {
                    return false;
                }
                prev = c->val;
                //ans.push_back(c->val);
                p = c;
                c = c->right;
            }
            else
            {
                rmnode->right = c;
                c = c->left;
            }
        }
    }
    return true;
}


bool isValidBST(TreeNode *root)
{

}

int main()
{
    return 0;
}