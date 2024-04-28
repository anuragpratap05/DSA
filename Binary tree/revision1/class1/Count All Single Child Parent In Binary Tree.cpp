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

int countExactlyOneChild(TreeNode *node)
{
    if (node == nullptr or (node->left == nullptr and node->right == nullptr))
    {
        return 0;
    }

    int lc = countExactlyOneChild(node->left);

    int rc = countExactlyOneChild(node->right);

    if (node->left == nullptr or node->right == nullptr)
    {
        return lc+rc+1;
    }
    return lc+rc;
}

int main()
{
    return 0;
}