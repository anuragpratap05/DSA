#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
Node *insert(Node *root, int Key)
{
    if (root == nullptr)
    {
        Node *x = new Node(Key);
        return x;
    }
    if (root->data < Key)
    {
        root->right = insert(root->right, Key);
    }
    else if (root->data > Key)
    {
        root->left = insert(root->left, Key);
    }
    return root;
}
int main()
{
    return 0;
}