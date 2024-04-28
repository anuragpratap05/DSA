#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val)
    {
        this->val = val;
    }
};

Node *rightMostNode(Node *root, Node *curr)
{
    while (root->right != nullptr and root->right != curr)
        root = root->right;

    return root;
}

// prev=left next=right
Node *morrisInorder(Node *root)
{
    Node *curr = root;

    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while (curr != nullptr)
    {
        Node *l = curr->left;
        if (l == nullptr)
        {
            // cout << curr->val << " ";
            curr->left = prev;
            prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr) // thread creation time
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else // thread destrot time
            {
                rmNode->right = nullptr;
                // cout << curr->val << " ";
                curr->left = prev;
                prev->right = curr;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    Node *hd = dummy->right;
    hd->left = prev;
    prev->right = hd;
    return hd;
}

Node *treeToCircularDoublyList(Node *root)
{
    if (root == nullptr)
        return nullptr;
    return morrisInorder(root);
}

int main()
{
    return 0;
}