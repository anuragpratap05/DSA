#include<bits/stdc++.h>
using namespace std;

// in BST
class Node
{
    public:
    int key = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key)
    {
    this->key = key;
    }
};

Node* rightmost(Node* root)
{
    if(root==nullptr)
    {
        return root;
    }
    while(root->right!=nullptr)
    {
        root=root->right;
    }
    return root;
}

Node *leftmost(Node *root)
{
    if (root == nullptr)
    {
        return root;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    Node* c=root;
    while(c!=nullptr)
    {
        if(c->key==key)
        {
            suc = (c->right == nullptr ? suc : leftmost(c->right));
            pre = (c->left == nullptr ? pre : rightmost(c->left));
            break;
        }
        else if(c->key>key)
        {
            suc=c;
            c=c->left;
        }
        else 
        {
            pre=c;
            c=c->right;
        }
    }
}

int main()
{
    return 0;
}