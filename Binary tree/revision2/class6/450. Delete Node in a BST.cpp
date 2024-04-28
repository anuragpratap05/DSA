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

int getMinNode(TreeNode *node)
{
    while (node->left)
        node = node->left;
    return node->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == key)
    {
        if (root->left == nullptr or root->right == nullptr)
        {
            return root->left == nullptr ? root->right : root->left;
        }
        else
        {
            int minEle = getMinNode(root->right);
            root->val = minEle;
            root->right = deleteNode(root->right, minEle);
            return root;
        }
    }
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    return root;
}

int main()
{
    return 0;
}