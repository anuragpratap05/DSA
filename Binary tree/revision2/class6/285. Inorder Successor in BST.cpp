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

TreeNode *rightMostNode(TreeNode *node, TreeNode *curr)
{
    while (node->right != nullptr and node->right != curr)
        node = node->right;
    return node;
}

void morrisInorder(TreeNode *root, TreeNode *p, TreeNode *&succ)
{
    if (root == nullptr)
        return;
    TreeNode *prev = nullptr;

    TreeNode *curr = root;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            if (prev == p)
                succ = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr)
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmNode->right = nullptr;
                if (prev == p)
                    succ = curr;
                prev = curr;
                curr = curr->right;
            }
        }
    }
}

TreeNode *leftMostNode(TreeNode *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

TreeNode *inorderSuccessorBst(TreeNode *root, TreeNode *p)
{
    TreeNode *succ = nullptr;

    TreeNode *curr = root;
    while (curr != p)
    {
        if (curr->val > p->val)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    // curr = curr->val > p->val ? curr->left : curr->right;

    if (curr->right == nullptr)
    {
        return succ;
    }
    else
    {
        return leftMostNode(curr->right);
    }
}

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    // TreeNode *succ = nullptr;
    // morrisInorder(root, p, succ); // O (n)
    // return succ;

    return inorderSuccessorBst(root,p);
}

int main()
{
    return 0;
}