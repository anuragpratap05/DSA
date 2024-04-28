#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

Node *minNode(Node *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// w/o looking node->val
Node *inorderSuccessor2(Node *node)
{
    if (node == nullptr)
        return nullptr;
    Node *succ = nullptr, *curNode = node;

    if (curNode->right != nullptr)
        return minNode(curNode->right);

    while (curNode->parent != nullptr)
    {
        Node *par = curNode->parent;
        if(par->right==curNode)
            return par;
        curNode = par;
    }
    return succ;
}

Node *inorderSuccessor(Node *node)
{
    if(node==nullptr)
        return nullptr;
    Node *succ = nullptr, *curNode = node;

    if (curNode->right != nullptr)
        return minNode(curNode->right);

    while (curNode->parent != nullptr)
    {
        curNode = curNode->parent;
        if (curNode->val > node->val)
            return curNode;
    }
    return succ;
}

int main()
{
    return 0;
}