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

int morrisInorder(TreeNode *root, int k)
{
    TreeNode *curr = root;
    int ans;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            // cout << curr->val;
            if (--k == 0)
                ans = curr->val;
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
                // cout << curr->val;
                if (--k == 0)
                    ans = curr->val;
                curr = curr->right;
            }
        }
    }
    return ans;
}
int kthSmallest(TreeNode *root, int k)
{
    return morrisInorder(root, k);
}

int main()
{
    return 0;
}