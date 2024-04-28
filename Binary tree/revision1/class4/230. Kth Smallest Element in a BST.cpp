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

TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
{
    while (root->right != nullptr and root->right != curr)
    {
        root = root->right;
    }
    return root;
}

int morris_inorder(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return 0;
    }

    TreeNode *curr = root;
    int rv;

    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {
            // ans.push_back(curr->val);
            if (--k == 0)
            {
                rv = curr->val;
            }
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnode = rightmost_node(left, curr);
            if (rmnode->right == nullptr)
            {
                rmnode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnode->right = nullptr;
                if (--k == 0)
                {
                    rv = curr->val;
                }
                curr = curr->right;
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