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

vector<int> inorderTraversal(TreeNode *root)
{
    return morris_inorder(root);
}










vector<int> morris_preorder(TreeNode *root)
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
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                rmnode->right = nullptr;
                
                curr = curr->right;
            }
        }
    }

    return ans;
}

vector<int> preorder_Traversal(TreeNode *root)
{
    return morris_preorder(root);
}

int main()
{
    return 0;
}