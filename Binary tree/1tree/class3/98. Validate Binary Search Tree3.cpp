#include<bits/stdc++.h>
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

class bstpair
{
public:
    bool is_bst;
    long lmin;
    long rmax;
    bstpair()
    {
        is_bst = false;
        lmin = -373;
        rmax = -73;
    }
};

bstpair isValidBST2(TreeNode *root)
{
    if (root == nullptr)
    {
        bstpair base;
        base.is_bst = true;
        base.lmin = 1e13;
        base.rmax = -1e13;
        return base;
    }
    // bstpair mypair;
    bstpair left = isValidBST2(root->left);
    if (!left.is_bst)
    {
        return bstpair();
    }
    bstpair right = isValidBST2(root->right);
    if (!right.is_bst)
    {
        return bstpair();
    }
    bstpair mypair;
    if (left.lmin < right.lmin)
    {
        if (left.lmin < root->val)
        {
            mypair.lmin = left.lmin;
        }
        else
        {
            mypair.lmin = root->val;
        }
    }
    else
    {
        if (right.lmin < root->val)
        {
            mypair.lmin = right.lmin;
        }
        else
        {
            mypair.lmin = root->val;
        }
    }

    if (left.rmax > right.rmax)
    {
        if (left.rmax > root->val)
        {
            mypair.rmax = left.rmax;
        }
        else
        {
            mypair.rmax = root->val;
        }
    }
    else
    {
        if (right.rmax > root->val)
        {
            mypair.rmax = right.rmax;
        }
        else
        {
            mypair.rmax = root->val;
        }
    }

    mypair.is_bst = ((root->val > left.rmax and root->val < right.lmin and left.is_bst and right.is_bst) ? true : false);
    return mypair;
}

bool isValidBST(TreeNode *root)
{
    // display(root);
    bstpair rp = isValidBST2(root);
    return rp.is_bst;
}

int main()
{
    return 0;
}