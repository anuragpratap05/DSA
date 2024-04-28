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

class trplet
{
public:
    long min = 1e13;
    bool isBalanced = true;
    long max = -1e13;
};

trplet isValidBSTHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        trplet base;
        return base;
    }
    trplet myTrp;
    trplet left = isValidBSTHelp(root->left);
    if (!left.isBalanced or left.max > root->val)
    {
        myTrp.isBalanced = false;
        return myTrp;
    }
    trplet right = isValidBSTHelp(root->right);
    if (!right.isBalanced or right.min < root->val)
    {
        myTrp.isBalanced = false;
        return myTrp;
    }
    myTrp.min = left.min < root->val ? left.min : root->val;
    myTrp.max = right.max > root->val ? right.max : root->val;
    return myTrp;
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelp(root).isBalanced;
}

int main()
{
    return 0;
}