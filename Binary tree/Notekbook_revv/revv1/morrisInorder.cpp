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
    while (node->right != nullptr and node->right != curr)
        node = node->right;
    return node;
}

vector<int> morrisInorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            // cout << curr->val;
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnd = getRightMostNode(l, curr);
            if (rmnd->right == nullptr)
            {
                rmnd->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnd->right = nullptr;
                // cout << curr->val;
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