#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    void updateHtOfRoot(Node *node)
    {
        int leftHt = node->left ? node->left->height : -1;
        int rightHt = node->right ? node->right->height : -1;

        node->height = max(leftHt, rightHt) + 1;
    }

    int getBalnaceFactor(Node *node)
    {
        int leftHt = node->left ? node->left->height : -1;
        int rightHt = node->right ? node->right->height : -1;

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

    Node *insertIntoBST(Node *root, int data)
    {
        if (root == nullptr)
        {
            Node *newNd = new Node(data);
            // newNd->data = data;
            newNd->height = 0;
            newNd->left = nullptr;
            newNd->right = nullptr;
            return newNd;
        }
        if (data == root->data)
        {
            return root;
        }
        else if (data < root->data)
            root->left = insertIntoBST(root->left, data);
        else
            root->right = insertIntoBST(root->right, data);
        return rotateIfUnbalanced(root);
    }
    Node *insertToAVL(Node *node, int data)
    {
        return insertIntoBST(node, data);
    }
};