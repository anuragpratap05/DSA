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

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh, rh) + 1;
}

int main()
{
    return 0;
}