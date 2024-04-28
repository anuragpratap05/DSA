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

TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
{
    while (root->right != nullptr and root->right != curr)
    {
        root = root->right;
    }
    return root;
}

vector<int> morris_inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {
            ans.push_back(curr->val);
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
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}