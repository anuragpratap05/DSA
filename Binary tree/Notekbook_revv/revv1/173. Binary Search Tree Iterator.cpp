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

class BSTIterator
{
    TreeNode *curr = nullptr;
    TreeNode *getRightMostNode(TreeNode *node)
    {
        if (node == nullptr)
            return nullptr;
        while (node->right != nullptr and node->right != curr)
            node = node->right;
        return node;
    }

    void goToExtremeLeft()
    {
        if (curr == nullptr)
            return;
        while (curr->left != nullptr)
        {
            TreeNode *l = curr->left;
            TreeNode *rmnd = getRightMostNode(l);
            rmnd->right = curr;
            curr = curr->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
    }

    int next()
    {
        TreeNode *l = curr->left;
        int ans;
        if (l == nullptr)
        {
            ans = curr->val;
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnd = getRightMostNode(l);
            if (rmnd->right == nullptr)
            {
                goToExtremeLeft();
                ans = curr->val;
                curr = curr->right;
            }
            else
            {
                rmnd->right = nullptr;
                ans = curr->val;
                curr = curr->right;
            }
        }
        return ans;
    }

    bool hasNext()
    {
        return curr != nullptr;
    }
};

int main()
{
    return 0;
}