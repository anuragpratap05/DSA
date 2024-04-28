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

class nodeInfo
{
public:
    int maxHt = -1;
    int maxDia = 0;
};

nodeInfo maxDiameter(Node *root)
{
    if (root->children.size() == 0)
    {
        nodeInfo base;
        base.maxHt = 0;
        return base;
    }

    nodeInfo curNode;

    for (Node *node : root->children)
    {
        nodeInfo recAns = maxDiameter(node);

        curNode.maxDia = max(curNode.maxDia, max(recAns.maxDia, curNode.maxHt + 2 + recAns.maxHt));
        curNode.maxHt = max(curNode.maxHt, recAns.maxHt);
    }
    curNode.maxHt += 1;
    return curNode;
}

int diameter(Node *root)
{
    if (root == nullptr)
        return 0;
    return maxDiameter(root).maxDia;
}

int main()
{
    return 0;
}