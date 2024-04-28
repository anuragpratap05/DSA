#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0, ht = 0, bal = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true)
{
    if (node == nullptr)
    {
        cout << "Empty tree";
        return;
    }

    if (node->right)
    {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left)
    {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

void updateHtAndBal(TreeNode *root)
{
    int lh = root->left == nullptr ? -1 : root->left->ht;
    int rh = root->right == nullptr ? -1 : root->right->ht;

    root->ht = max(lh, rh) + 1;
    root->bal = lh - rh;
}

TreeNode *rotateRight(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    TreeNode *A = root;
    TreeNode *B = root->left;
    TreeNode *bkr = B->right;

    B->right = A;
    A->left = bkr;
    updateHtAndBal(A);
    updateHtAndBal(B);
    return B;
}

TreeNode *rotateLeft(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    TreeNode *A = root;
    TreeNode *B = A->right;
    TreeNode *bkl = B->left;

    B->left = A;
    A->right = bkl;
    updateHtAndBal(A);
    updateHtAndBal(B);
    return B;
}

TreeNode *rotateIfunbalanced(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    updateHtAndBal(root);

    if(root->bal>1)//ll lr
    {
        if(root->left->bal>=0)//ll
        {
            return rotateRight(root);
        }
        else// lr
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    else if(root->bal<-1)// rr , rl
    {
        if(root->right->bal>=0)// rr
        {
            return rotateLeft(root);
        }
        else//rl
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return rotateIfunbalanced(root);
}

int main()
{
    TreeNode *root = nullptr;
    vector<int> vec = {80, 51, 95, 29, 66, 89, 99, 6, 40, 71, 94, 98};
    for (int val : vec)
    {
        root = insertIntoBST(root, val);
    }
    prettyPrintTree(root);
    return 0;
}