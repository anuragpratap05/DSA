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

Node *get_tail(Node *root)
{
    while (root->children.size() > 0)
    {
        root = root->children[0];
    }
    return root;
}
// O(n^2)
Node *linearize_help(Node *node)
{

    for (int i = node->children.size() - 1; i >= 0; i--)
    {
        Node *tail = linearize_help(node->children[i]);
        if (i + 1 < node->children.size())
        {
            tail->children.push_back(node->children[i + 1]);
            node->children.erase(node->children.begin() + i + 1);
        }
    }
    return get_tail(node);
}

Node *linearize(Node *node)
{
    linearize_help(node);
    return node;
}

Node *linearize2_help(Node *node)
{
    if (node->children.size() == 0)
    {
        return node;
    }
    Node *lkt = linearize2_help(node->children[node->children.size() - 1]);
    for (int i = node->children.size() - 1; i >= 1; i--)
    {
        Node *lc = node->children[i];
        
        Node *slc = node->children[i-1];
        Node *slkt = linearize2_help(slc);
        slkt->children.push_back(lc);
        node->children.erase(node->children.begin() + i);

        // tail->children.push_back(node->children[i + 1]);
        // node->children.erase(node->children.begin() + i + 1);
    }
    return lkt;
}

Node *linearize2(Node *node)
{
    linearize2_help(node);
    return node;
}

int main()
{
    return 0;
}