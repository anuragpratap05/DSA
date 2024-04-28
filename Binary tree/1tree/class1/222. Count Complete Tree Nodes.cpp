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

int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int a = countNodes(root->left);
    int b = countNodes(root->right);
    return a + b + 1;
}

int main()
{
    return 0;
}