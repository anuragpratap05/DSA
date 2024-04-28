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

TreeNode *giveit(TreeNode *root, TreeNode *c)
{
    while(root->right!=nullptr)
    {
        root=root->right;
        if(root==c)
        {
            return root;
        }
    }
    return root;
}

vector<int> morris_inorder(TreeNode *root,vector<int>& ans)
{
    TreeNode *c = root;
    TreeNode *p = nullptr;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            ans.push_back(c->val);
            p = c;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l,c);
            if(rmnode==c)
            {
                p->right=nullptr;
                ans.push_back(c->val);
                p=c;
                c=c->right;
            }
            else
            {
                rmnode->right=c;
                c=c->left;
            }
        }
    }
    return ans;
}

void morris_preorder(TreeNode *root)
{
    TreeNode *c = root;
    TreeNode *p = nullptr;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            //cout << c->val;
            p = c;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l, c);
            if (rmnode == c)
            {
                p->right = nullptr;
                //cout << c->val;
                p = c;
                c = c->right;
                // if(c!=nullptr)
                // {
                //     cout<<c->val;
                // }
            }
            else
            {
                rmnode->right = c;
                cout<<c->val;
                c = c->left;
            }
        }
    }
}

int main()
{
    return 0;
}