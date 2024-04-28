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

class NodeInfo
{
public:
    long long int maxLfToLfSum = -1;
    long long int MaxPathSum = 0;
};
NodeInfo findMaxSumPathHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        NodeInfo base;
        return base;
    }

    NodeInfo left = findMaxSumPathHelp(root->left);
    NodeInfo right = findMaxSumPathHelp(root->right);

    NodeInfo curNode;
    curNode.MaxPathSum = root->val + max(left.MaxPathSum, right.MaxPathSum);

    if (root->left and root->right)
    {
        curNode.maxLfToLfSum = max(left.MaxPathSum + root->val + right.MaxPathSum, max(left.maxLfToLfSum, right.maxLfToLfSum));
    }
    else
    {
        curNode.maxLfToLfSum = root->right == nullptr ? left.maxLfToLfSum : right.maxLfToLfSum;
    }
    return curNode;
}

long long int findMaxSumPath(TreeNode *root)
{
    return findMaxSumPathHelp(root).maxLfToLfSum;
}

int main()
{
    return 0;
}