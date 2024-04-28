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
TreeNode *get_leftmost(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == key)
    {
        if (root->left == nullptr and root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left == nullptr or root->right == nullptr)
        {
            return (root->left == nullptr ? root->right : root->left);
        }
        else
        {
            TreeNode *x = get_leftmost(root->right);
            root->val = x->val;
            root->right = deleteNode(root->right, x->val);
            return root;
        }
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
        root->left = deleteNode(root->left, key);

    return root;
}
int main()
{
    return 0;
}