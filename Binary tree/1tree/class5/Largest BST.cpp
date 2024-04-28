#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
class bstpair
{
public:
    bool is_bst;
    long lmin;
    long rmax;
    int size;
    bstpair()
    {
        is_bst = false;
        lmin = -373;
        rmax = -73;
        size = -1;
    }
};

bstpair isdataidBST2(Node *root)
{
    if (root == nullptr)
    {
        bstpair base;
        base.is_bst = true;
        base.lmin = 1e13;
        base.rmax = -1e13;
        base.size = 0;

        return base;
    }
    // bstpair mypair;
    bstpair left = isdataidBST2(root->left);

    bstpair right = isdataidBST2(root->right);

    bstpair mypair;
    if (left.lmin < right.lmin)
    {
        if (left.lmin < root->data)
        {
            mypair.lmin = left.lmin;
        }
        else
        {
            mypair.lmin = root->data;
        }
    }
    else
    {
        if (right.lmin < root->data)
        {
            mypair.lmin = right.lmin;
        }
        else
        {
            mypair.lmin = root->data;
        }
    }

    if (left.rmax > right.rmax)
    {
        if (left.rmax > root->data)
        {
            mypair.rmax = left.rmax;
        }
        else
        {
            mypair.rmax = root->data;
        }
    }
    else
    {
        if (right.rmax > root->data)
        {
            mypair.rmax = right.rmax;
        }
        else
        {
            mypair.rmax = root->data;
        }
    }

    mypair.is_bst = ((root->data > left.rmax and root->data < right.lmin and left.is_bst and right.is_bst) ? true : false);

    if (mypair.is_bst)
    {
        mypair.size = (left.size + right.size) + 1;
    }
    else
    {
        mypair.size = max(left.size, right.size);
    }
    return mypair;
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    // Your code here
    // display(root);
    return isdataidBST2(root).size;
}

int main()
{
    return 0;
}