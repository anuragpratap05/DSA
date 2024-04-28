#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};



int getMinEleFromRight(Node *node)
{
    while (node->left)
        node = node->left;
    return node->data;
}

void updateHtOfRoot(Node *node)
{
    int leftHt = node->left ? node->left->height : 0;
    int rightHt = node->right ? node->right->height : 0;

    node->height = max(leftHt, rightHt) + 1;
}

int getBalnaceFactor(Node *node)
{
    int leftHt = node->left ? node->left->height : 0;
    int rightHt = node->right ? node->right->height : 0;

    return leftHt - rightHt;
}

Node *rightRotation(Node *A)
{
    Node *B = A->left;
    Node *rightSubTreeOfB = B->right;
    B->right = A;
    A->left = rightSubTreeOfB;
    updateHtOfRoot(A);
    updateHtOfRoot(B);
    return B;
}

Node *leftRotation(Node *A)
{
    Node *B = A->right;
    Node *leftSubTreeOfB = B->left;
    B->left = A;
    A->right = leftSubTreeOfB;
    updateHtOfRoot(A);
    updateHtOfRoot(B);
    return B;
}

Node *rotateIfUnbalanced(Node *root)
{
    if (root == nullptr)
        return nullptr;
    updateHtOfRoot(root);
    int rootBal = getBalnaceFactor(root);
    if (rootBal > 1) // ll  ,  lr
    {
        if (getBalnaceFactor(root->left) >= 0) // ll
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
        if (getBalnaceFactor(root->right) <= 0) // rr
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

Node *deleteNodeOfBST(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (key == root->data)
    {
        if (root->left == nullptr or root->right == nullptr)
        {
            return root->left == nullptr ? root->right : root->left;
        }
        else
        {
            int minEle = getMinEleFromRight(root->right);
            root->data = minEle;
            root->right = deleteNodeOfBST(root->right, minEle);
            return rotateIfUnbalanced(root);
        }
    }

    if (key < root->data)
        root->left = deleteNodeOfBST(root->left, key);
    else if (key > root->data)
        root->right = deleteNodeOfBST(root->right, key);

    return rotateIfUnbalanced(root);
}

Node *deleteNode(Node *root, int data)
{

    return deleteNodeOfBST(root, data);
}