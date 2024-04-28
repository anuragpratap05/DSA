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
int height(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}
// O(n^2)
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int ld = diameterOfBinaryTree(root->left);
    int rd = diameterOfBinaryTree(root->right);

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh + rh + 2, max(ld, rd));
}
// o(n)

class p
{
public:
    int dia = 0;
    int h = -1;
};

p diameterOfBinaryTree2_help(TreeNode *root)
{
    if (root == nullptr)
    {
        p x;
        return x;
    }

    p l = diameterOfBinaryTree2_help(root->left);
    p r = diameterOfBinaryTree2_help(root->right);

    p myp;
    myp.dia = max(l.dia, r.dia);
    myp.h = max(l.h, r.h) + 1;
    myp.dia = max(myp.dia, l.h + r.h + 2);
    return myp;
}
int diameterOfBinaryTree2(TreeNode *root)
{
    return diameterOfBinaryTree2_help(root).dia;
}

int main()
{
    return 0;
}