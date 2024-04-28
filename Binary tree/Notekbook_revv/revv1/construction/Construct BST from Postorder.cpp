#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data=data;
    }
};

int idx;

Node *constructTree(int post[], int lr, int rr)
{
    if (idx < 0 or post[idx] <= lr or post[idx] >= rr)
        return nullptr;
    Node *root = new Node(post[idx--]);
    root->right = constructTree(post, root->data, rr);
    root->left = constructTree(post, lr, root->data);
    return root;
}

Node *constructTree(int post[], int size)
{
    idx = size - 1;
    return constructTree(post, -1e9, 1e9);
}

int main()
{
    return 0;
}