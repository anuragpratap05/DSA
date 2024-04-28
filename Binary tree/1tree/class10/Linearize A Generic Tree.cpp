#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

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
Node *gettail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}
// Method1 O(n2):
Node *linearize(Node *node)
{
    for (Node *child : node->children)
    {
        linearize(child);
    }
    while (node->children.size() > 1)
    {
        Node *lc = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node *sec_last = node->children[node->children.size() - 1];
        Node *tail = gettail(sec_last);
        tail->children.push_back(lc);
    }
    return node;
}
// Method2 O(n):
Node *linearize2(Node *node)
{
    if (node->children.size() == 0)
    {
        return node;
    }
    Node *lkt = linearize(node->children[node->children.size() - 1]);
    while(node->children.size()>1)
    {
        Node *lc = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node *sec_last = node->children[node->children.size() - 1];
        Node* slkt=linearize(sec_last);
        slkt->children.push_back(lc);
    }
    return lkt;
}

int main()
{
    return 0;
}