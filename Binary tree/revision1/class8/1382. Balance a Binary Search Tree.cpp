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

int get_bal(TreeNode *root)
{
    int lh = height(root->left);
    int rh = height(root->right);

    return lh - rh;
}

TreeNode *get_rotation(TreeNode *root)
{
    if (get_bal(root) >= 2)
    {
        // ll or lr
        if (get_bal(root->left) >= 1) // ll
        {
            return right_rotation(root);
        }
        else // lr
        {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }
    else if (get_bal(root) <= -2)
    {
        // rr or rl
        if (get_bal(root->right) <= -1) // rr
        {
            return left_rotation(root);
        }
        else // rl
        {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }
    }
    return root;
}
TreeNode *left_rotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *bkl = B->left;
    B->left = A;
    A->right = bkl;
    B->left = get_rotation(A);
    return get_rotation(B);
}

TreeNode *right_rotation(TreeNode *A)
{
    TreeNode *B = A->left;
    TreeNode *bkr = B->right;
    B->right = A;
    A->left = bkr;

    B->right = get_rotation(A);

    return get_rotation(B);
}


TreeNode *balanceBST_help(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    root->left = balanceBST_help(root->left);
    root->right = balanceBST_help(root->right);

    return get_rotation(root);
}

TreeNode *balanceBST(TreeNode *root)
{
    return balanceBST_help(root);
}

int main()
{
    return 0;
}