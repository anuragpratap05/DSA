#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

struct NodeInfo
{
    int dia = 0;
    int ht = -1;
};

NodeInfo diameterHelp(Node *root)
{
    if (root->children.size() == 0)
    {
        NodeInfo base;
        return base;
    }
    NodeInfo curNode;
    for (Node *child : root->children)
    {
        NodeInfo recAns = diameterHelp(child);
        curNode.dia = max(recAns.dia, max(curNode.dia, curNode.ht + recAns.ht + 2));
        curNode.ht = max(recAns.ht, recAns.ht);
    }
    curNode.ht += 1;
    return curNode;
}

int diameter(Node *root)
{
    return diameterHelp(root).dia;
}

int main()
{
    return 0;
}