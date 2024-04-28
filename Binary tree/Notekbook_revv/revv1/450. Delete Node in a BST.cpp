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

TreeNode *leftMostNode(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == key)
    {
        if (root->left == nullptr or root->right == nullptr)
            return root->left == nullptr ? root->right : root->left;
        else
        {
            TreeNode *leftNode = leftMostNode(root->right);
            swap(root->val, leftNode->val);
            root->right = deleteNode(root->right, leftNode->val);
            return root;
        }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}

int main()
{
    return 0;
}