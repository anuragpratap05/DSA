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

TreeNode *getRightMostNode(TreeNode *node, TreeNode *curr)
{
    if (node == nullptr)
        return nullptr;
    while (node->right and node->right != curr)
    {
        node = node->right;
    }
    return node;
}

vector<int> inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> ans;

    TreeNode *curr = root;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *rmNode = getRightMostNode(l, curr);
            if (rmNode->right == nullptr)
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmNode->right = nullptr;
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