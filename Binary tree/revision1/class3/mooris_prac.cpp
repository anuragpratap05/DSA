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
TreeNode *get_right_monst(TreeNode* root,TreeNode* c)
{
    if(root==nullptr or root->right==nullptr or root->right==c)
    {
        return root;
    }
    while(root->right!=nullptr and root->right!=c)
    {
        root = root->right;
    }
    return root;
}

void morris_inorder(TreeNode *root)
{
    TreeNode *c = root;
    while (c != nullptr)
    {
        TreeNode *l = c->left;
        if (l == nullptr)
        {
            cout << c->val;
            c = c->right;
        }
        else
        {
            TreeNode *rm = get_right_monst(l, c);
            if(rm->right==nullptr)
            {
                rm->right = c;
                c = c->left;
            }
            else
            {
                rm->right = nullptr;
                cout << c->val;
                c = c->right;
            }
        }
    }
}

int main()
{
    return 0;
}