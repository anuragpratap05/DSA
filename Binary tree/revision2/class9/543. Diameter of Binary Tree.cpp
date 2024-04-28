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

class diaAndHt
{
public:
    int maxHt = -1, maxDia = -1;
};

diaAndHt diameterOfBinaryTreeHelp(TreeNode *root)
{
    if (root == nullptr)
    {
        diaAndHt base;
        return base;
    }

    diaAndHt leftNd = diameterOfBinaryTreeHelp(root->left);
    diaAndHt rightNd = diameterOfBinaryTreeHelp(root->right);

    diaAndHt curNd;

    curNd.maxHt = max(leftNd.maxHt, rightNd.maxHt) + 1;
    curNd.maxDia = max(max(leftNd.maxDia, rightNd.maxDia), leftNd.maxHt + rightNd.maxHt + 2);
    return curNd;
}

int diameterOfBinaryTree(TreeNode *root)
{
    return diameterOfBinaryTreeHelp(root).maxDia;
}

int main()
{
    return 0;
}