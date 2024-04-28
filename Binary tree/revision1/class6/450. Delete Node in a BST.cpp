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

TreeNode *leftmost(TreeNode *root)
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
        return root;
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
        TreeNode *l = leftmost(root->right);
        root->val = l->val;
        root->right = deleteNode(root->right, l->val);
        return root;
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        root->left = deleteNode(root->left, key);
    }
    return root;
}

int main()
{
    return 0;
}