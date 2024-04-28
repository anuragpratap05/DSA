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

class p
{
public:
    int ovmax = 0;
    int lm = 0;
    int rm = 0;
};

class p2
{
public:
    int forw = -1;
    int backw = -1;
    int ovmax = -1;
};

// my method

p longestZigZag_help(TreeNode *root)
{
    if (root == nullptr or (root->left == nullptr and root->right == nullptr))
    {
        p x;
        return x;
    }

    p left = longestZigZag_help(root->left);
    p right = longestZigZag_help(root->right);

    p myp;
    if(root->left!=nullptr)
    {
        left.rm += 1;
    }
    if(root->right!=nullptr)
    {
        right.lm += 1;
    }
    myp.ovmax = max(left.ovmax, right.ovmax);
    myp.ovmax = max(myp.ovmax, max(left.lm, left.rm));
    myp.ovmax = max(myp.ovmax, max(right.lm, right.rm));

    if(root->left!=nullptr and left.lm>0)
    {
        left.lm = 1;
    }
    if(root->right!=nullptr and right.rm>0)
    {
        right.rm = 1;
    }
    myp.lm = max(left.lm, left.rm);
    myp.rm = max(right.lm, right.rm);
    cout << myp.ovmax << " " << myp.lm << " "<< myp.rm << endl;
    return myp;
}

int longestZigZag(TreeNode *root)
{
    return longestZigZag_help(root).ovmax;
}


// sir method

p2 longestZigZag2_help(TreeNode *root)
{
    if(root==nullptr)
    {
        p2 x;
        return x;
    }

    p2 left = longestZigZag2_help(root->left);
    p2 right = longestZigZag2_help(root->right);

    p2 myp;
    myp.forw = left.backw + 1;
    myp.backw = right.forw + 1;
    myp.ovmax = max(left.ovmax, right.ovmax);
    myp.ovmax = max(myp.ovmax, max(myp.forw, myp.backw));
    return myp;
}

int longestZigZag2(TreeNode *root)
{
    return longestZigZag2_help(root).ovmax;
}

int main()
{
    return 0;
}