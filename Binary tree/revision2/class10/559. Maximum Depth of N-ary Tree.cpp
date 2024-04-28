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

int maxDepthHelp(Node *root)
{
    if (root->children.size() == 0)
        return 1;

    int myHt = 0;
    for (Node *node : root->children)
    {
        int recHt = maxDepthHelp(node);
        if (myHt < recHt + 1)
            myHt = recHt + 1;
    }
    return myHt;
}

int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    return maxDepthHelp(root);
}

int main()
{
    return 0;
}