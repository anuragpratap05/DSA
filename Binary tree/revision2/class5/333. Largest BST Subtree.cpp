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

class rootInfo
{
public:
    bool isBst = true;
    int minVal = 1e9;
    int maxVal = -1e9;
    int nodes = 0;
};

rootInfo largestBSTSubtreeHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        rootInfo base;
        return base;
    }

    rootInfo leftAns = largestBSTSubtreeHelp(root->left);

    rootInfo rightAns = largestBSTSubtreeHelp(root->right);

    rootInfo rootAns;
    if (!leftAns.isBst or !rightAns.isBst or leftAns.maxVal >= root->val or rightAns.minVal <= root->val)
    {
        rootAns.isBst = false;
        rootAns.nodes = max(leftAns.nodes, rightAns.nodes);
    }
    else
    {
        rootAns.minVal = min(leftAns.minVal, root->val);
        rootAns.maxVal = max(rightAns.maxVal, root->val);
        rootAns.nodes = leftAns.nodes + rightAns.nodes + 1;
    }
    return rootAns;
}

int largestBSTSubtree(TreeNode *root)
{
    return largestBSTSubtreeHelp(root).nodes;
}

int main()
{
    return 0;
}