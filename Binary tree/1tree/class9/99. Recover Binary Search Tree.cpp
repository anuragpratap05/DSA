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
    while (root->right != nullptr and root->right != c)
    {
        root = root->right;
    }
    return root;
}

void morris_inorder(TreeNode *root)
{
    TreeNode *c = root;
    TreeNode* a=nullptr;
    TreeNode *p = nullptr;
    TreeNode *b = nullptr;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            if(p!=nullptr and c->val<p->val)
            {
                if(a==nullptr)
                {
                    a=p;
                }
                b=c;
            }
            p=c;
            cout << c->val;
            c = c->right;
        }
        else
        {
            TreeNode *rmnode = giveit(l, c);
            if (rmnode->right == nullptr)
            {
                rmnode->right = c;
                c = c->left;
            }
            else
            {
                rmnode->right = nullptr;
                if (p != nullptr and c->val < p->val)
                {
                    if (a == nullptr)
                    {
                        a = p;
                    }
                    b = c;
                }
                p = c;
                cout << c->val;
                c = c->right;
            }
        }
    }
    int temp=a->val;
    a->val=b->val;
    b->val=temp;
}

void recoverTree(TreeNode *root)
{
    return morris_inorder(root);
}

int main()
{
    return 0;
}