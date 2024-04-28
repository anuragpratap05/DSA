#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node *> children;
    Node(int data)
    {

        this->data = data;
    }
};

Node *getTail(Node *node)
{
    while (node->children.size() > 0)
        node = node->children[0];
    return node;
}

Node *displayTree(Node *root)
{
    cout << root->data;
    for (Node *node : root->children)
        displayTree(node);
}

Node *linearize(Node *node)
{
    for (Node *child : node->children)
        linearize(child);
    while (node->children.size() > 1)
    {
        Node *lc = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node *slc = node->children[node->children.size() - 1];
        Node *slt = getTail(slc);
        slt->children.push_back(lc);
    }
    return node;
}

int main()
{
    return 0;
}