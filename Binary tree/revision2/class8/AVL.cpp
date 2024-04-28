#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int ht = 0;
    int bal = 0;
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

int getMinEleFromRight(TreeNode *node)
{
    while (node->left)
        node = node->left;
    return node->val;
}

void updateHtAndBalOfRoot(TreeNode *node)
{
    int leftHt = node->left ? node->left->ht : -1;
    int rightHt = node->right ? node->right->ht : -1;

    node->ht = max(leftHt, rightHt) + 1;
    node->bal = leftHt - rightHt;
}

TreeNode *rightRotation(TreeNode *A)
{
    TreeNode *B = A->left;
    TreeNode *rightSubTreeOfB = B->right;
    B->right = A;
    A->left = rightSubTreeOfB;
    updateHtAndBalOfRoot(A);
    updateHtAndBalOfRoot(B);
    return B;
}

TreeNode *leftRotation(TreeNode *A)
{
    TreeNode *B = A->right;
    TreeNode *leftSubTreeOfB = B->left;
    B->left = A;
    A->right = leftSubTreeOfB;
    updateHtAndBalOfRoot(A);
    updateHtAndBalOfRoot(B);
    return B;
}

TreeNode *rotateIfUnbalanced(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    updateHtAndBalOfRoot(root);
    if (root->bal > 1) // ll  ,  lr
    {
        if (root->left->bal >= 0) // ll
        {
            return rightRotation(root);
        }
        else // lr
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (root->bal < -1) // rr  , rl
    {
        if (root->right->bal <= 0) // rr
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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return rotateIfUnbalanced(root);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == key)
    {
        if (root->left == nullptr or root->right == nullptr)
        {
            return root->left == nullptr ? root->right : root->left;
        }
        else
        {
            int minEle = getMinEleFromRight(root->right);
            root->val = minEle;
            root->right = deleteNode(root->right, minEle);
            return rotateIfUnbalanced(root);
        }
    }
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    return rotateIfUnbalanced(root);
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

    // cout << "Now deletion start" << endl;
    // vector<int> toBeDeletd = {6, 95, 80, 89, 98, 99, 66, 29, 51, 71, 40, 94};
    // for (int val : toBeDeletd)
    // {
    //     root = deleteNode(root, val);
    //     cout << "After deleting " << val << endl;
    //     prettyPrintTree(root);
    // }
    if (root == nullptr)
    {
        cout << "Whole tree deleted  ";
    }
    return 0;
}