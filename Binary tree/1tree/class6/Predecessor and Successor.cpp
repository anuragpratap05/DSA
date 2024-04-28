#include<bits/stdc++.h>
using namespace std;

// in binary tree
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
Node *giveit(Node *root, Node *c)
{
    while (root->right != nullptr and root->right != c)
    {
        root = root->right;
    }
    return root;
}

void morris_inorder(Node *root,Node *&pre, Node *&suc, int key)
{
    Node *c = root;
    Node* p=nullptr;
    while (c != nullptr)
    {
        Node *l = c->left;
        if (l == nullptr)
        {
            cout << c->data;
            if(c->data==key)
            {
                pre=p;
            }
            if (p != nullptr and p->data == key)
            {
                suc=c;
            }
            p=c;
            c = c->right;
        }
        else
        {
            Node *rmnode = giveit(l, c);
            if (rmnode->right == nullptr)
            {
                rmnode->right = c;
                c = c->left;
            }
            else
            {
                rmnode->right = nullptr;
                cout << c->data;
                if (c->data == key)
                {
                    pre = p;
                }
                if (p != nullptr and p->data == key)
                {
                    suc = c;
                }
                p = c;
                c = c->right;
            }
        }
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    
}

int main()
{
    return 0;
}