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

class nodeInfo
{
public:
    int ht = 0;
    bool isBalanced = true;
};

nodeInfo isBalancedHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        nodeInfo base;
        return base;
    }

    nodeInfo leftAns = isBalancedHelp(root->left);
    if (!leftAns.isBalanced)
        return leftAns;

    nodeInfo rightAns = isBalancedHelp(root->right);
    if (!rightAns.isBalanced)
        return rightAns;

    nodeInfo currAns;
    if (abs(leftAns.ht - rightAns.ht) > 1)
        currAns.isBalanced = false;
    else
        currAns.ht = max(leftAns.ht, rightAns.ht) + 1;
    return currAns;
}

bool isBalanced(TreeNode *root)
{
    return isBalancedHelp(root).isBalanced;
}

int main()
{
    return 0;
}