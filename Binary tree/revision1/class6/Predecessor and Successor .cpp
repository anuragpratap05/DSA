#include <bits/stdc++.h>
using namespace std;

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

Node* leftmost(Node* root)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    while(root->left!=nullptr)
    {
        root = root->left;
    }
    return root;

}

Node *rightmost(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    Node* curr=root;
    while(curr!=nullptr)
    {
        if(curr->key==key)
        {
            suc=(curr->right!=nullptr?leftmost(curr->right):suc);
            pre=(curr->left!=nullptr?rightmost(curr->left):pre);
            break;

        }
        else if(curr->key<key)
        {
            pre=curr;
            curr=curr->right;
        }
        else
        {
            suc=curr;
            curr=curr->left;
        }
    }
}

int main()
{
    return 0;
}