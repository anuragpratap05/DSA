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
    int maxTreeSum = -1e8;
    int maxPathSum = 0;
};

NodeInfo maxPathSumHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        NodeInfo base;
        return base;
    }

    NodeInfo left = maxPathSumHelp(root->left);
    NodeInfo right = maxPathSumHelp(root->right);

    NodeInfo curNode;

    curNode.maxTreeSum = max(root->val, max(left.maxPathSum + right.maxPathSum + root->val, max(root->val + max(left.maxPathSum, right.maxPathSum), max(left.maxTreeSum, right.maxTreeSum))));

    curNode.maxPathSum = max(root->val, root->val + max(left.maxPathSum, right.maxPathSum));

    return curNode;
}

int maxPathSum(TreeNode *root)
{
    return maxPathSumHelp(root).maxTreeSum;
}

int main()
{
    return 0;
}