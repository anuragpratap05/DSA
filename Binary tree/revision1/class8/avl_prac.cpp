#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    int b = 0;
    int h = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

void update_height(TreeNode *root)
{
    int lh = (root->left == nullptr ? -1 : root->left->h);
    int rh = (root->right == nullptr ? -1 : root->right->h);
    root->h = max(lh, rh)+1;
    root->b = lh - rh;
}
TreeNode *left_rotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *bkl = B->left;
    B->left = A;
    A->right = bkl;
    update_height(A);
    update_height(B);
    return B;
}

TreeNode *right_rotation(TreeNode *A)
{
    TreeNode *B = A->left;
    TreeNode *bkr = B->right;
    B->right = A;
    A->left = bkr;
    update_height(A);
    update_height(B);
    return B;
}

TreeNode *getrotation(TreeNode *root)
{
    update_height(root);
    if (root->b == 2)
    {
        // ll or lr
        if (root->left->b == 1) // ll
        {
            return right_rotation(root);
        }
        else // lr
        {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }
    else if (root->b == -2)
    {
        // rr or rl
        if (root->right->b == -1) // rr
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
    return getrotation(root);
}

TreeNode *get_leftmost(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == key)
    {
        if (root->left == nullptr and root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left == nullptr or root->right == nullptr)
        {
            return (root->left == nullptr ? root->right : root->left);
        }
        else
        {
            TreeNode *x = get_leftmost(root->right);
            root->val = x->val;
            root->right = deleteNode(root->right, x->val);
            return getrotation(root);
        }
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
        root->left = deleteNode(root->left, key);

    return getrotation(root);
}

void display(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    string str = "";
    str += (root->left != nullptr ? to_string(root->left->val) : ".");
    str += (" -> " + to_string(root->val) + " <- ");
    str += (root->right != nullptr ? to_string(root->right->val) : ".");
    cout << str << endl;
    display(root->left);
    display(root->right);
}

int main()
{
    TreeNode *root = nullptr;
    for (int i = 1; i <= 15; i++)
    {
        root = insert(root, i*10);
    }
    display(root);
    return 0;
}