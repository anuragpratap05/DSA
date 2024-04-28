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
int morris_inorder(TreeNode *root, int k)
{
    TreeNode *c = root;
    TreeNode *p = nullptr;
    int rv=-1;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            //ans.push_back(c->val);
            k--;
            if(k==0)
            {
                rv=c->val;
            }
            p = c;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l, c);
            if (rmnode == c)
            {
                p->right = nullptr;
                //ans.push_back(c->val);
                k--;
                if (k == 0)
                {
                    rv = c->val;
                }
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
    return rv;
}
int kthSmallest(TreeNode *root, int k)
{
    return morris_inorder(root,k);
}

int main()
{
    return 0;
}