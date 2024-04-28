#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
    }
};

int i;
Node *constructTree(int post[], int lr, int rr)
{
    if (i < 0 or lr >= post[i] or rr <= post[i])
        return nullptr;

    Node *root = new Node(post[i]);
    i--;
    root->right = constructTree(post, root->data, rr);
    root->left = constructTree(post, lr, root->data);
    return root;
}

Node *constructTree(int post[], int size)
{
    i = size - 1;
    return constructTree(post, -1e9, 1e9);
}

int main()
{
    return 0;
}