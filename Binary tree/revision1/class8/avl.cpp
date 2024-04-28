#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    int height = 0;
    int b = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};



void update(TreeNode *root)
{
    int lh = (root->left == nullptr ? -1 : root->left->height);
    int rh = (root->right == nullptr ? -1 : root->right->height);
    root->b = lh - rh;
    root->height = max(lh, rh) + 1;
}

TreeNode* right_rotation(TreeNode* A)
{
    TreeNode* B = A->left;
    TreeNode* bkr = B->right;
    B->right = A;
    A->left = bkr;
    return B;
     
}

TreeNode *left_rotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *bkl = B->left;
    B->left = A;
    A->right = bkl;
    update(A);
    update(B);
    return B;
}
TreeNode* get_rotation(TreeNode *root)
{
    update(root);
    if (root->b == 2) // ll or lr
    {
        if (root->left->b == 1) // ll
        {
            return right_rotation(root);
        }
        else // lr
        {
        }
    }
    else if (root->b == -2) // rr or rl
    {

        if (root->right->b == 1) // rl
        {
        }
        else//rr
        {
            return left_rotation(root);
        }
    }
    return root;
}

TreeNode *insert(TreeNode *root, int Key)
{
    if (root == nullptr)
    {
        TreeNode *x = new TreeNode(Key);
        return x;
    }
    if (root->val < Key)
    {
        root->right = insert(root->right, Key);
    }
    else if (root->val > Key)
    {
        root->left = insert(root->left, Key);
    }
    return get_rotation(root);
}

int main()
{
    return 0;
}