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

int getHeightOfNd(TreeNode *root)
{
    if (root == nullptr)
        return -1;
    int leftHt = getHeightOfNd(root->left);
    int rightHt = getHeightOfNd(root->right);
    return max(leftHt, rightHt) + 1;
}

int getBalanceOfNd(TreeNode *root)
{
    int leftHt = getHeightOfNd(root->left);
    int rightHt = getHeightOfNd(root->right);
    return leftHt - rightHt;
}

TreeNode *rightRotation(TreeNode *A)
{
    TreeNode *B = A->left;
    TreeNode *rightSubTreeOfB = B->right;
    B->right = A;
    A->left = rightSubTreeOfB;
    B->right = rotateIfUnbalanced(A);
    return rotateIfUnbalanced(B);
}

TreeNode *leftRotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *leftSubTreeOfB = B->left;
    B->left = A;
    A->right = leftSubTreeOfB;
    B->left = rotateIfUnbalanced(A);
    return rotateIfUnbalanced(B);
}

TreeNode *rotateIfUnbalanced(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    int rootBal = getBalanceOfNd(root);
    if (rootBal > 1) // ll  ,  lr
    {
        if (getBalanceOfNd(root->left) >= 0) // ll
        {
            return rightRotation(root);
        }
        else // lr
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (rootBal < -1) // rr  , rl
    {
        if (getBalanceOfNd(root->right) <= 0) // rr
        {
            return leftRotation(root);
        }
        else // rl
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}

TreeNode *balanceBST(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    root->left = balanceBST(root->left);
    root->right = balanceBST(root->right);

    return rotateIfUnbalanced(root);
}

int main()
{
    return 0;
}